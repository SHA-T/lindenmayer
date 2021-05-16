#########################################
# Makefile
#########################################

CXX = g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g -Og \
	-Winit-self -Wold-style-cast -Wcast-qual -Wundef \
	-Woverloaded-virtual \
	-Wconversion \
	-Wlogical-op \
	-Wzero-as-null-pointer-constant \
	-fsanitize=address \
	-fsanitize=undefined \
	-fsanitize=float-cast-overflow

LINK_FLAGS := -fsanitize=address \
	-fsanitize=undefined \
	-fsanitize=float-cast-overflow

EXEC	:= lindenmayer
SRCS	:= $(wildcard src/*.cpp)
HDRS	:= $(wildcard src/*.h)
OBJS	:= $(patsubst src/%.cpp, obj/%.o, $(SRCS))
DEPS	:= $(patsubst %.o, %.d, $(OBJS))

# Default target
$(EXEC)	:

# Create all
all	: $(EXEC)

# Include existing dependancies
-include $(DEPS)

# Create dependancy files
.SUFFIXES += .d
obj/%.d: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MM -MT '$(patsubst src/%.cpp,obj/%.o,$<)' $< -MF $@

# Compilation
obj/%.o: src/%.cpp obj/%.d
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link all object files to executable
$(EXEC)	: $(OBJS)
	$(CXX) $(OBJS) $(LINK_FLAGS) -lstdc++fs -o $@

# Documentation
doc	: $(SRCS) $(HDRS)
	doxygen

# Clean up directory
clean	: 
	rm -f $(EXEC) 
	rm -rf obj
	rm -rf doc
	rm -rf results


