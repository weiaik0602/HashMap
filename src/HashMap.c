#include "HashMap.h"



void hashMapInit(HashTable *table,int size){
  table->list = (LinkedList **)calloc(size*SIZE_FACTOR , sizeof(LinkedList **));
  table->size=size;
}

void _hashMapAdd(HashTable *table,void *data, int hashValue,Compare compfunc){
  if(table->list[hashValue]==NULL){
    table->list[hashValue]->data=data;
  }
}

void _hashMapSearch(HashTable *table,void *data, int index,Compare compfunc){

}


void _hashMapRemove(HashTable *table,void *data, int index,Compare compfunc){

}
uint32_t hashUsingModulo(uint32_t value,int size){
  return value%size;
}


void hashMapAddInteger(HashTable *table,void *data){
  int hashValue=hashUsingModulo(data,table->size);
  _hashMapAdd(table,(void *)data,hashValue,integerCompare);
}

void hashMapSearch(HashTable *table,void *data){

}


void hashMapRemove(HashTable *table,void *data){

}
