#ifndef CKONSOLE_LOGGER_H
#define CKONSOLE_LOGGER_H

#include <stdarg.h>

typedef enum {
  LVL_DEBUG   = 1,
  LVL_INFO    = 2,
  LVL_WARN    = 3,
  LVL_ERROR   = 4,
  LVL_SUCCESS = 5,
} _LogLevel;

/**
 * PRIVATE
 */

static void _log_generic(_LogLevel lvl, const char *msg, va_list args);
static const char *_get_lvl_str(_LogLevel lvl);
static const char *_get_color_str(_LogLevel lvl);

/**
 * PUBLIC
 */

void log_debug(const char *msg, ...);
void log_info(const char *msg, ...);
void log_warn(const char *msg, ...);
void log_error(const char *msg, ...);
void log_success(const char *msg, ...);

#endif // CKONSOLE_LOGGER_H