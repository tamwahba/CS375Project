#include "HashTable.h"

HashTable::HashTable()
	:method{LINEAR},
	size{0} {
		srand(time(0));
		if (method == PERFECT) {
			perfectTable = std::vector<std::vector<int>>(100, std::vector<int>(100, -1));
			perfectHashFunction = std::vector<std::vector<bool>>(12, std::vector<bool>(16));
		}
		else {
			openTable = std::vector<int>(100, -1); // initialize all values to -1
		}
}

/* Param: METHOD m, int Size
*  Desc: initializes hash table with size `size` and hashing algorithm `m`.
*/
HashTable::HashTable(METHOD m, int size)
	:method{m},
	size{0} {
		if (method == PERFECT) {
			srand(time(0));
			perfectTable = std::vector<std::vector<int>>(size, std::vector<int>(size, -1));
			perfectHashFunction = std::vector<std::vector<bool>>(12, std::vector<bool>(16));
			for (int i = 0; i < perfectHashFunction.size(); i++) {
				for (int j = 0; j < perfectHashFunction[i].size(); j++) {
					perfectHashFunction[i][j] = rand() % 2;
				}
			}
		}
		else {
			openTable = std::vector<int>(size, -1); // initialize all values to -1
		}
}

// HashTable::~HashTable()
// {
// }

/*---------------PUBLIC METHODS---------------*/


/* Param: int key, int value
*  Desc: inserts `value` into table based on `key`
*  Returns: void
*/
void HashTable::insert(int key, int value){
	if (method == PERFECT) {
		int perf = hashKey(key, value);
		int perfperf = perfectHashKey(perf, value);
		perfectTable[perf][perfperf] = value;
		return;
	} else {
		if (size == openTable.size() || hashKey(key, value) == -1)
			return;
		openTable[hashKey(key, value)] = value;
	}
	size++;
}

/* Param: int key
*  Desc: finds the value that corresponds to the given key
*  Returns: returns the value or `<-1` if not found
*/
int HashTable::find(int key, int val){
	int pos = hashKey(key, val);
	int value = -1;
	if (method == PERFECT) {
		value = perfectTable[pos][perfectHashKey(pos, val)];
	} else {
		value = openTable[pos];
	}
	return value;
}

/* Param: int key
*  Desc: deletes the value in table that corresponds to the given key
*  Returns: returns `true` if deleted or `false` if key not found
*/
bool HashTable::remove(int key, int val){
	int pos = hashKey(key, val);
	int value = -5;
	if (method == PERFECT) {
		value = perfectTable[pos][perfectHashKey(pos, val)];
		perfectTable[pos][perfectHashKey(pos, val)] = -2;
	} else {
		value = openTable[pos];
		openTable[pos] = -2;
	}
	bool removed = (value != -5);
	if (removed)
		size--;
	return removed;
}

/*---------------PRIVATE METHODS---------------*/

/* Param: int key
*  Desc: hashes `key` based on specified method
*  Returns: returns its location in the table
*/
int HashTable::hashKey(int key, int val){
	int idx = -1;
	//TODO: hash key, set idx
	if(method == LINEAR){
		idx = linearHash(key, val);
	}else if(method == QUADRATIC){
		idx = quadraticHash(key, val);
	}else if(method == DOUBLE){
		idx = doubleHash(key, val);
	}else if(method == PERFECT){
		idx = perfectHash(key);
	}
	return idx;
}

int HashTable::perfectHashKey(int key, int val){
	int m = perfectTable[key].size(); // FIX THIS BETTER
	int interval = 1 + (key % (m-1));
	int idx = key % m;
	// find empty spot. -1 if empty, -2 if deleted
	while (perfectTable[key][idx] > -1 && val != perfectTable[key][idx]) {
		idx += interval;  // mod size (i.e. could go out of range, need to wrap around) to beginning
		idx %= m; 
	}
	return idx;
}


/* Param: int key
*  Desc: hashes `key` linearly
*  Returns: returns its location in the table
*/
int HashTable::linearHash(int key, int val){
	int retVal=-1, pos=0;
	int size = openTable.size();
	int idx = key % size;
	//TODO: hash key
	while (openTable[idx] > -1 && val != openTable[idx]){
		idx = (idx + 1) % size;
	}
	return idx;
}

/* Param: int key
*  Desc: hashes `key` quadtratically
*  Returns: returns its location in the table
*/
int HashTable::quadraticHash(int key, int val){
	int retVal = 0, pos=0, idx=0, interval=0; 
	// quadratic function 1 
	//  h(k), h(k)+2, h(k)+6...   
	int size = openTable.size(); // size = m number of slots
	interval = key % size;
	while (openTable[idx] > -1 && val != openTable[idx]) {
		idx = ((interval + (pos*pos)) % size);
		pos++;
		if (pos == size)
			return -1;
	}
	return idx;
}

/* Param: int key
*  Desc: hashes `key` using double hash method
*  Returns: returns its location in the table
*/
int HashTable::doubleHash(int key, int val) {
	int m = openTable.size(); // FIX THIS BETTER
	int interval = 1 + (key % (m-1));
	int idx = key % m;
	// find empty spot. -1 if empty, -2 if deleted
	while (openTable[idx] > -1 && val != openTable[idx]) {
		idx += interval;  // mod size (i.e. could go out of range, need to wrap around) to beginning
		idx %= m;
	}
	return idx;
}


/* Param: int key
*  Desc: hashes `key` perfectly
*  Returns: returns its location in the table
*/
int HashTable::perfectHash(int key){
	int hashval = 0;
	for (int i = 0; i < 10; i++) {
		int sum = 0;
		if ((key >> i) & 1) {
			for (int j = 0; j < perfectHashFunction[i].size(); j++) {
				sum += perfectHashFunction[i][j];
			}
		}
		hashval = (hashval | (sum % 2)) << 1;
	}
	return hashval;
}
