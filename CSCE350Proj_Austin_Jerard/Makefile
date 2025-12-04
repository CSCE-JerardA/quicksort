CC = g++

CFLAGS = -std=c++17 -Wall

NAME_PREFIX = Austin_Jerard


SIZES = 10 100 1000 # Sizes of my files
FILES = 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 # Number of files

all: $(NAME_PREFIX)_QuickSort GenFile AvgTime

$(NAME_PREFIX)_QuickSort: Austin_Jerard_QuickSort.cc
		$(CC) $(CFLAGS) Austin_Jerard_QuickSort.cc -o $(NAME_PREFIX)_QuickSort

GenFile: InputFileGenerator.cc # Keyword to use after make
		$(CC) $(CFLAGS) InputFileGenerator.cc -o GenFile


AvgTime: TimeCalculator.cc
	$(CC) $(CFLAGS) TimeCalculator.cc -o $@

test: $(NAME_PREFIX)_QuickSort GenFile
	@echo "--- Creating all 75 Input Files ---"
	./GenFile


	@echo "--- Running QuickSort Tests ---"

	@for size in $(SIZES); do for i in $(FILES); do input_file="input_$$size""_$$i.txt"; sorted_file="sorted_$$size""_$$i.txt" time_file="time_$$size""_i.txt"; ./$(NAME_PREFIX)_QuickSort "$$input_file" "$$sorted_file" "$$time_file"; done; done;

	@echo "--- All 75 tests are complete! The data is store in  $(NAME_PREFIX)_executionTime.txt ---"





average: $(NAME_PREFIX)_QuickSort AvgTime
	@echo "--- Starting Average Time Calculation ---"
	./AvgTime

	@echo "--- Analysis complete. Results in $(NAME_PREFIX)_averageExecutionTime.txt ---"




clean:
		rm -f $(NAME_PREFIX)_QuickSort GenFile *.txt
