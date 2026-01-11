#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

class HashTable {
private:
    int size;
    int* table;
    bool* used;

    int hash(int id) const;

public:
    HashTable(int size);
    ~HashTable();

    void insert(int id);
    bool contains(int id) const;
};

#endif
