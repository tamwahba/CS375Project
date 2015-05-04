# CS375Project
Final group project for CS375 - Algorithms - class
-------------
- Daniel D'alessandro
- Henry Dinhofer
- Tamer Wahba

-------------
This is project is aimed at testing hash table performance based on different 
hashing algorithms as well as input types. Data values are generated using a python script.

HashTable
-------------
###### public methods: -- Tamer
- `HashTable(METHOD m, int size)`
	- initializes hash table with size `size` and hashing algorithm `m`
- `void insert(int key, int value)`
	- inserts `value` into table based on `key`
- `int find(int key)`
	- returns value that corresponds to key, returns `<= -1` if not found
- `bool delete(int key)`
	- deletes value in table and returns `true`, returns `false` if key not found

###### private methods:
- `int hashKey(int key)` -- Dan
	- hashes `key` based on specified method and returns its location in the table
- `int perfectHashKey(int key)` -- Tamer
	- hashes `key` to find inner index for perfect hashing method
- `int linearHash(int key)` -- Dan
	- hashes `key` linearly
- `int quadraticHash(int key)` -- Henry
	- hashes `key` using quadratic hash method
- `int doubleHash(int key)` -- Tamer
	- hashes key using double hashing
- `int perfectHash(int key)` -- Tamer
	- hashes `key` using perfect hashing method

###### data members:
- `std::vector<int> openTable`
	- only in use for the open addressing methods
- `std::vector<std::vector>> perfectTable`
	- only in use for perfect hashing method
	
Input
------------------
```
11
INSERT 3
20 5
15 3
12 4
DELETE 1
15
FIND 2
20
12
INSERT 1
4 10
```
- The first line indicates the number of following lines in the file (for parsing simplicity)
- It must be directly followed by one of three commands: `INSERT`, `DELETE`, or `FIND`
	- The commands are followed by a number to indicate the number of operations
	- `FIND` and `DELETE` commands are composed of only the key to operate on
	- `INSERT` commands have the key followed by a space then a value. Both are numbers
- There can be any combination and repitition of the three commands
