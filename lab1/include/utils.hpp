#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <ext/stdio_filebuf.h>

void createPipe(int fd[2]);
pid_t createChildProcess();
bool probability(int percentage);
