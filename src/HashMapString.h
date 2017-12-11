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




void hashMapAddString(HashTable *table,char *data,int key);

void hashMapSearchString(HashTable *table,char *data,int key);

void hashMapRemoveString(HashTable *table,char *data,int key);

#endif // _HASHMAPSTRING_H
