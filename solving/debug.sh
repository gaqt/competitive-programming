#!/bin/bash

red=$(tput setaf 1)
green=$(tput setaf 2)
cyan=$(tput setaf 6)
white=$(tput setaf 7)

echo -e "${cyan}<-- Compiling... -->${white}"
g++ -std=c++17 -D __DEBUG__ "problems/$1.cpp" -o problems/a.out

if [ $? -eq 0 ]; then
    echo -e "${green}<-- COMPILATION SUCCESSFUL -->${white}"
    echo -e "${cyan}<-- Running... -->${white}"
    echo ""
    problems/a.out < problems/in
    rm problems/a.out
else
    echo -e "${red}<-- COMPILATION FAILED -->${white}"
fi
