# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11

# Linker flags
LDFLAGS = -lncurses

# Target executable
TARGET = anitype

# Source files
SRCS = src/main.cpp src/ncurses_helper.cpp src/wordlist_helper.cpp
# Object files
OBJS = $(SRCS:src/%.cpp=build/Debug/%.o)

# Include directories
INC_DIRS = -I./include

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile source files
build/Debug/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Create necessary directories
$(shell mkdir -p build/Debug)

# Clean rule
clean:
	rm -rf build $(TARGET)
