#!/bin/bash

red=$(tput setaf 1)
green=$(tput setaf 2)
cyan=$(tput setaf 6)
white=$(tput setaf 7)

echo -e "${cyan}<-- Compiling... -->${white}"
g++ -std=c++17 -D __DEBUG__ -ggdb "problems/$1.cpp" -o bins/$1.out

if [ $? -eq 0 ]; then
    echo -e "${green}<-- COMPILATION SUCCESSFUL -->${white}"
else
    echo -e "${red}<-- COMPILATION FAILED -->${white}"
fi
