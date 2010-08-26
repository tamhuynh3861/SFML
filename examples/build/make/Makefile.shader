EXE     = shader
SRC     = $(wildcard $(SRCROOT)/$(EXE)/*.cpp)
OBJ     = $(SRC:.cpp=.o)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) -o $(SRCROOT)/$(EXE)/$(EXE) $(OBJ) $(LDFLAGS)

$(OBJ): %.o: %.cpp
	$(CPP) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(SRCROOT)/$(EXE)/$(EXE)