CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/main.o ./obj/maze.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


# ./obj/DLS.o ./obj/solution.o

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
./obj/maze.o: ./cpp/maze.cpp
	$(CXX) $(CXXFLAGS) ./cpp/maze.cpp -o ./obj/maze.o
# ./obj/DLS.o: ./cpp/DLS.cpp
# 	$(CXX) $(CXXFLAGS) ./cpp/DLS.cpp -o ./obj/DLS.o
# ./obj/solution.o: ./cpp/solution.cpp
# 	$(CXX) $(CXXFLAGS) ./cpp/solution.cpp -o ./obj/solution.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
