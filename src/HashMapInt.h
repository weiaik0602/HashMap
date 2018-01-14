#ifndef _HASHMAPINT_H
#define _HASHMAPINT_H


#include "HashMap.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "malloc.h"
#include "intCompare.h"
#include "LinkedL.h"
#include "Data.h"


void hashMapAddInteger(HashTable *table,int data,int key);

void *hashMapSearchInteger(HashTable *table,int key);

void hashMapRemoveInteger(HashTable *table,int key);
#endif // _HASHMAPINT_H
