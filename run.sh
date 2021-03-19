CXX_FLAG="-std=c++17 -Wall -Wextra -Werror -fsanitize=address"
g++ ${CXX_FLAG} main.cpp -o main -I ..; ./main; rm main

g++ -std=c++17 -Wall -Wextra -fsanitize=address main.cpp -o main -I ..; ./main; rm main
