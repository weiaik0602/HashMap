#include "unity.h"
#include "HashMap.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_HashMap_NeedToImplement(void)
{
  HashTable table;
  hashMapInit(&table, 10);
  _hashMapAdd(&table,2,2);
  //TEST_ASSERT_EQUAL(table.list[2].data,2);
}
