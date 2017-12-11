#include "intCompare.h"

int integerCompare(int v1,int v2){
  if(v1 > v2)
    return 1;
  else if(v1<v2)
    return -1;
  else
    return 0;
  }



int CompareKey(uint32_t key, Data *data){
    if(key>data->key)
      return 1;
    else if(key<data->key)
      return -1;
    else
      return 0;

  }
