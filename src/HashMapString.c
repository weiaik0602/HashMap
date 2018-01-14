#include "HashMapString.h"



void hashMapAddString(HashTable *table,char *str,int key){
  int index=hashUsingModulo(key,table->size);
  Data *data=dataCreate(key,str);
  _hashMapAdd(table,data,key,index,(Compare)CompareKey);
}

void *hashMapSearchString(HashTable *table,int key){
  int index=hashUsingModulo(key,table->size);
  return _hashMapSearch(table,key,index,(Compare)CompareKey);
}


void hashMapRemoveString(HashTable *table,int key){
  int index=hashUsingModulo(key,table->size);
  _hashMapRemove(table,key,index,(Compare)CompareKey);
}
