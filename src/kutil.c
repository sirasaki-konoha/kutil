#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "kutil.h"

char *format_string(const char *restrict __format, ...) {
  va_list args;
  va_start(args, __format);

  va_list args_copy;
  va_copy(args_copy, args);
  int len = vsnprintf(NULL, 0, __format, args_copy);
  va_end(args_copy);

  if (len < 0) {
    va_end(args);
    return NULL;
  }

  char *buf = malloc(len + 1);
  if (!buf) {
    va_end(args);
    return NULL;
  }

  vsnprintf(buf, len + 1, __format, args);
  va_end(args);
  return buf;
}


char *safe_strdup(const char *s) {
  if (!s) return NULL;

  char *dup = malloc(strlen(s) + 1);
  if (!dup) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  strcpy(dup, s);
  return dup;
}


char *join_strings(char **strings, const char *separator) {
  unsigned long total_length = 0;
  int i;
  for (i = 0; strings[i] != NULL; i++) {
    total_length += strlen(strings[i]);
  }
  total_length += strlen(separator) * (i - 1);

  char *result = malloc(total_length + 1);
  result[0] = '\0';

  for (int i = 0; strings[i] != NULL; i++) {
    strcat(result, strings[i]);
    if (strings[i + 1] != NULL) {
      strcat(result, separator);
    }
  }

  return result;
}


char **split_whitespace(const char *input) {
  size_t argc = 0;
  size_t capacity = 10;
  char **argv = malloc(capacity * sizeof(char *));

  const char *p = input;
  while (*p) {
    while (isspace((unsigned char)*p)) p++;
    if (*p == '\0') break;

    const char *start = p;
    while (*p && !isspace((unsigned char)*p)) p++;

    size_t len = p - start;
    char *token = malloc(len + 1);
    strncpy(token, start, len);
    token[len] = '\0';

    if (argc + 1 >= capacity) {
      capacity *= 2;
      argv = realloc(argv, capacity * sizeof(char *));
    }

    argv[argc++] = token;
  }

  argv[argc] = NULL;
  return argv;
}

void free_str_array(char **argv) {
  for (size_t i = 0; argv[i] != NULL; i++) {
    free(argv[i]);
  }
  free(argv);
}


