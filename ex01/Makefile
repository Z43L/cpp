# Variables
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
LDFLAGS =

# Fuentes y objetivos
SOURCES = main.cpp contact.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = megaphone

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