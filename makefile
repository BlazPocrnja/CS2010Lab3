CC = g++
OBJ = craps.o

craps: $(OBJ)
	$(CC) $(OBJ) -o $@


.cpp.o : 
	$(CC) -c $<


clean:
	rm *.o craps

archive:
	

