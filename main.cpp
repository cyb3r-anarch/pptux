/*
* Typing Test Program
* Description: soon to come
* Author: cyb3r-anarch
*/
#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <array>
#include <string>

std::string wordListPath;
std::vector<std::string> wordList = {};


void initializeNcurses(){
  initscr(); // Start curses mode
  noecho(); // disables echoing characters typed
}

void cleanupNcurses(){
  getch(); //wait for character input before exiting
  endwin();// exits curses mode
}

void appendWordList(std::vector<std::string>& thisWordList, std::string wordFilePath){
  std::string word;
  std::ifstream wordlist("resources/wordlists/english");
  if(wordlist.is_open())
  {
    while(getline(wordlist,word))
    {
      thisWordList.push_back(word);
    }
    wordlist.close();
  }
  else{
    std::cout << "Error getting file" << std::endl;
  }
}

void displayWords(std::vector<std::string> thisWordList){
  // clear(); //Clears the screen before displaying 
  move(10,0);
  for(int i = 0; i < thisWordList.size(); i++){
    printw("%s ",thisWordList[i].c_str());
  }
}

int main() {
  initializeNcurses();
  wordListPath = "resources/wordlists/english";

  appendWordList(wordList,wordListPath);
  displayWords(wordList);
  move(0,0);
  getch();
  cleanupNcurses();
  return 0;
}

