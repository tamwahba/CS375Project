#include <vector>
#include <ctime>
#include <cstdlib>

enum METHOD
{
	LINEAR = 1,
	QUADRATIC,
	DOUBLE,
	PERFECT
};

class HashTable {
public:
    HashTable();
    HashTable(METHOD m, int size);
    // ~HashTable();
    int getSize();
    void insert(int key, int value);
    int find(int key, int val);
    bool remove(int key, int val);

private:
	int hashKey(int key, int val);
	int perfectHashKey(int key, int val);
	int linearHash(int key, int val);
	int quadraticHash(int key, int val);
	int doubleHash(int key, int val);
	int perfectHash(int key);

private:
	std::vector<int> openTable;
	std::vector<std::vector<int>> perfectTable;
	std::vector<std::vector<bool>> perfectHashFunction;
	METHOD method;
	int size;
};
