#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// include the header files with the declarations of listset
#include "listset.h"

// create a new, empty linked list set
struct listset * listset_new() {
    struct listset * my_listset = (struct listset *) malloc(sizeof(struct listset *));
    my_listset->head = NULL;
    return my_listset;
}

/* check to see if an item is in the set
   returns 1 if in the set, 0 if not */
int listset_lookup(struct listset * this, char * item) {
    struct listnode * p;
    for (p = this->head; p != NULL ; p = p->next) {
        if (strcmp(item, p-> str) == 0) {
            return 1;
        }
    }
    return 0;
}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set.
// New items that are not already in the set should
// be added to the start of the list
void listset_add(struct listset * this, char * item) {
    // check if it's already in set
    if (listset_lookup(this, item) == 1) { return; }

    // make new node
    struct listnode * new_node = (struct listnode *) malloc(sizeof(struct listnode *));

    // copy string over
//    new_node->str = (char *) malloc(sizeof(char *));
    new_node->str = item;
    
    struct listnode * temp = this->head;
    this->head = new_node;
    new_node->next = malloc(sizeof(struct listnode));
    new_node->next = temp;
}

// remove an item with number 'item' from the set
void listset_remove(struct listset * this, char * item) {
    struct listnode * p_prev;
    struct listnode * p;
    for ( p = this->head; p != NULL; p = p->next ) {
        if (p->str != NULL && strcmp(p->str, item) == 0) {
            // remove node

            // if it's the head node
            if (this->head == p) {
                this->head = p->next;
            }
            else {
                p_prev->next = p->next;
            }

            break;

        }
        p_prev = p;
    }
}
  
// place the union of src1 and src2 into dest
void listset_union(struct listset * dest, struct listset * src1, struct listset * src2) {
    // Loop through src1 and add everything
    struct listnode * curr;
    for ( curr = src1->head; curr != NULL; curr = curr->next ) {
        listset_add(dest, curr->str);
    }

    // Loop through src2 and add everything 
    for ( curr = src2->head; curr != NULL; curr = curr->next ) {
        listset_add(dest, curr->str);
    }
}

// place the intersection of src1 and src2 into dest
void listset_intersect(struct listset * dest, struct listset * src1, struct listset * src2) {
    // Loop through src1
    struct listnode * curr;
    for ( curr = src1->head; curr != NULL; curr = curr->next ) {
        // If it's in src2, add it to dest
        if (listset_lookup(src2, curr->str) == 1) {
            listset_add(dest, curr->str);
        }
    }
}

// return the number of items in the listset
int listset_cardinality(struct listset * src) {
    // Loop through src and increment count each time
    int count = 0;
    struct listnode * p;
    for ( p = src->head; p != NULL; p = p->next) {
        count++;
    }
    return count;
}

// print the elements of the list set
void listset_print(struct listset * this) {
  struct listnode * p;

  for ( p = this->head; p != NULL; p = p->next ) {
    printf("%s, ", p->str);
  }
  printf("\n");
}
