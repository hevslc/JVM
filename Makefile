CXX = g++
CXXFLAGS = -W -Wall -std=c++11 -lm -g -I$(IDIR)

SDIR = src
IDIR = include
ODIR = obj

NAME = main

DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(patsubst %.cpp,%.o,$(wildcard $(SDIR)/*.cpp))
OBJ = $(patsubst $(SDIR)/%,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(NAME)