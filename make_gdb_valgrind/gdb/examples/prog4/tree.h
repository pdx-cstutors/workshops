// CS Tutors Make/GDB/Valgrind Workshop
// Kendall Stewart

struct node {
  node();

  char * string;
  node * left;
  node * right;
};

class tree {
  public:
    tree();

    void insert(const char * string);
    void display_all();

  private:
    void insert(node *& root, const char * string);
    void display_all(node * root);
    node * root;
};
