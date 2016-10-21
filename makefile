GCC = gcc -g

run: all
	./test

all: songNodes.o songLibrary.o main.o
	$(GCC) songNodes.o songLibrary.o main.o -o test

link_list.o: songNodes.c
	$(GCC) -c songNodes.c

main.o: main.c
	$(GCC) -c main.c

music_library.o: songLibrary.c
	$(GCC) -c songLibrary.c

clean:
	make -i cleanH

cleanH:
	rm *~
	rm *.o