#include <iostream>
#include <fstream>

#include "app/menu.hpp"
#include "ds/bloom_filter.hpp"
#include "ds/hash_table.hpp"

void runMenu() {
    int m, k;

    std::cout << "===== BLOOM FILTER =====\n";

    std::cout << "Nhap m (so bit): ";
    std::cin >> m;

    std::cout << "Nhap k (so ham bam): ";
    std::cin >> k;

    // Khoi tao Bloom Filter
    BloomFilter bf(m, k);

    // Mo file input
    std::ifstream in("input.txt");
    if (!in) {
        std::cout << "Khong mo duoc file input.txt\n";
        std::cout << "Dat input.txt cung cap voi file exe\n";
        std::cout << "Nhan Enter de thoat...";
        std::cin.ignore();
        std::cin.get();
        return;
    }

    // Dem so ID
    int id;
    int n = 0;
    while (in >> id) {
        n++;
    }

    in.clear();
    in.seekg(0);

    // Hash table luu du lieu that
    HashTable ht(n * 2);

    // Doc ID vao Bloom Filter + HashTable
    while (in >> id) {
        bf.add(id);
        ht.insert(id);
    }

    in.close();

    std::cout << "\nDa doc " << n << " ID tu file\n";

    // ===== TRUY VAN =====
    std::cout << "\n===== TRUY VAN ID =====\n";
    std::cout << "Nhap ID (-1 de thoat): ";

    int queryId;
    while (std::cin >> queryId && queryId != -1) {
        bool inBloom = bf.possiblyContains(queryId);
        bool inReal  = ht.contains(queryId);

        std::cout << "Bloom Filter : "
                  << (inBloom ? "Co the co" : "Khong co") << "\n";
        std::cout << "Thuc te      : "
                  << (inReal ? "Co" : "Khong co") << "\n";

        if (inBloom && !inReal) {
            std::cout << "=> FALSE POSITIVE\n";
        }

        std::cout << "\nNhap ID (-1 de thoat): ";
    }
    return;
}
