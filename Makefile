CC := clang
FLAGS := -g -fsanitize=address -o

main: paranoia.o player_list.o
	$(CC) $(FLAGS) paranoia paranoia.o player_list.o

paranoia.o: paranoia.c player_list.h
	$(CC) -c paranoia.c

list.o: player_list.c player_list.h
	$(CC) -c player_list.c

clean: 
	rm paranoia paranoia.o player_list.o
