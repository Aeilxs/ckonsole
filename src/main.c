#include <stdio.h>

#include "ansi_code.h"
#include "logger.h"

void test_logger();
void test_ansicode();

int main() {
  test_logger();
  test_ansicode();
  return 0;
}

void test_logger() {
  printf("\n===== LOGGER TEST SUITE =====\n");
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
  printf("\n===== ANSI CODE TEST SUITE =====\n");

  printf(BBLU "   " RST BWHT "   " RST BRED "   " RST "\n");
  printf(BLU "blue " ULINE "uline blue\n" RST);
  printf(YLW "yellow " STRKTRGH "strktrgh yellow\n" RST);
  printf(BOLD "Some bold\n" RST);
}