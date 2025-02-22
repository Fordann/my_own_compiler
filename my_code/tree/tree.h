#ifndef TREE_H
#define TREE_H

#include "../token/token.h"

#ifndef SUCCESS
#define SUCCESS 1
#endif
#ifndef ERROR 
#define ERROR 0
#endif


struct Tree {
  char value;
  enum token_type token;
  struct Tree** childs;
  int max_size;
  int nb_childs;
};

void addBranchInTree(struct Tree* root_tree, struct Token token);

struct Tree* initEmptyTreeForSearch();

void displayTree(struct Tree* t, int depth);

struct Tree* initEmptyTree();
struct Tree* initTreeWithValue(struct Token token, char value);

int isValidNextChar(struct Tree* t, char* already_read_word, char char_to_add);

struct Tree* addChildTree(struct Tree* t, struct Tree* child);

void increaseSizeTree(struct Tree* t);

struct Tree* createTreeParser();

void freeTree(struct Tree*);

#endif
