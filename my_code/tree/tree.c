#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "../token/token.h"
#include "../utils/utils.h"

struct Tree* initEmptyTree() {
  struct Tree* t = malloc(sizeof(struct Tree));
  t->childs = NULL;
  t->max_size = 0;
  t->nb_childs = 0;
  t->value = 0;
  return t;
}

struct Tree* initTreeWithValue(struct Token token, char value) {
  struct Tree* t = initEmptyTree();
  t->value = value;
  t->token = token.type; 
  return t;
}

struct Tree* initEmptyTreeForSearch() {
  struct Token wildcard = createStringWildcardToken();
  struct Tree* child = initTreeWithValue(wildcard, '%');
  addChildTree(child, child);
  return child;
}

char getValueTree(struct Tree* t) {
  return t->value;
}

void increaseSizeTree(struct Tree* t) {
  if (t->max_size == 0) {
    t->max_size = 1;
    t->childs = malloc(sizeof(struct Tree));
  }
  else {
    if (t->nb_childs == t->max_size) {
      t->max_size *=2;
      t->childs = realloc(t->childs, t->max_size * sizeof(struct Tree));
    }
  } 
  }

int findValueInChildsTree(struct Tree* t, char value) {
  for (int current_child = 0; current_child < t->nb_childs; current_child++) {
    if (getValueTree(t->childs[current_child]) == value) {
      return current_child;
    }
  }
  return -1;
}

struct Tree* addChildTree(struct Tree* t, struct Tree* child) {
    increaseSizeTree(t);
    t->childs[t->nb_childs] = child;
    t->nb_childs++;
    return child;
}

void addBranchInTree(struct Tree* root_tree, struct Token token) {
  struct Tree* current_tree = root_tree;
  for (int letter = 0; letter < strlen(token.literal); letter++) {
    int child_who_has_value = findValueInChildsTree(current_tree, token.literal[letter]);
    if (child_who_has_value != -1) {
        current_tree = current_tree->childs[child_who_has_value];
    }
    else {
      if (!isSpecialChar(token.literal[letter]))
        addChildTree(current_tree, initEmptyTreeForSearch());
      current_tree = addChildTree(current_tree, initTreeWithValue(token, token.literal[letter])); 
    }
  }
}

struct Tree* searchNodeTree(struct Tree* t, char* word) {
  struct Tree* current_tree = t;
  for (int letter = 0; letter < strlen(word); letter++) {
    int child_who_has_value = findValueInChildsTree(current_tree, word[letter]);
    
    if (child_who_has_value == -1 && (isLetter(word[letter]) || isDigit(word[letter])))
      child_who_has_value = findValueInChildsTree(current_tree, '%');

    if (child_who_has_value != -1) {
        current_tree = current_tree->childs[child_who_has_value];
    }
    else {
      return NULL;
    }
  }
  return current_tree;
}

int isValidNextChar(struct Tree* t, char* already_read_word, char char_to_add) {
  if (strcmp(already_read_word, "") == 0) {
    return 1;
  }

  size_t word_size = strlen(already_read_word);
  char* new_word = malloc((word_size + 2 ) * sizeof(char));
  strcpy(new_word, already_read_word);
  new_word[word_size] = char_to_add;
  new_word[word_size + 1] = 0;

  return searchNodeTree(t, new_word) != NULL;
}

struct Tree* createTreeParser() {
  struct Tree* t = initEmptyTree();
  addChildTree(t, initEmptyTreeForSearch());

  #define NB_SYMB 26

  struct Token tab[NB_SYMB] = {
        newToken(EQ, "="),
        newToken(LT, "<"),
        newToken(GT, ">"),
        newToken(COMMA, ";"),
        newToken(FUNCTION, "("),
        newToken(FUNCTION, ")"),
        newToken(FUNCTION, ","),
        newToken(FUNCTION, "!"),
        newToken(FUNCTION, "+"),
        newToken(FUNCTION, "-"),
        newToken(FUNCTION, "/"),
        newToken(FUNCTION, "*"),
        newToken(FUNCTION, "{"),
        newToken(FUNCTION, "}"),
        newToken(FUNCTION, "function"),
        newToken(FUNCTION, "let"),
        newToken(FUNCTION, "return"),
        newToken(FUNCTION, "true"),
        newToken(FUNCTION, "false"),
        newToken(FUNCTION, "if"),
        newToken(FUNCTION, "else"),
        newToken(FUNCTION, "!="),
        newToken(FUNCTION, "=="),
        newToken(FUNCTION, "for"),
        newToken(FUNCTION, "in"),
        newToken(FUNCTION, "range"),
      
  };
  for (int i = 0; i < NB_SYMB; i++) {
    addBranchInTree(t, tab[i]);
  }
  return t;
}

void displayTree(struct Tree* t, int depth) {
    if (t == NULL) return;
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%c\n", t->value);
    
    for (int i = 0; i < t->nb_childs; i++) {
        if (t->childs[i]->value != '%' || t->value !='%')
          displayTree(t->childs[i], depth + 1);
    }
}

