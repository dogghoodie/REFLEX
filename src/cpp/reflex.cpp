#include "../include/reflex.h"
#include <iostream>
#include <random>

Reflex::Reflex(float TIME_LIMIT)
    : score(0), TIME_LIMIT(TIME_LIMIT), averageTime(0.0f), key(-1),
      targetKey(' '), favoriteKey(' '), win(nullptr) {
  std::cout << "Reflex::Reflex()\n";
}

Reflex::~Reflex() {
  if (win) {
    delwin(win);
    endwin();
  }
  std::cout << "Reflex::~Reflex()\n";
}

void Reflex::start() {
  while (true) {
    initCursesWindow();
    game();
    if (playAgain()) {
      continue;
    } else {
      break;
    }
  }
}

// TODO : Implement target and clean up this method a TON
void Reflex::game() {

  while (true) {

    targetKey = getTargetCharacter();

    mvwprintw(win, 1, 8, "%c.", targetKey);
    wrefresh(win);
    // START TIMER
    auto startTime = std::chrono::high_resolution_clock::now();

    key = wgetch(win);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;
    if (key == targetKey && elapsedTime.count() <= TIME_LIMIT) {
      score++;
      mvwprintw(win, 3, 3, "Time: %.5f", elapsedTime.count());
      wrefresh(win);
      if (elapsedTime.count() > TIME_LIMIT) {

        formatting();
        updateLeaderboard();

        // DEBUG
        std::cout << score;

        break;
      }
    } else {

      formatting();
      updateLeaderboard();

      // DEBUG
      wgetch(win);
      std::cout << "AA" << score;

      score = 0;
      break;
    }
  }
}

void Reflex::initCursesWindow() {
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

  win = newwin(winHeight, winWidth, startY, startX);
  int max_x = getmaxx(win);
  int clear_width = max_x - 2 - 2; // leave space for border and "X"
  std::string spaces(clear_width, ' ');
  box(win, 0, 0);

  std::string title = "REFLEX";
  int title_x = startX + (winWidth - title.length()) / 2;
  mvprintw(startY - 1, title_x, "%s", title.c_str());
  refresh();
  wrefresh(win);
}

void Reflex::printCursesWindow() {}

void Reflex::updateLeaderboard() {
  // TODO : Write score to csv with MM:DD:YYYY
}

char Reflex::getTargetCharacter() {

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 25);

  std::vector<char> CHAR_LIST;
  for (char targetKey = 'a'; targetKey <= 'z'; targetKey++) {
    CHAR_LIST.push_back(targetKey);
  }
  int rand = dist(gen);

  char targetKey = CHAR_LIST[rand];
  return targetKey;
}

float Reflex::getScore() const { return score; }
float Reflex::getAverageTime() const { return averageTime; }
char Reflex::getFavoriteKey() const { return favoriteKey; }

void Reflex::saveScore() {}
bool Reflex::playAgain() { return true; }

void Reflex::formatting() {
  // GET WDITH OF WINDOW
  int max_x = getmaxx(win);
  // LEAVE SPACE FOR BORDER AND "X"
  int clear_width = max_x - 2 - 2;
  std::string spaces(clear_width, ' ');
  mvwprintw(win, 3, 2, "%s", spaces.c_str());
  mvwprintw(win, 2, 2, "%s", spaces.c_str());
  mvwprintw(win, 2, 2, "Streak: %.1f", score);
  wrefresh(win);
}
