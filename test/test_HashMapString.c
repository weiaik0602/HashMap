#include "unity.h"
#include "HashMapString.h"



#include "HashMap.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"
#include "intCompare.h"
#include "LinkedL.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_hashMapAddInteger(void)
{
  HashTable table;
  hashMapInit(&table, 10);
  //head & tail both is 1
  hashMapAddInteger(&table,(int *)1,123);
  TEST_ASSERT_EQUAL((table.list)[3].tail->data,1);
  TEST_ASSERT_EQUAL((table.list)[3].head->data,1);
  //head is 1 & tail is 3
  hashMapAddInteger(&table,(int *)2,123);
  hashMapAddInteger(&table,(int *)3,123);
  TEST_ASSERT_EQUAL((table.list)[3].head->data,1);
  TEST_ASSERT_EQUAL((table.list)[3].head->next->data,2);
  TEST_ASSERT_EQUAL((table.list)[3].tail->data,3);
  //head become 2 as removed 1 and tail is 1 as added 1
  hashMapAddInteger(&table,(int *)1,123);
  TEST_ASSERT_EQUAL((table.list)[3].head->data,2);
  TEST_ASSERT_EQUAL((table.list)[3].head->next->data,3);
  TEST_ASSERT_EQUAL((table.list)[3].tail->data,1);
}
