CC=g++
CFLAGS=-I.
DEPS = Node.h Single_LL.hpp 
OBJ = main.o Single_LL.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $> $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o run
