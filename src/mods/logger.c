#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "ansi_code.h"
#include "logger.h"

static void _log_generic(_LogLevel lvl, const char *msg, va_list args) {
  const char *level_str = _get_lvl_str(lvl);
  const char *color_str = _get_color_str(lvl);

  printf("%s[%s] %s", color_str, level_str, RST);
  vprintf(msg, args);
  printf("\n");
}

void log_debug(const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  _log_generic(LVL_DEBUG, msg, args);
  va_end(args);
}

void log_info(const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  _log_generic(LVL_INFO, msg, args);
  va_end(args);
}

void log_warn(const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  _log_generic(LVL_WARN, msg, args);
  va_end(args);
}

void log_error(const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  _log_generic(LVL_ERROR, msg, args);
  va_end(args);
}

void log_success(const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  _log_generic(LVL_SUCCESS, msg, args);
  va_end(args);
}

void progress_bar(int percentage, const char *title) {
  if (percentage < 0 || percentage > 100) {
    // clang-format off
    const char *msg = "Progress percentage " BOLD "MUST " RST "be in the interval [0;100]";
    log_error("%s value: %d", msg, percentage);
    // clang-format on
    return;
  }

  printf(BOLD "[");
  int chars_to_print = (PROGRESS_BAR_LENGTH * percentage) / 100;

  for (int i = 0; i < PROGRESS_BAR_LENGTH; i++) {
    printf("%s", i <= chars_to_print ? RST "#" BOLD : " ");
    if (i == chars_to_print) {
      printf(">");
    }
  }

  printf("] %s [%d/100]\r" RST, title, percentage);
  fflush(stdout);

  if (percentage == 100) {
    printf("\n");
  }
}

static const char *_get_lvl_str(_LogLevel lvl) {
  const char *level_str;
  switch (lvl) {
  case LVL_DEBUG:
    level_str = "DEBUG";
    break;
  case LVL_INFO:
    level_str = "INFO";
    break;
  case LVL_WARN:
    level_str = "WARN";
    break;
  case LVL_ERROR:
    level_str = "ERROR";
    break;
  case LVL_SUCCESS:
    level_str = "SUCCESS";
    break;
  default:
    level_str = "UNKNOWN";
    break;
  }
  return level_str;
}

const char *_get_color_str(_LogLevel lvl) {
  const char *color_str;
  switch (lvl) {
  case LVL_DEBUG:
    color_str = BLU;
    break;
  case LVL_INFO:
    color_str = MGT;
    break;
  case LVL_WARN:
    color_str = YLW;
    break;
  case LVL_ERROR:
    color_str = RED;
    break;
  case LVL_SUCCESS:
    color_str = GRN;
    break;
  default:
    color_str = RED;
    break;
  }
  return color_str;
}
