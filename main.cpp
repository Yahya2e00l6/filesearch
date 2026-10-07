#include <iostream>
#include "search2m.h"
#include <chrono>

int main() {
    File2mSearcher searcher;
    auto start = std::chrono::high_resolution_clock::now();
    if (searcher.loadFromFile("large_2mots.txt")) {
        std::cout << "Successfully loaded " << searcher.size()<< " words!" << std::endl;
        int count = 0;
        searcher.replaceAllInList("ai" , "sk");
        searcher.saveToFile("large_2mots.txt");
    } else {
        std::cout << "Note: large_2mots.txt not found in current directory." << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    double micros = nanos / 1000.0;
    double millis = nanos / 1000000.0;
    std::cout << "time: " << nanos << " ns (" << micros << " us, " << millis << " ms)\n";

    return 0;
}
