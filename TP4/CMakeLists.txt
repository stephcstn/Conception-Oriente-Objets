cmake_minimum_required(VERSION 3.20)
project(TP4)

set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)


message(STATUS "PARAMETRAGE DE TP4")


set(HEADERS
    "include/cible.hpp"
    "include/commande.hpp"
    "include/parsing.hpp"
)

set(SOURCES # attention pas de main.c!
    "include/cible.cpp"
    "include/commande.cpp"
    "include/parsing.cpp"
)


add_executable(appexe "src/main.cpp" ${SOURCES})
target_include_directories(appexe PUBLIC "include") # pour retrouver fibo

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

add_executable(cible_tests "tests/test_cible.cpp" ${SOURCES})
target_include_directories(cible_tests PRIVATE include)
target_link_libraries(cible_tests PRIVATE GTest::gtest GTest::gtest_main)

add_executable(commande_tests "tests/test_commande.cpp" ${SOURCES})
target_include_directories(commande_tests PRIVATE include)
target_link_libraries(commande_tests PRIVATE GTest::gtest GTest::gtest_main)

add_executable(parsing_tests "tests/test_parsing.cpp" ${SOURCES})
target_include_directories(parsing_tests PRIVATE include)
target_link_libraries(parsing_tests PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cible_tests)
gtest_discover_tests(commande_tests)
gtest_discover_tests(parsing_tests)