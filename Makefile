CC = gcc
CFLAGS = -Wall $(shell pkg-config --cflags libsodium)
LDFLAGS = $(shell pkg-config --libs libsodium)

TARGET = keygen

all: $(TARGET)

$(TARGET): keygen.c
	$(CC) $(CFLAGS) -o $(TARGET) keygen.c $(LDFLAGS)

clean:
	rm -f $(TARGET)

cleanall:
	rm -f $(TARGET) public.key private.key
