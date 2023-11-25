#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashset.h"

// main function to test the hashtable ADT
int main(int argc, char ** argv) {
    struct hashtable * my_hashtable;
    my_hashtable = hashtable_new(100);
    hashtable_add(my_hashtable, "Cat");
    hashtable_add(my_hashtable, "Dog");
    hashtable_add(my_hashtable, "Elephant");
    hashtable_add(my_hashtable, "Dog");
    hashtable_remove(my_hashtable, "Cat");
    hashtable_print(my_hashtable);
    
  return 0;
}
