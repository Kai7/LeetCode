CXX_FLAG="-std=c++17 -Wall -Wextra -Werror"
g++ ${CXX_FLAG} main.cpp -o main -I ..; ./main; rm main

g++ -std=c++17 -Wall -Wextra main.cpp -o main -I ..; ./main; rm main
