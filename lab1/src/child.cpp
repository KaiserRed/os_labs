#include "utils.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        perror("No input file.\n");
        exit(EXIT_FAILURE);
    }

    std::string filename(argv[1]);
    std::ofstream file(filename);
    std::string str;
    while (std::getline(std::cin, str)) {
        std::reverse(str.begin(), str.end());
        file << str << '\n';
    }

    file.close();
    exit(EXIT_SUCCESS);
}