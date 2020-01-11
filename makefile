####################################################
################ MAKEFILE PRINCIPAL ################
####################################################

#EXECUTION
CC = g++
LDFLAGS = 
CFLAGS = -W -Wall -I./include -I./include/interface
EXEC = monopoly
EXEC_TEST_CONSOLE = monopoly_test_console

#LISTE FICHIER INCLU
INCLUDE = $(wildcard include/*.hpp)

#LISTE FICHIER SOURCE
SRC = $(wildcard src/class_*.cpp)
INTERFACE_SRC = $(wildcard src/interface/*.cpp)

#LISTE FICHIER OBJET
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
INTERFACE_OBJ = $(patsubst src/interface/%.cpp, obj/interface/%.o, $(INTERFACE_SRC))

####################################################

all	: $(EXEC) $(EXEC_TEST_CONSOLE)
	@echo "DONE"

$(EXEC)	: $(OBJ) ./obj/main.o $(INTERFACE_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) `sdl2-config --libs`

$(EXEC_TEST_CONSOLE) : $(OBJ) ./obj/main_console.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

obj/main_console.o : src/main_console.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

obj/main.o : src/main.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

obj/%.o:src/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

obj/interface/%.o : src/interface/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) `sdl2-config --cflags`


####################################################

.PHONY	: clean mrproper

clean	: 
	rm -f obj/*.o
	rm -f obj/interface/*.o

mrproper: clean
	rm -rf $(EXEC) $(EXEC_TEST_CONSOLE)

print-%  : ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet D-mineur ##################################
####################################################
