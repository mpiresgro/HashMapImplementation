#include <gtest/gtest.h>

#include "hashMap.h"

class HashMapAdd : public ::testing::Test {
public:
    HashMap<std::string, Person> hash;
    Person value = {.name = "John", .age = 28};
};


TEST_F(HashMapAdd, test_add_one)
{
    hash.add(value.name, &value);

    Person expected;
    
    bool result = hash.get(value.name, expected);

    ASSERT_EQ(expected.name, "John");
    ASSERT_EQ(expected.age, 28);
    ASSERT_EQ(result, true);
}