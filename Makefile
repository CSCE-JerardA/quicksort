CC = g++

CFLAGS = -std=c++17 -Wall

NAME_PREFIX = Austin_Jerard

SIZES = 10 100 1000
FILES = 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

all: $(NAME_PREFIX)_QuickSort GenFile

$(NAME_PREFIX)_QuickSort: Austin_Jerard_QuickSort.cc
		$(CC) $(CFLAGS) Austin_Jerard_QuickSort.cc -o $(NAME_PREFIX)_QuickSort

GenFile: InputFileGenerator.cc
		$(CC) $(CFLAGS) InputFileGenerator.cc -o GenFile

test: $(NAME_PREFIX)_QuickSort GenFile

		@echo "--- Creating all 75 Input Files ---"
		./GenFile

		@echo "--- Running QuickSort Tests ---"

		@for size in $(SIZES); do \ 
