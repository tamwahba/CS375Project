#include <vector>

enum METHOD
{
	LINEAR = 0,
	QUADRATIC,
	DOUBLE,
	PERFECT
};

class HashTable {
public:
    HashTable();
    HashTable(METHOD m, int size);
    ~HashTable();
    void insert(int key, int value);
    int find(int key);
    bool remove(int key);

private:
	int hashKey(int key);
	int perfectHashKey(int key);
	int linearHash(int key);
	int quadraticHash(int key);
	int doubleHash(int key);
	int perfectHash(int key);

private:
	std::vector<int> openTable;
	std::vector<std::vector<int>> perfectTable;
	METHOD method;
};