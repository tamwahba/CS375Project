#include "HashTable.h"

HashTable::HashTable()
	:method{LINEAR} {
		if (method == PERFECT)
			perfectTable = std::vector<std::vector<int>>(100);
		else
			openTable = std::vector<int>(100, -1); // initialize all values to -1
}

/* Param: METHOD m, int Size
*  Desc: initializes hash table with size `size` and hashing algorithm `m`.
*/
HashTable::HashTable(METHOD m, int size)
	:method{m} {
		if (method == PERFECT)
			perfectTable = std::vector<std::vector<int>>(size);
		else
			openTable = std::vector<int>(size, -1); // initialize all values to -1
}

HashTable::~HashTable()
{
}

/*---------------PUBLIC METHODS---------------*/


/* Param: int key, int value
*  Desc: inserts `value` into table based on `key`
*  Returns: void
*/
void HashTable::insert(int key, int value){
	if (method == PERFECT) {
		perfectTable[hashKey(key)][perfectHashKey(hashKey(key))] = value;
		return;
	}
	openTable[hashKey(key)] = value;
}

/* Param: int key
*  Desc: finds the value that corresponds to the given key
*  Returns: returns the value or `<-1` if not found
*/
int HashTable::find(int key){
	int pos = hashKey(key);
	int val = -1;
	if (method == PERFECT) {
		val = perfectTable[pos][perfectHashKey(pos)];
	} else {
		val = openTable[pos];
	}
	return val;
}

/* Param: int key
*  Desc: deletes the value in table that corresponds to the given key
*  Returns: returns `true` if deleted or `false` if key not found
*/
bool HashTable::remove(int key){
	int pos = hashKey(key);
	int val = -5;
	if (method == PERFECT) {
		val = perfectTable[pos][perfectHashKey(pos)];
		perfectTable[pos][perfectHashKey(pos)] = -2;
	} else {
		val = openTable[pos];
		openTable[pos] = -2;
	}
	return (val != -5);
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

int HashTable::perfectHashKey(int key){
	return -1;
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
int HashTable::quadraticHash(int key){
	int retVal = -1, pos=0, idx=0, interval=0; 
	// quadratic function 1 
	//  h(k), h(k)+2, h(k)+6...   
	int size = openTable.size(); // size = m number of slots
	interval = key % size;
	while (openTable[idx] > -1) {
		idx =(  (interval + pos + (pos*pos)) %size);
		pos++;	
	}
	return openTable[idx] > -1 ? idx : retVal;
}

/* Param: int key
*  Desc: hashes `key` using double hash method
*  Returns: returns its location in the table
*/
int HashTable::doubleHash(int key) {
	int m = openTable.size(); // FIX THIS BETTER
	int interval = 1 + (key % (m-1));
	int idx = key % m;
	// find empty spot. -1 if empty, -2 if deleted
	while (openTable[idx] > -1) {
		idx += interval;  // mod size (i.e. could go out of range, need to wrap around) to beginning
	}
	return idx;
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
