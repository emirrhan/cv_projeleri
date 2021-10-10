# If you want to use this on your own machine, change CLASSDIR and/or INCLUDE and LIBS so
# that they point to the correct directories/library.

INCLUDE = -I ./ 
LIBS = ./libfdr/libfdr.a
CC = gcc

CC = gcc
EX =kripto

run:  clean  $(EX) sifre

clean: 
	rm -f $(EX) *.o
	
cleanall:
	rm -f $(EX) *.o *.txt encripted decripted ornek_metin .kilit

kripto:main.c 
	$(CC) $(INCLUDE) -o kripto main.c $(LIBS)

sifre:        
		./$(EX) -e ornek_metin encripted
		./$(EX) -d encripted decripted
	
.SUFFIXES:  .c  .o
.c .o:
	$(CC)  -g  $(INCLUDE)    -c      $*.c