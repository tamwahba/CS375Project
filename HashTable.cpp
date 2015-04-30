#include <stdio.h>
#include <stdlib.h>
#include <vector>

class HashTable {
public:
    HashTable();
    ~HashTable();
    void OpenHashTable(METHOD m, int size);
    void insert(int key, int value);
    int find(int key);
    bool delete(int key);

private:
	int hashKey(int key);
	int linearHash(int key);
	int quadraticHash(int key);
	int doubleHash(int key);
	int perfectHash(int key);

private:
	std::vector<int> openTable;
	std::vector<std::vector>> perfectTable;	
};

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

/*---------------PUBLIC METHODS---------------*/

/* Param: METHOD m, int Size
*  Desc: initializes hash table with size `size` and hashing algorithm `m`.
*  Returns: void
*/
void HashTable::OpenHashTable(METHOD m, int size){

}

/* Param: int key, int value
*  Desc: inserts `value` into table based on `key`
*  Returns: void
*/
void HashTable::insert(int key, int value){
	
}

/* Param: int key
*  Desc: finds the value that corresponds to the given key
*  Returns: returns the value or `-1` if not found
*/
int HashTable::find(int key){
	int pos = -1;
	//TODO: Find key, set pos
	return pos;
}

/* Param: int key
*  Desc: deletes the value in table that corresponds to the given key
*  Returns: returns `true` if deleted or `false` if key not found
*/
bool HashTable::delete(int key){
	bool found = false;
	//TODO: Delete key, set found to true
	return found;
}

/*---------------PRIVATE METHODS---------------*/

/* Param: int key
*  Desc: hashes `key` based on specified method
*  Returns: returns its location in the table
*/
int HashTable::hashKey(int key){
	int pos = 0;
	//TODO: hash key, set pos
	return pos;
}

/* Param: int key
*  Desc: hashes `key` linearly
*  Returns: returns its location in the table
*/
int HashTable::linearHash(int key){
	int retVal = -1;
	//TODO: hash key
	return retVal;
}

/* Param: int key
*  Desc: hashes `key` quadtratically
*  Returns: returns its location in the table
*/
int HashTable::quadtraticHash(int key){
	int retVal = -1;
	//TODO: hash key
	return retVal;
}

/* Param: int key
*  Desc: hashes `key` perfectly
*  Returns: returns its location in the table
*/
int HashTable::perfectHash(int key){
	int retVal = -1;
	//TODO: hash key
	return retVal;
}