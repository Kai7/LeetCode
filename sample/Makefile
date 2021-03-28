CXX_FLAG = -std=c++17
CXX_FLAG += -Wall -Wextra -Werror
CXX_FLAG += -fsanitize=address -fsanitize=undefined
INCLUDE  = ..
SAMPLE   = sample_create_AVLTree

all: $(SAMPLE)

sample_create_AVLTree:
	g++ $(CXX_FLAG) -I $(INCLUDE) $@.cpp -o $@

clean:
	rm $(SAMPLE)
