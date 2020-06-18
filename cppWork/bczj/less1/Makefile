
export GG = g++ -W -Wall -fPIC -std=c++11
export BUILD_LIBS = -lpython2.7

millionSort:million_sort.o ccallp.o
	$(GG) $(BUILD_LIBS) million_sort.o ccallp.o -o millionSort
	rm *.o
.c.o:million_sort.cpp ccallp.cpp
	$(GG) $(BUILD_LIBS) -c $<
.PHONY:clean
clean:
	rm -rf millionSort

