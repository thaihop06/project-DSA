#include "ds/bloom_filter.hpp"

BloomFilter::BloomFilter(int m, int k) : m(m), k(k) {
    bits = new bool[m];
    for (int i = 0; i < m; i++) {
        bits[i] = false;
    }
}

BloomFilter::~BloomFilter() {
    delete[] bits;
}

int BloomFilter::hash1(int id) const {
    return id % m;
}

int BloomFilter::hash2(int id) const {
    return (id / 7 + 1) % m;
}

void BloomFilter::add(int id) {
    for (int i = 0; i < k; i++) {
        int index = (hash1(id) + i * hash2(id)) % m;
        bits[index] = true;
    }
}

bool BloomFilter::possiblyContains(int id) const {
    for (int i = 0; i < k; i++) {
        int index = (hash1(id) + i * hash2(id)) % m;
        if (!bits[index]) {
            return false;
        }
    }
    return true;
}
