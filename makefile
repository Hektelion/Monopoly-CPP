####################################################
################ MAKEFILE PRINCIPAL ################
####################################################

#EXECUTION
CC = g++
LDFLAGS = 
CFLAGS = -W -Wall -I./include -I./include/interface
EXEC = mono_poly

#LISTE FICHIER INCLU
INCLUDE = $(wildcard include/*.hpp)

#LISTE FICHIER SOURCE
SRC = $(wildcard src/*.cpp)
INTERFACE_SRC = $(wildcard src/interface/*.cpp)

#LISTE FICHIER OBJET
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
INTERFACE_OBJ = $(patsubst src/interface/%.cpp, obj/interface/%.o, $(INTERFACE_SRC))

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ) $(INTERFACE_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) `sdl2-config --libs`

obj/%.o:src/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

obj/interface/%.o : src/interface/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) `sdl2-config --cflags`


####################################################

.PHONY	: clean mrproper

clean	:
	rm -f obj/*.o

mrproper: clean
	rm -rf $(EXEC)

print-%  : ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet D-mineur ##################################
####################################################