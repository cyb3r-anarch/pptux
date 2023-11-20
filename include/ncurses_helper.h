// ncurses_helper.h

#ifndef NCURSES_HELPER
#define NCURSES_HELPER

#include <ncurses.h>
#include <vector>
#include <string>

// Color pairs for highlighting
enum ColorPairs {
    CORRECT_PAIR = 1,
    WRONG_PAIR,
    DEFAULT_PAIR
};

extern int currentWordIndex;
extern std::string wordListPath;
extern std::vector<std::string> wordList;

void initializeNcurses();
void cleanupNcurses();
void displayWords(const std::vector<std::string>& thisWordList, WINDOW* window, int inputIndex);

#endif // NCURSES_HELPER_H
