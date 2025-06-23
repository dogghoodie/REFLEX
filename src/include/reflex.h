#ifndef REFLEX_H
#define REFLEX_H

#include <chrono>
#include <ncurses.h>

class Reflex {
public:
  // CONSTRUCTOR AND DESTRUCTOR
  Reflex(float timeLimit);
  ~Reflex();

  // START GAME LOOP
  void start();

private:
  // INITIALIZE AND DRAW CURSES WINDOW
  void initCursesWindow();
  void printCursesWindow();

  // FUNCTIONS FOR GAME DATA
  void game();
  char getTargetCharacter();
  float getScore() const;
  float getAverageTime() const;
  char getFavoriteKey() const;
  void updateLeaderboard();
  void saveScore();
  bool playAgain();
  void formatting();

  // GAME VARIABLES
  int key;
  float score;
  double TIME_LIMIT;
  float averageTime;
  char targetKey;
  char favoriteKey;
  std::vector<float> leaderboard;

  // NCURSES VARIABLES
  WINDOW *win;
  int winWidth, winHeight;
  int termWidth, termHeight;
};

#endif
