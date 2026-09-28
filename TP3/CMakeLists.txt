cmake_minimum_required(VERSION 3.20)
project(vecteurexe VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(GNUInstallDirs)

option(VECTEUREXE_ENABLE_TIME "Enable time measurement" ON)

# vraiment inutile mais pour votre apprentissage
option(VECTEUREXE_RECURSIVE "Enable recursive mode" OFF) 

message(STATUS "PARAMETRAGE DE VECTEUREXE")
message(STATUS "VECTEUREXE_ENABLE_TIME = ${VECTEUREXE_ENABLE_TIME}")
message(STATUS "VECTEUREXE_RECURSIVE = ${VECTEUREXE_RECURSIVE}")

set(HEADERS
    "include/vecteur.hpp"
)

set(SOURCES # attention pas de main.c!
    "src/vecteur.cpp"
)

# on gere les options de compilation
if(VECTEUREXE_RECURSIVE)
    add_compile_definitions(VECTEUREXE_RECURSIVE)
endif()
if(VECTEUREXE_ENABLE_TIME)
    add_compile_definitions(ENABLE_TIME)
endif()

add_executable(vecteurexe "src/main.cpp" ${SOURCES})
target_include_directories(vecteurexe PUBLIC "include") # pour retrouver fibo

add_executable(up::vecteurexe ALIAS vecteurexe)

## parties des tests

enable_testing()

# on cherche la dépendance Google Test (gtest) pour les tests unitaires
find_package(GTest QUIET)
if (NOT GTest_FOUND)
    message(STATUS "Google Test not found, downloading...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    # Force le meme runtime CRT que le projet sous MSVC
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    message(STATUS "Google Test fetched with success.")
else()
    message(STATUS "Google Test found")
endif()

add_executable(vecteur_tests "tests/tests_vecteur.cpp" ${SOURCES})
target_include_directories(vecteur_tests PRIVATE include)
target_link_libraries(vecteur_tests PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(vecteur_tests)