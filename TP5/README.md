g++ -std=c++17 -Wall -Wextra \*.cpp -o mon_programme
g++ -std=c++17 -Wall -Wextra test_vecteur.cpp -lgtest -lgtest_main -pthread -o run_tests
./run_tests
g++ -std=c++17 -Wall -Wextra main.cpp -o mon_programme
