/*
 * queue.c
 */

#include "stack.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void init_stack (stack *q)
{
  q->first = NULL;
  
}

void add_name (stack *q, int *name)
{
  stack_elt *elt;
  
  // Allocate a new list element with malloc
  elt = malloc (sizeof(*elt));


  // If malloc fails end the program
  if (elt == NULL) {
    printf ("Couldn't allocate a new queue element\n");
    exit (1);
  }

  // Allocate space to store the name
  elt->name = malloc(1);

  // If malloc fails end the program
  if (elt->name == NULL) {
    printf ("Couldn't allocate a new name\n");
    exit (1);
  }

  // Copy the name
  *elt->name = *name;

  elt->next = q->first;
  q->first = elt;



  // Check if queue is empty
  //if (q->last) {
    // add elt to the end
    //(q->last)->next = elt;
  //} else {
    //q->first = elt;
  //}
  //q->last = elt;
}

int * remove_name (stack *q)
{
  stack_elt *elt;
  int *answer = NULL;
  if (q->first) {
    elt = q->first;

    
    q->first = elt->next;
    
	answer = elt->name;
    // free the elt
    //free(elt->name);
    free(elt);
  }
  return answer;
}

void delete_all_entries (stack *q)
{
  while (q->first) {
    int *answer = 
    remove_name (q);
    free(answer);
  }
}

void print_stack (stack *q)
{
  stack_elt *elt = q->first;
	//printf ("%d\n", *elt->name);
  printf ("\nQUEUE CONTENTS\n");

  while (elt) {
    printf ("%d\n", *elt->name);
    elt = elt->next;
  }
}

int * get_name (stack *q)
{
  stack_elt *elt;
  int *answer = NULL;
  if (q->first) {
    elt = q->first;

    
	answer = elt->name;
    
  }
  return answer;
}



