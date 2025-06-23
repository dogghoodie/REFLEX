#include "progress_bar.h"

ProgressBar::ProgressBar(double TIME_LIMIT) : win(nullptr) {}

ProgressBar::~ProgressBar() {
  if (win) {
    delwin(win);
    endwin();
  }
}

void ProgressBar::initCursesWindow() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);

  int termHeight, termWidth;
  getmaxyx(stdscr, termHeight, termWidth);
  int winHeight = 3;
  int winWidth = 18;
  int startY = (termHeight - winHeight) / 2 + 3;
  int startX = (termWidth - winWidth) / 2;

  win = newwin(winHeight, winWidth, startY, startX);
  int max_x = getmaxx(win);
  int clear_width = max_x - 2 - 2; // leave space for border and "X"
  box(win, 0, 0);

  refresh();
  wrefresh(win);
}

void ProgressBar::drawProgressBar() {
  if (!win) {
    initCursesWindow();
  }

  int max_x = getmaxx(win);

  // Draw the progress bar
  wrefresh(win);
}
