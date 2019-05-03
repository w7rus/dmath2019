G++ = g++
G++FLAGS = -c -Wall -Werror
VPATH = src:build
PATH_IN = ./src/
PATH_BUILD = ./build/
PATH_OUT = ./bin/
dmath2019_main = main
dmath2019_functions = functions
dmath2019_conmenu = conmenu

all: app clean

app: $(dmath2019_main).o $(dmath2019_functions).o $(dmath2019_conmenu).o
	$(G++) $(PATH_BUILD)$(dmath2019_main).o $(PATH_BUILD)$(dmath2019_functions).o $(PATH_BUILD)$(dmath2019_conmenu).o -o $(PATH_OUT)dmath2019_run

$(dmath2019_main).o: $(dmath2019_main).cpp
	$(G++) $(G++FLAGS) $(PATH_IN)$(dmath2019_main).cpp -o $(PATH_BUILD)$(dmath2019_main).o

$(dmath2019_functions).o: $(dmath2019_functions).cpp
	$(G++) $(G++FLAGS) $(PATH_IN)$(dmath2019_functions).cpp -o $(PATH_BUILD)$(dmath2019_functions).o

$(dmath2019_conmenu).o: $(dmath2019_conmenu).cpp
	$(G++) $(G++FLAGS) $(PATH_IN)$(dmath2019_conmenu).cpp -o $(PATH_BUILD)$(dmath2019_conmenu).o

ifeq ($(OS),Windows_NT)
clean:
	del /S *.o
else
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
clean:
	find . -name \*.o -type f -exec rm -f {} \;
endif
endif