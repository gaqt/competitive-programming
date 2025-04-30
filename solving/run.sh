#!/bin/bash

red=$(tput setaf 1)
green=$(tput setaf 2)
cyan=$(tput setaf 6)
white=$(tput setaf 7)

echo -e "${cyan}<-- Running... -->${white}"
echo ""
bins/$1.out < problems/in
