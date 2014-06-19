/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "aha.h"

static inline Node create_a_node();

static inline Node
create_a_node()
{
  Node ret = (Node)malloc(sizeof(struct node));
  ret->data = (Type)0;
  ret->next = NULL;
  return ret;
}

Node
list_init(uint size, Type data[])
{
  if (size <= 0)
  {
    return NULL;
  }

  Node tmp = create_a_node();
  Node head = tmp;
  for (int i = 0; i < size; ++i)
  {
    tmp->data = data[i];
    if (i != size - 1){
      tmp->next = create_a_node();
      tmp = tmp->next;
    }
  }
  return head;
}

Node
list_init()
{
  return create_a_node();
}


void
delete_list(Node head)
{
  Node current = head;
  Node next;
  while(current->next!=NULL){
    next = current->next;
    free current;
    current = next;
  }
}

