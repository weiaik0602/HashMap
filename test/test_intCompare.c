#include "unity.h"
#include "intCompare.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_intCompare_NeedToImplement(void)
{
    int x=integerCompare(8,9);
    int y=integerCompare(9,8);
    int z=integerCompare(8,8);
    TEST_ASSERT_EQUAL(x,-1);
    TEST_ASSERT_EQUAL(y,1);
    TEST_ASSERT_EQUAL(z,0);
}
