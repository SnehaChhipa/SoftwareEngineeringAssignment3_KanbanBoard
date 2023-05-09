cmake_minimum_required(VERSION 3.21)
project(KanbanStyleBoard C)

set(CMAKE_C_STANDARD 99)

add_executable(KanbanStyleBoard main.c loadSaveDisplay.c sampleTestData.c edit.c types.h sampleTestData.h loadSaveDisplay.h edit.h)
