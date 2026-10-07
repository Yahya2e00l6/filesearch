#include <fstream>
#include "search2m.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

std::string File2mSearcher::toLowerCopy(const std::string& s) {
    std::string out = s;
    for (size_t i = 0; i < out.size(); ++i) {
        if (out[i] >= 'A' && out[i] <= 'Z') {
            out[i] = static_cast<char>(out[i] + ('a' - 'A'));
        }
    }
    return out;
}

bool File2mSearcher::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    words.clear();
    std::string w;
    while (file >> w) {
        words.push_back(w);
    }
    return true;
}

bool File2mSearcher::isthere(const std::string& word , const std::string& pattern) const {
    if (word.empty()) {
        return false;
    }
    int start_idx = 0;
    for (char c : pattern) {
        start_idx = word.find(c , start_idx);
        if(start_idx == -1){
            return false;
        }
        start_idx += 1;
    }
    return true;
}

std::string File2mSearcher::replaceInWord(std::string word, const std::string& pattern, const std::string& replacement) const {
    std::vector<size_t> indices;
    size_t start_idx = 0;
    for (char c : pattern) {
        start_idx = word.find(c, start_idx);
        if (start_idx == -1) {
            return word;
        }
        indices.push_back(start_idx);
        start_idx += 1;
    }
    for (size_t i = 0; i < indices.size() && i < replacement.size(); ++i) {
        word[indices[i]] = replacement[i];
    }
    return word;
}
void File2mSearcher::replaceAllInList(const std::string& pattern, const std::string& replacement) {
        for (std::string& word : words) {
            word = replaceInWord(word, pattern, replacement);
        }
    }

bool File2mSearcher::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) return false;
    for (const std::string& w : words) {
        out << w << "\n";
    }
    return true;
}

size_t File2mSearcher::size() const {
    return words.size();
}

const std::vector<std::string>& File2mSearcher::getWords() const {
    return words;
}