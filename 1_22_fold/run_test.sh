#! /bin/bash

EXERCISE_NUM=1_22
EXE=${EXERCISE_NUM}.out
BUILD_DIR=../build
INPUT=input.txt
OUTPUT=${BUILD_DIR}/${EXERCISE_NUM}_output.txt

${BUILD_DIR}/${EXE} $1 < ${INPUT} > ${OUTPUT} && vim ${OUTPUT} 
