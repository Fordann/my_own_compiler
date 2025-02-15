
#include <string.h>
#include "utils.h"

int isLetter(char letter) {
    if (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z'))
      return SUCCESS;
  return ERROR;
}

int isChar(char ch) {
  return isLetter(ch) || isSpecialChar(ch);
}
int isSpecialChar(char ch) {
    switch (ch) {
      case '=':
      case ';':
      case '(':
      case ')':
      case ',':
      case '+':
      case '{':
      case '}':
      case 0:
        return SUCCESS;
      default:
        return ERROR;
    }
}

int isNumber(const char* result_word) {
  for (int i = 0; i < strlen(result_word); i++) {
    if (result_word[i] < '0' || result_word[i] > '9')
      return ERROR;
  }
  return SUCCESS;
}
