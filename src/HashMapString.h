#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H


#include "HashMap.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "malloc.h"
#include "intCompare.h"
#include "LinkedL.h"
#include "Data.h"


void hashMapAddString(HashTable *table,char *str,int key);
void *hashMapSearchString(HashTable *table,int key);
void hashMapRemoveString(HashTable *table,int key);
#endif // _HASHMAPSTRING_H
