#== Stephanie Briere Americo GRR20165313 ==
#== Talita Halboth Cunha Fernandes GRR20165399 ==
CFLAGS = -Wall -O3
busca: main.o AVL_tree.o
	gcc -o busca *.o $(CFLAGS) 

main.o: main.c 
	gcc -c main.c $(CFLAGS) 

AVL_tree.o: AVL_tree.h AVL_tree.o
	gcc -c AVL_tree.c $(CFLAGS) 
