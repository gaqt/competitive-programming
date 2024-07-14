#!/bin/bash

red=$(tput setaf 1)
white=$(tput setaf 7)

if [ -f "problems/$1.cpp" ]; then
    echo -e "${red}File already exists${white}"
    exit 1
fi

cp template.cpp problems/
mv problems/template.cpp problems/$1.cpp
