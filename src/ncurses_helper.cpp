#include "../include/ncurses_helper.h"

int currentWordIndex;
std::string wordListPath;
std::vector<std::string> wordList;

void initializeNcurses() {
    initscr();      // Start curses mode
    start_color();  // Enable color
    init_pair(NCURSES_HELPER::CORRECT_PAIR, COLOR_GREEN, COLOR_BLACK);
    init_pair(NCURSES_HELPER::WRONG_PAIR, COLOR_RED, COLOR_BLACK);
    init_pair(NCURSES_HELPER::DEFAULT_PAIR, COLOR_WHITE, COLOR_BLACK);
    noecho();       // Disable echoing characters typed
    raw();          // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys
    curs_set(1);    // Cursor visibility (0: invisible, 1: normal, 2: very visible)
}

void cleanupNcurses() {
    getch();        // Wait for character input before exiting
    endwin();       // Exit curses mode
}


void displayWords(const std::vector<std::string>& thisWordList, WINDOW* window, int inputIndex) {
    werase(window); // Clear the word window
    box(window, 0, 0);
    mvwprintw(window, 1, 1, "Words to type:");

    int row = 2;
    int col = 1;
    for (int i = 0; i < thisWordList.size(); ++i) {
        const std::string& word = thisWordList[i];
        for (int j = 0; j < word.length(); ++j) {
            if (i == currentWordIndex) {
                // Highlight only the current word
                if (j < inputIndex) {
                    // Character has been typed
                    wattron(window, COLOR_PAIR((word[j] == wordList[currentWordIndex][j]) ? CORRECT_PAIR : WRONG_PAIR));
                    mvwprintw(window, row, col++, "%c", word[j]);
                    wattroff(window, COLOR_PAIR((word[j] == wordList[currentWordIndex][j]) ? CORRECT_PAIR : WRONG_PAIR));
                } else {
                    // Character not yet typed
                    wattron(window, COLOR_PAIR(DEFAULT_PAIR));
                    mvwprintw(window, row, col++, "%c", word[j]);
                    wattroff(window, COLOR_PAIR(DEFAULT_PAIR));
                }
            } else {
                // Display other words without highlighting
                wattron(window, COLOR_PAIR(DEFAULT_PAIR));
                mvwprintw(window, row, col++, "%c", word[j]);
                wattroff(window, COLOR_PAIR(DEFAULT_PAIR));
            }
        }

        // Add space between words
        col++;
    }

    wrefresh(window);
}
