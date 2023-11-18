#include "parent.hpp"

int main() {
    parentRoutine(getenv("PATH_TO_CHILD"), std::cin);
    // bash: export PATH_TO_CHILD="/home/alexey/code/os_labs/lab1/build/child"
    exit(EXIT_SUCCESS);
}