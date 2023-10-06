#include <stdlib.h>
#include <string.h>

char *replace(const char *input_str) {
  if (input_str == NULL)
    return NULL;

  size_t input_length = strlen(input_str);
  char *out = (char *)malloc(input_length * 5 + 1); // Worst case malloc

  size_t out_index = 0;
  for (size_t i = 0; i < input_length && input_str[i] != '\0'; ++i) {
    switch (input_str[i]) {
    case '&':
      if (out_index + 5 <= input_length * 5) {
        strncpy(out + out_index, "&amp;", 5);
        out_index += 5;
      }
      break;
    case '<':
      if (out_index + 4 <= input_length * 5) {
        strncpy(out + out_index, "&lt;", 4);
        out_index += 4;
      }
      break;
    case '>':
      if (out_index + 4 <= input_length * 5) {
        strncpy(out + out_index, "&gt;", 4);
        out_index += 4;
      }
      break;
    default:
      if (out_index < input_length * 5) {
        out[out_index] = input_str[i];
        ++out_index;
      }
      break;
    }
  }
  out[out_index] = '\0';

  return out;
}
