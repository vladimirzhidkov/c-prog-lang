#! /bin/bash

EXERCISE_NUM=1_08
EXE=${EXERCISE_NUM}.out
BUILD_DIR=../build
INPUT=input.txt
OUTPUT=${BUILD_DIR}/${EXERCISE_NUM}_output.txt

${BUILD_DIR}/${EXE} < ${INPUT}
