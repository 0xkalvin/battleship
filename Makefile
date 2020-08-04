.PHONY: build run all clean

default: all

COMPILER=g++
PATTERN=*.cpp
BINARY=battleship

build:
	${COMPILER} ${PATTERN} -o ${BINARY}

run:
	./${BINARY}

all: build run

clean:
	rm ${BINARY}