CXXFLAGS = -std=c++11

OBJECTS = Driver.o HashTable.o

hash-table:	$(OBJECTS)
	g++ $(CXXFLAGS) $(OBJECTS) -o $@

Driver.o:	Driver.cpp
HashTable.o:	HashTable.h HashTable.cpp

clean:
	rm -f *.o hash-table
