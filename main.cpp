#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <ncurses.h>
#include <random>
#include <vector>

void reflex(WINDOW *win, float TIME) {
  int key = -1;
  float streak = 0;
  while (true) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 25);

    std::vector<char> CHAR_LIST;
    for (char c = 'a'; c <= 'z'; c++) {
      CHAR_LIST.push_back(c);
    }
    int max_x = getmaxx(win);
    int clear_width = max_x - 2 - 2; // leave space for border and "X"

    int rand = dist(gen);

    char target = CHAR_LIST[rand];
    mvwprintw(win, 1, 8, "%c.", target);
    wrefresh(win);

    auto startTime = std::chrono::high_resolution_clock::now();

    key = wgetch(win);

    if (key == target) {
      streak++;
      auto endTime = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> elapsedTime = endTime - startTime;

      mvwprintw(win, 3, 2, "Time: %.5f", elapsedTime.count());
      wrefresh(win);
      if (elapsedTime.count() > TIME) {
        std::string spaces(clear_width, ' ');
        mvwprintw(win, 3, 2, "%s", spaces.c_str());
        mvwprintw(win, 2, 2, "%s", spaces.c_str());
        mvwprintw(win, 2, 2, "Streak: %.1f", streak);
        wrefresh(win);
        break;
      }
    } else {

      std::string spaces(clear_width, ' ');
      mvwprintw(win, 3, 2, "%s", spaces.c_str());
      mvwprintw(win, 2, 2, "%s", spaces.c_str());
      mvwprintw(win, 2, 2, "Streak: %.1f", streak);
      wrefresh(win);
      streak = 0;
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Use: " << argv[0] << " <TIME>\n";
    return 1;
  }
  float TIME = std::stof(argv[1]);

  initscr();
  cbreak();
  noecho();
  curs_set(0);

  int termHeight, termWidth;
  getmaxyx(stdscr, termHeight, termWidth);
  int winHeight = 5;
  int winWidth = 18;
  int startY = (termHeight - winHeight) / 2;
  int startX = (termWidth - winWidth) / 2;

  WINDOW *win = newwin(winHeight, winWidth, startY, startX);
  int max_x = getmaxx(win);
  int clear_width = max_x - 2 - 2; // leave space for border and "X"
  std::string spaces(clear_width, ' ');
  box(win, 0, 0);

  std::string title = "REFLEX";
  int title_x = startX + (winWidth - title.length()) / 2;
  mvprintw(startY - 1, title_x, "%s", title.c_str());
  refresh();

  while (true) {
    reflex(win, TIME);
    mvwprintw(win, 1, 2, "%s", spaces.c_str());
    mvwprintw(win, 3, 2, "Continue? y/n");
    wrefresh(win);
    char input = wgetch(win);
    if (input == 'y') {
      mvwprintw(win, 1, 2, "%s", spaces.c_str());
      mvwprintw(win, 2, 2, "%s", spaces.c_str());
      mvwprintw(win, 3, 2, "%s", spaces.c_str());
      continue;
    } else {
      break;
    }
  }

  wrefresh(win); // update screen
  endwin();
  return 0;
}
