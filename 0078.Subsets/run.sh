# CXX_FLAG="-std=c++17 -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined"
# g++ ${CXX_FLAG} main.cpp -o main -I ..; ./main; rm main

# g++ -std=c++17 -Wall -Wextra -fsanitize=address -fsanitize=undefined main.cpp -o main -I ..; ./main; rm main

g++ -std=c++17 -Wall -Wextra main.cpp -o main -I ..; ./main; rm main
