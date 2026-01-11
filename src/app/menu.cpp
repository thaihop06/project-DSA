#include <iostream>
#include <fstream>

#include "app/menu.hpp"
#include "ds/bloom_filter.hpp"
#include "ds/hash_table.hpp"

void runMenu() {
    int m, k;
    int choice;

    std::cout << "===== BLOOM FILTER =====\n";
    std::cout << "Nhap m (so bit): ";
    std::cin >> m;
    std::cout << "Nhap k (so ham bam): ";
    std::cin >> k;

    BloomFilter bf(m, k);

    std::cout << "\n1. Doc ID tu file\n";
    std::cout << "2. Nhap ID bang tay\n";
    std::cout << "Chon che do: ";
    std::cin >> choice;

    int id;
    int n = 0;

    HashTable ht(2000); // du dung cho ca 2 che do

    // ===== CHE DO 1: DOC FILE =====
    if (choice == 1) {
        std::ifstream in("input.txt");
        if (!in) {
            std::cout << "Khong mo duoc file input.txt\n";
            return;
        }

        while (in >> id) {
            bf.add(id);
            ht.insert(id);
            n++;
        }
        in.close();

        std::cout << "Da doc " << n << " ID tu file\n";
    }

    // ===== CHE DO 2: NHAP TAY =====
    else if (choice == 2) {
        std::cout << "Nhap cac ID (nhap -1 de ket thuc):\n";

        while (true) {
            std::cin >> id;
            if (id == -1) break;

            bf.add(id);
            ht.insert(id);
            n++;
        }

        std::cout << "Da nhap " << n << " ID bang tay\n";
    }

    else {
        std::cout << "Lua chon khong hop le\n";
        return;
    }

    // ===== TRUY VAN =====
    std::cout << "\n===== TRUY VAN ID =====\n";
    std::cout << "Nhap ID can kiem tra (-1 de thoat): ";

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

        std::cout << "\nNhap ID can kiem tra (-1 de thoat): ";
    }
    return;
}
