cmake_minimum_required(VERSION 3.17)
project(smash)

set(CMAKE_CXX_STANDARD 14)

add_executable(smash commands.cpp signals.cpp smash.cpp
        commands.h signals.h Terminal_class.cpp Terminal_class.h Terminal_class.cpp Terminal_class.h Jobs.cpp Jobs.h SingleJob.cpp SingleJob.h)