// CS Tutors Make/GDB/Valgrind Workshop
// Kendall Stewart

#include <iostream>
#include <cstring>
#include "tree.h"
using namespace std;

node::node() : string(NULL), left(NULL), right(NULL) {}

tree::tree() : root(NULL) {}

void tree::insert(const char * string) {
  insert(root, string);    
}

void tree::insert(node *& root, const char * string) {
  if(!root) {
    root = new node;
    root->string = new char[strlen(string) + 1];
    strcpy(root->string, string);
  }
  // Hmm...
  else if (strcmp(root->string, string) < 0)
    insert(root->left, string);
  else
    insert(root->right, string);
}

void tree::display_all() {
  display_all(root);
}

void tree::display_all(node * root)
{
  if(!root)
    return;

  display_all(root->left);
  cout << root->string << endl;
  display_all(root->right);
}
