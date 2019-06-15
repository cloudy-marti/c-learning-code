### Makefile of hash Project ###

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
OBJ=$(OBJPATH)simple_list.o $(OBJPATH)simple_list_manager.o
hOBJ=$(OBJPATH)hash.o $(OBJPATH)hash_manager.o $(OBJPATH)simple_list_manager.o
OBJPATH=obj/
SRCPATH=src/

all :
	@echo "--------------------------------------------------------------"
	@echo "          to compile type one of the following :"
	@echo "		      make hash"
	@echo "		      make list"
	@echo "--------------------------------------------------------------"

hash: dir $(hOBJ)
	$(CC) -o bin/hash $(hOBJ)
	@echo "--------------------------------------------------------------"
	@echo "               Hash Table - C Programming"
	@echo "                      Emilie Marti"
	@echo ""
	@echo "       		    to execute type :"
	@echo ""
	@echo "             ./bin/hash data/path_to_file"
	@echo "--------------------------------------------------------------"

list: dir $(OBJ)	
	$(CC) -o bin/list $(OBJ)
	@echo "--------------------------------------------------------------"
	@echo "               Simple List - C Programming"
	@echo "                      Emilie Marti"
	@echo ""
	@echo "       		    to execute type :"
	@echo ""
	@echo "             ./bin/list data/path_to_file"
	@echo "--------------------------------------------------------------"

dir:
	mkdir -p bin obj

$(OBJPATH)simple_list.o: $(SRCPATH)simple_list.c
	$(CC) -c $(SRCPATH)simple_list.c -o $(OBJPATH)simple_list.o $(CFLAGS)

$(OBJPATH)simple_list_manager.o: $(SRCPATH)simple_list_manager.c
	$(CC) -c $(SRCPATH)simple_list_manager.c -o $(OBJPATH)simple_list_manager.o $(CFLAGS)

$(OBJPATH)hash.o: $(SRCPATH)hash.c
	$(CC) -c $(SRCPATH)hash.c -o $(OBJPATH)hash.o $(CFLAGS)

$(OBJPATH)hash_manager.o: $(SRCPATH)hash_manager.c
	$(CC) -c $(SRCPATH)hash_manager.c -o $(OBJPATH)hash_manager.o $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(hOBJ)
	rm -f bin/hash
	rm -f bin/list
