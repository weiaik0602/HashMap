#include "Data.h"
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>


Data *dataCreate(uint32_t key,void *value){
  Data *data =(Data *)malloc(sizeof(Data));
  data->key=key;
  data->value=value;
}
