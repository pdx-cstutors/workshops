// CS Tutors Make/GDB/Valgrind Workshop
// Kendall Stewart

#include "tree.h"

 int main(void) {
   tree test;

   const char * strings[7] = {"gertrude", "paulette", "constance", 
			      "bridget", "faith", "zelda", "millicent"};

  /*
   *            gertrude
   *         /            \
   *    constance         paulette
   *    /      \         /       \
   * bridget  faith  millicent  zelda
   *
   */

  for (int i = 0; i<7; ++i)
    test.insert(strings[i]);

  test.display_all();
}
