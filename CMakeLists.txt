cmake_minimum_required(VERSION 3.10)

project(StateMachinePattern VERSION 1.0 LANGUAGES CXX DESCRIPTION "A simple example  of a Task Queue Design Pattern by Vladimir Petukhov in modern C++")

set(CMAKE_CONFIGURATION_TYPES "Release")

add_executable(TaskQueuePattern TaskQueuePattern.cpp TaskQueuePattern.h main.cpp)
