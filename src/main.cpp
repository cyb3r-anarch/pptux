/*
* Typing Test Program
* Description: typing test program written in C++
* Author: cyb3r-anarch
*/
#include "../include/ncurses_helper.h"
#include "../include/wordlist_helper.h"



int main() {
    initializeNcurses();
    wordListPath = "resources/wordlists/english";

    appendWordList(wordList, wordListPath);

    int winHeight, winWidth, winY_cor, winX_cor;
    winHeight = 4;
    winWidth = 80;
    winX_cor = 0; // Adjusted X coordinate to start from the left
    winY_cor = 2; // Adjust the Y coordinate to be towards the top

    WINDOW* wordWin = newwin(winHeight, winWidth, winY_cor, winX_cor);
    WINDOW* inputWin = newwin(3, winWidth, winY_cor + winHeight, winX_cor); // Adjusted starting position and width
    refresh();

    box(wordWin, 0, 0);
    box(inputWin, 0, 0);
    displayWords(wordList, wordWin, 0);

    wrefresh(wordWin);
    wrefresh(inputWin);

    int ch;
    int inputIndex = 0;

    while ((ch = mvwgetch(inputWin, 1, inputIndex + 1)) != KEY_F(1)) {
        if (ch == ' ' || ch == '\n') {
            // Handle space or enter key separately
            currentWordIndex++;
            if (currentWordIndex == wordList.size()) {
                // End of the word list, break the loop
                break;
            }

            // Clear the input window for the new word
            werase(inputWin);
            box(inputWin, 0, 0);
            wrefresh(inputWin);

            // Display the new word
            displayWords(wordList, wordWin, 0);

            // Reset input variables
            inputIndex = 0;
        } else if (ch == wordList[currentWordIndex][inputIndex]) {
            wattron(inputWin, COLOR_PAIR(CORRECT_PAIR));
            waddch(inputWin, ch);
            wattroff(inputWin, COLOR_PAIR(CORRECT_PAIR));
            inputIndex++;
        } else {
            // Handle incorrect input
            wattron(inputWin, COLOR_PAIR(WRONG_PAIR));
            waddch(inputWin, ch);
            wattroff(inputWin, COLOR_PAIR(WRONG_PAIR));
            // Allow user to continue typing the word
            mvwprintw(inputWin, 1, inputIndex + 1, "%s", wordList[currentWordIndex].substr(inputIndex).c_str());
        }

        // Display updated words with character-wise coloring
        displayWords(wordList, wordWin, inputIndex);
    }

    cleanupNcurses();
    return 0;
}
