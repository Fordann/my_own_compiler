#ifndef SUCCESS
#define SUCCESS 1
#endif
#ifndef ERROR 
#define ERROR 0
#endif

struct Tree {
  char value;
  struct Tree** childs;
  int max_size;
  int nb_childs;
};

void addBranchInTree(struct Tree* root_tree, char* word_to_add);

void displayTree(struct Tree* t, int depth);

struct Tree* initEmptyTree();

int isValidNextChar(struct Tree* t, char* already_read_word, char char_to_add);
