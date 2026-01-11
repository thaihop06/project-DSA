#include <iostream>
#include <fstream>
#include <limits>

#include "app/menu.hpp"
#include "ds/bloom_filter.hpp"
#include "ds/hash_table.hpp"

void runMenu() {
    int m, k;
    int n = 0;

    std::cout << "===== BLOOM FILTER (FILE INPUT) =====\n";

    std::cout << "Nhap m (so bit): ";
    std::cin >> m;

    std::cout << "Nhap k (so ham bam): ";
    std::cin >> k;

    BloomFilter bf(m, k);

    std::ifstream in("data/input.txt");
    if (!in) {
        std::cout << "Khong mo duoc file data/input.txt\n";
        return;
    }

    // Dem so ID
    int id;
    while (in >> id) {
        n++;
    }
    in.clear();
    in.seekg(0);

    HashTable ht(n * 2);

    // Doc ID tu file
    while (in >> id) {
        bf.add(id);
        ht.insert(id);
    }
    in.close();

    // Test false positive
    int testCount = 1000;
    int falsePositive = 0;

    for (int i = 0; i < testCount; i++) {
        int testId = n * 10 + i;
        if (bf.possiblyContains(testId) && !ht.contains(testId)) {
            falsePositive++;
        }
    }

    double rate = static_cast<double>(falsePositive) / testCount;

    // Xuat file bao cao
    std::ofstream out("report.csv");
    out << "m,k,false_positive,rate\n";
    out << m << "," << k << "," << falsePositive << "," << rate << "\n";
    out.close();

    std::cout << "\n===== KET QUA =====\n";
    std::cout << "So ID doc tu file: " << n << "\n";
    std::cout << "False Positive   : " << falsePositive << "\n";
    std::cout << "Rate             : " << rate << "\n";
    std::cout << "Da xuat file     : report.csv\n";
    std::cout << "\nNhan Enter de thoat...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
