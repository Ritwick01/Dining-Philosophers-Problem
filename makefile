all: p1 p2

p1: p1.c
	gcc p1.c -o p1 -lpthread -lrt 

p2: p2.c
	gcc p2.c -o p2 -lpthread -lrt

clean: 
	rm p1 p2