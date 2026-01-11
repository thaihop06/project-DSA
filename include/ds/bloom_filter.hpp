#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

class BloomFilter {
private:
    int m;      // so bit
    int k;      // so ham bam
    bool* bits; // bit array

    int hash1(int id) const;
    int hash2(int id) const;

public:
    BloomFilter(int m, int k);
    ~BloomFilter();

    void add(int id);
    bool possiblyContains(int id) const;
};

#endif
