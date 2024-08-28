CC=gcc
CFLAGS=-c -Wall
SOURCE=main.c
OBJ=$(SOURCE:.c=.o)
EXE=red_merchant

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ) utils.o trade_route.o ga.o
	$(CC) $(OBJ) utils.o trade_route.o ga.o -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXE)
