#include "../include/wordlist_helper.h"
#include <iostream>
#include <fstream>


void appendWordList(std::vector<std::string>& thisWordList, const std::string& wordFilePath) {
    std::string word;
    std::ifstream wordlist(wordFilePath);
    if (wordlist.is_open()) {
        while (getline(wordlist, word)) {
            thisWordList.push_back(word);
        }
        wordlist.close();
    } else {
        std::cout << "Error getting file" << std::endl;
    }
}
