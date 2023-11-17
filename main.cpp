/*
* Typing Test Program
* Description: soon to come
* Author: cyb3r-anarch
*/
#include <iostream>
#include <ncurses.h>
#include <string.h>

const int WORD_COUNT = 6;


void initializeNcurses(){
  initscr(); // Start curses mode
  noecho(); // disables echoing characters typed
}

void cleanupNcurses(){
  endwin();// exits curses mode
  getch(); //wait for character input before exiting
}

void displayWords(const std::string words[], const int wordCount){
  clear(); //Clears the screen before displaying 
  for(int i = 0; i < wordCount; i++){
    for(int j = 0; j < words[i].length();j++){
      printw("%c",words[i][j]);
      refresh(); //refreshes screen
      getch(); //waits for a character input before proceeding
    }
    printw(" "); // adds space between the words
    refresh();
  }
}

int main() {
  initializeNcurses();


  //array of string for temporary example 
  std::string words[6] = {"This", "is", "a", "typing","test","."}; 
  displayWords(words,WORD_COUNT);

  getch(); //wait for character input before exiting
  cleanupNcurses();


  return 0;
}

