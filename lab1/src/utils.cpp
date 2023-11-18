#include "utils.hpp"

void createPipe(int fd[2]) {
    if (pipe(fd) == -1) {
        perror("Couldn't create pipe");
        exit(EXIT_FAILURE);
    }
}

pid_t createChildProcess() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Couldn't create child");
        exit(EXIT_FAILURE);
    }
    return pid;
}

void reverseString(std::string string) {
    int length = string.size();
    for (size_t i = 0; i < length >> 1; ++i) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}

bool probability(int percentage) {
    assert(0 <= percentage && percentage <= 100);
    return (rand() % 100) < percentage;
}
