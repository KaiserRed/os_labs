#include "parent.hpp"

void parentRoutine(const char *pathToChild, std::istream &in){
    std::string filename1, filename2;
    std::getline(in, filename1);
    std::getline(in, filename2);

    int fd1[2], fd2[2];
    createPipe(fd1);

    int pid1 = createChildProcess();
    if (pid1 > 0) {
        close(fd1[0]);

        createPipe(fd2);

        int pid2 = createChildProcess();

        if (pid2 > 0) {
            close(fd1[0]);
            close(fd2[0]);

            std::string line;
            while (getline(std::cin, line)) {
                line += '\n';
                if (probability(80)) {
                    write(fd2[1], line.c_str(), line.length());
                } else {
                    write(fd1[1], line.c_str(), line.length());
                }
            }
            close(fd1[1]);
            close(fd2[1]);

        } else {
            close(fd2[1]);
            if (dup2(fd2[0], STDIN_FILENO) == -1) {
                perror("dup2 error");
                exit(EXIT_FAILURE);
            }

            close(fd2[0]);
            if (execlp(pathToChild, pathToChild, filename2.c_str(), nullptr) == -1){
                perror("Error with execlp");
                exit(EXIT_FAILURE);
            }
        }
    } else {
        close(fd1[1]);
        if (dup2(fd1[0], STDIN_FILENO) == -1) {
                perror("dup2 error");
                exit(EXIT_FAILURE);
            }

            close(fd1[0]);
            if (execlp(pathToChild, pathToChild, filename1.c_str(), nullptr) == -1){
                perror("Error with execlp");
                exit(EXIT_FAILURE);
            }
    }
}

