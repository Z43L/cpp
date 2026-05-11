# Variables
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g3
LDFLAGS =

# Fuentes y objetivos
SOURCES =  main.cpp Animal.cpp cat.cpp dog.cpp brain.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = animal

# Reglas
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

re: fclean all

fclean: clean
	rm -f $(EXECUTABLE)
	
run: all
	./$(EXECUTABLE)
