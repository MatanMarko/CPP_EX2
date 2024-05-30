#322318080
#matanmarkovits@gmail.com

#!make -f

# CXX=g++
# CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
# VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
# OBJECTS=$(subst .cpp,.o,$(SOURCES))

# run: demo
# 	./$^

# demo: Demo.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o demo

# test: TestCounter.o Test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o test

# tidy:
# 	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# valgrind: demo test
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) --compile $< -o $@

# clean:
# 	rm -f *.o demo test



#running Makefile from EX1:

CC=g++
FLAGS=-std=c++11 -Werror -Wsign-conversion

CPPs=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(subst .cpp,.o,$(CPPs))

all: demo test

run: demo
	./$^

demo: Demo.o $(filter-out TestCounter.o Test.o, $(OBJECTS))
	$(CC) $(FLAGS) $^ -o demo

test: TestCounter.o Test.o $(filter-out Demo.o, $(OBJECTS))
	$(CC) $(FLAGS) $^ -o test

%.o: %.cpp
	$(CC) $(FLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
