#include <gtest/gtest.h>
#include "hashMap.h"

class HashMapGet : public ::testing::Test {
public:
    HashMap hash;
    Person value = {.name = "John", .age = 28};
};

TEST_F(HashMapGet, get_existing_value)
{
    hash.add(value.name, &value);
    Person expected; 

    bool result = hash.get(value.name, expected);
    
    ASSERT_EQ(expected.name, "John");
    ASSERT_EQ(expected.age, 28);
    ASSERT_EQ(result, true);
}


TEST_F(HashMapGet, get_not_existing_value)
{
    Person expected; 
    bool result = hash.get(value.name, expected);
    
    ASSERT_EQ(result, false);
}