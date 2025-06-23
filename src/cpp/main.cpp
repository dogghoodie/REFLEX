#include "progress_bar.h"
#include "reflex.h"
#include <iostream>

int main(int argc, char *argv[]) {
  // TODO : Add flags
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <time_limit_in_seconds>\n";
    return 1;
  }
  float TIME_LIMIT = std::stof(argv[1]);

  Reflex reflex(TIME_LIMIT);
  ProgressBar progressBar(TIME_LIMIT);
  progressBar.initCursesWindow();
  reflex.start();

  return 0;
}
