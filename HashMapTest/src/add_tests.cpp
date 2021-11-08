#include <gtest/gtest.h>
#include "hashMap.h"
#include "struct_types.cpp"

// Custom HashFn class to test a different HashFn
class CustomHashFn : public HashFnBase
{
public:
    uint32_t operator()(const std::string &)
    {
        return 1;
    }

    uint32_t operator()(const int &)
    {
        return 1;
    }
};


class HashMapAdd : public ::testing::Test {
public:
    HashMap<std::string, Person> hash;
    Person value1 = {.name = "John", .age = 28};
    Person value2 = {.name = "Feaocn", .age = 12};
    Person value3 = {.name = "Louia", .age = 54};
};


TEST_F(HashMapAdd, test_add_one)
{
    hash.add(value1.name, &value1);

    Person expected;
    
    bool result = hash.get(value1.name, expected);

    ASSERT_EQ(expected.name, "John");
    ASSERT_EQ(expected.age, 28);
    ASSERT_EQ(result, true);
}



TEST_F(HashMapAdd, test_add_many)
{
    hash.add(value1.name, &value1);
    hash.add(value2.name, &value2);
    hash.add(value3.name, &value3);

    Person expected1, expected2, expected3;
    
    bool result1 = hash.get(value1.name, expected1);
    bool result2 = hash.get(value2.name, expected2);
    bool result3 = hash.get(value3.name, expected3);

    ASSERT_EQ(expected1.name, value1.name);
    ASSERT_EQ(expected1.age, value1.age);
    ASSERT_EQ(result1, true);

    ASSERT_EQ(expected2.name, value2.name);
    ASSERT_EQ(expected2.age, value2.age);
    ASSERT_EQ(result2, true);
    
    ASSERT_EQ(expected3.name, value3.name);
    ASSERT_EQ(expected3.age, value3.age);
    ASSERT_EQ(result3, true);
}


TEST_F(HashMapAdd, test_add_many_in_same_node)
{
    HashMap<std::string, Person, CustomHashFn> custom_hash;

    custom_hash.add(value1.name, &value1);
    custom_hash.add(value2.name, &value2);
    custom_hash.add(value3.name, &value3);

    Person expected1, expected2, expected3;
    
    bool result1 = custom_hash.get(value1.name, expected1);
    bool result2 = custom_hash.get(value2.name, expected2);
    bool result3 = custom_hash.get(value3.name, expected3);

    ASSERT_EQ(expected1.name, value1.name);
    ASSERT_EQ(expected1.age, value1.age);
    ASSERT_EQ(result1, true);

    ASSERT_EQ(expected2.name, value2.name);
    ASSERT_EQ(expected2.age, value2.age);
    ASSERT_EQ(result2, true);
    
    ASSERT_EQ(expected3.name, value3.name);
    ASSERT_EQ(expected3.age, value3.age);
    ASSERT_EQ(result3, true);
}