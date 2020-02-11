#include <iostream>

// This finds out the number of arguments during run and the prints out the arguments
//
// https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean

int main(int argc, char** argv) {
    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
}
