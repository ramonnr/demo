#include <stdio.h>
#include "linked_list.h"

//application specific implementations of print and compare
void print_func(node*);
int comp_func(void*, void*);

int main(void){
  //setup new list with int pointers 
  int j = 0;
  node* list = linked_list_init( (void*)&j, sizeof(int), comp_func, print_func );
  for(int i = 1; i < 10; i++){
    list->push( list, (void*)&i );
  }

  //test print function, should print [0,9]
  list->print(list);
  printf("\n");

  //test contains and pop functions, should print {yes, no}
  //implicit test of compare function
  printf("does list contain: %d ? %s\n", j, (list->contains(list,&j)?"yes":"no"));
  //should pop 0 off the list
  list -> pop(&list, &j);
  printf("popped value: %d\n",j);
  printf("does list contain: %d ? %s\n", j, (list->contains(list,&j)?"yes":"no"));

  //test destroy function, this is best tested by running the program through
  //a memory profiler, like valgrind, should return no errors (duh!)
  list->destroy(list);
  return 0;
}

void print_func(node* n){
  int i = 0;
  while( n != NULL ){
    printf("node #i: %d, payload: %d\n", i++, *(int*)n->payload);
    n = n -> next;
  }
}

int comp_func(void* x, void* y){
  return *(int*)x == *(int*)y; 
}
