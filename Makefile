CC = gcc
CFLAGS = -Wall -Wextra -I./src
LDFLAGS = -lcrypto
SRC = sources/main.c sources/couche.c sources/neurone.c sources/reseau.c
OBJ = $(SRC:.c=.o)

all: lp25_borgbackup

reseauneurone: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ) reseauneurone
