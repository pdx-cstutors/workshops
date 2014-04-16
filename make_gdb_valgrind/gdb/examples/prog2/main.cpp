// CS Tutors Make/GDB/Valgrind Workshop
// Colleen Murphy

#include <iostream>
using namespace std;

void dootherthings(char * thing)
{
  cout << thing[0];
}

void dothings(char * thing)
{
	dootherthings(thing);
}

int main()
{
  char * thing = NULL;

  dothings(thing);

  return 0;
}
