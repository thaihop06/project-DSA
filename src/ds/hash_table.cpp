#include "ds/hash_table.hpp"

HashTable::HashTable(int size) : size(size) {
    table = new int[size];
    used  = new bool[size];
    for (int i = 0; i < size; i++) {
        used[i] = false;
    }
}

HashTable::~HashTable() {
    delete[] table;
    delete[] used;
}

int HashTable::hash(int id) const {
    return id % size;
}

void HashTable::insert(int id) {
    int index = hash(id);
    while (used[index]) {
        if (table[index] == id) return;
        index = (index + 1) % size;
    }
    table[index] = id;
    used[index] = true;
}

bool HashTable::contains(int id) const {
    int index = hash(id);
    while (used[index]) {
        if (table[index] == id) return true;
        index = (index + 1) % size;
    }
    return false;
}
