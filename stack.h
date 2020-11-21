/*
 * queue.h
 */

typedef struct stack_elt_tag {
  int *name;
  struct stack_elt_tag *next;
} stack_elt;

typedef struct {
  stack_elt *first;
} stack;

void init_stack (stack *q);
void add_name (stack *q, int *name);
int * remove_name (stack *q);
int * get_name (stack *q);
void delete_all_entries (stack *q);
void print_stack (stack *q);
