set(CMAKE_CXX_STANDARD 17)

add_executable(main include/utils.hpp
        main.cpp
        src/parent.cpp
        src/utils.cpp)

add_executable(child include/utils.hpp
        src/child.cpp
        src/utils.cpp)

target_include_directories(main PRIVATE include)
target_include_directories(child PRIVATE include)

#add_dependencies(lab1 child)