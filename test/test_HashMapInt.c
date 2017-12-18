#include "unity.h"
#include "HashMapInt.h"

#include "HashMap.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"
#include "intCompare.h"
#include "LinkedL.h"
#include "Data.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hashMapAddInteger(void)
{
  HashTable table;
  hashMapInit(&table,10);

  hashMapAddInteger(&table,5,1) ;
  Data *head=(table.list)[1].head->data;
  Data *tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,5);
  TEST_ASSERT_EQUAL(tail->value,5);

  hashMapAddInteger(&table,10,11);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,5);
  TEST_ASSERT_EQUAL(tail->value,10);

  hashMapAddInteger(&table,15,21);
  head=(table.list)[1].head->data;
  tail=(table.list)[1].tail->data;
  TEST_ASSERT_EQUAL(head->value,5);
  TEST_ASSERT_EQUAL(tail->value,15);
}


void test_hashMapSearchInteger(void){


}
