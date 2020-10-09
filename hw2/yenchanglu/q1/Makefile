CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

EXEC = Line
OBJ = Line.o
CHECKFILE = result.txt

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: run
run: $(EXEC)
	./$(EXEC)

.PHONY: check
check: $(EXEC)
	./$(EXEC) > $(CHECKFILE)

.PHONY: clean
clean:
	$(RM) *.o $(EXEC) $(CHECKFILE)
