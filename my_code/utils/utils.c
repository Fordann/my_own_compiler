
#include <string.h>
#include "utils.h"

int isLetter(char letter) {
    if (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z'))
      return SUCCESS;
  return ERROR;
}

int isChar(char ch) {
  return isDigit(ch) || isLetter(ch) || isSpecialChar(ch);
}
int isSpecialChar(char ch) {
    switch (ch) {
      case '=':
      case ';':
      case '(':
      case ')':
      case ',':
      case '+':
      case '-':
      case '/':
      case '*':
      case '{':
      case '}':
      case '<':
      case '>':
      case '!':
      case 0:
        return SUCCESS;
      default:
        return ERROR;
    }
}

int isDigit(char ch) {
    return ('0' <= ch && ch <= '9');
}


int isNumber(const char* result_word) {
  for (int i = 0; i < strlen(result_word); i++) {
    if (!isDigit(result_word[i]))
      return ERROR;
  }
  return SUCCESS;
}
