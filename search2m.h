#ifndef SEARCHER2M_H
#define SEARCHER2M_H

#include <string>
#include <vector>

class File2mSearcher {
public:
    bool loadFromFile(const std::string& filename);
    bool isthere(const std::string& word ,const std::string& pattern) const;
    size_t size() const;
    const std::vector<std::string>& getWords() const;
    void replaceAllInList(const std::string& pattern, const std::string& replacement);
    bool saveToFile(const std::string& filename) const;
    std::string replaceInWord(std::string word, const std::string& pattern, const std::string& replacement) const;
private:
    std::vector<std::string> words;
    static std::string toLowerCopy(const std::string& s);
};

#endif
