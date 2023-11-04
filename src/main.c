#include <stdio.h>
#include <unistd.h>

#include "ansi_code.h"
#include "logger.h"

void test_logger();
void test_ansicode();
void test_progressbar();

int main() {
  test_logger();
  test_ansicode();
  test_progressbar();
  return 0;
}

void test_progressbar() {
  printf(BOLD ULINE "\n===== PROGRESS BAR TEST SUITE =====\n\n" RST);

  log_info("Doing a very important task");
  for (int i = 1; i <= 100; i++) {
    progress_bar(i, "processing");
    usleep(20000);
  }
  log_success("it worked well !");

  printf(ULINE "\nIt should show an error if invalid value for progress:\n\n" RST);
  progress_bar(-1, "");
  progress_bar(101, "");
}

void test_logger() {
  printf(BOLD ULINE "\n===== LOGGER TEST SUITE =====\n\n" RST);

  log_debug("Some debug message");
  log_info("Some info message");
  log_warn("Some warning message :s");
  log_error("A sad sad sad error message :'(");
  log_success("Wow it worked (success message)");

  log_info("This is PI : %.2f", 3.14159);
  log_debug("An int : %d, then a string : %s", 42, "my super string");
  log_success(RED "A red success message :o" RST);
}

void test_ansicode() {
  printf(BOLD ULINE "\n===== ANSI CODE TEST SUITE =====\n\n" RST);

  printf(ITLC "should be italic\n");
  printf(BBLU "   " RST BWHT "   " RST BRED "   " RST "\n");
  printf(BLU "blue " ULINE "uline blue\n" RST);
  printf(YLW "yellow " STRKTRGH "strktrgh yellow\n" RST);
  printf(BOLD "Some bold\n" RST);
}
