# Define the compiler and flags
CXX = g++-13
CXXFLAGS = -std=c++20 -fdiagnostics-color=always -g -I./include -pthread -O2

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Create the necessary directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# Output executable
TARGET = $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
