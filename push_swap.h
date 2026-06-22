#ifndef  PUSH_SWAP_H
#define  PUSH_SWAP_H

typedef struct s_node
{
    int             value;  // Il numero originale (es. -500, 18, 2147483647)
    int             index;  // La sua posizione finale ordinata (es. 0, 1, 2...)
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct  s_stack
{
  t_node  *top;
  int      size;
}  t_stack;
