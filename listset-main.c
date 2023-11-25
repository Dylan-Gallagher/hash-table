#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashtable.h"

// main function to test the hashtable ADT
int main(int argc, char ** argv) {
  struct hashtable * myset;

  if ( argc < 2 ) {
    fprintf(stderr, "Usage: ./hashtable <command> <string> <command> <string> ... \n");
    fprintf(stderr, "       where <command> is + (add following string)\n");
    fprintf(stderr, "                          - (remove following string)\n");
    fprintf(stderr, "                          = (print set)\n");
    fprintf(stderr, "                          # (print cardinality)\n");
    fprintf(stderr, "       Example: ./hashtable + Cat + Dog + Elephant - Dog =\n");
    exit(1);
  }

  // create a set and follow the commands
  myset = hashtable_new(100);
  int i = 1;
  while ( i < argc ) {
    if ( argv[i][0] == '+' ) {
      assert( i+1 < argc );
      hashtable_add(myset, argv[i+1]);
      i = i + 2;
    }
    else if (argv[i][0] == '-' ) {
      assert( i+1 < argc );
      hashtable_remove(myset, argv[i+1]);
      i = i + 2;
    }
    else if (argv[i][0] == '=' ) {
      hashtable_print(myset);
      i++;
    }
    else if (argv[i][0] == '#' ) {
      printf("cardinality: %d\n", hashtable_cardinality(myset));
      i++;
    }
    else {
      fprintf(stderr, "Error: Unknown command %s\n", argv[i]);
      exit(1);
    }
//    assert( 0 ); // we should never get here
  }
    
  return 0;
}
