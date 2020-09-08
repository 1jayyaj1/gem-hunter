#!/bin/bash

include_files="../global.c"
include_include="-I../"
include_flag="-std=c99 -fopenmp -lm -lstdc++ -march=native"

(set -x && gcc -O3 -o "group" \
    main.c \
    ${include_files} \
    ${include_include} \
    ${include_flag}
)

