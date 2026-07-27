/*
Write a program that accepts the options presented in this section.
Print the values passed to main.
*/

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i != argc; ++i)
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    return 0;
}
