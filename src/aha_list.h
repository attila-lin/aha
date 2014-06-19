/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include <stdlib.h>

#ifndef _AHA_LIST_H_
#define _AHA_LIST_H_

typedef int Type;

struct node
{
  Type data;
  struct node next;
};

typedef struct node * Node;

// init
Node list_init(uint size, Type data[]);
Node list_init();

// add

// insert
Node list_insert(Type data);

void delete_list(Node head);

#endif /*_AHA_LIST_H_*/