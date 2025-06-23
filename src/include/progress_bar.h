#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <ncurses.h>

class ProgressBar {
public:
  // CONSTRUCTOR AND DESTRUCTOR
  ProgressBar(double TIME_LIMIT);
  ~ProgressBar();
  void initCursesWindow();
  void drawProgressBar();

private:
  // PROGRESS BAR VARIABLES
  double TIME_LIMIT;
  int barWidth;

  // NCURSES VARIABLES
  WINDOW *win;
  int winWidth, winHeight;
  int termWidth, termHeight;
};

#endif
