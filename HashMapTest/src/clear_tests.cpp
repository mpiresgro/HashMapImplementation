#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapClear, clear_one)
{
    HashMap<int, std::string> hashmap;

    int key = 123;
    std::string value = "Value";

    hashmap.add(key, &value);

    int size = hashmap.size();

    ASSERT_EQ(size, 0);
}

TEST(HashMapClear, clear_zero)
{
    HashMap<int, std::string> hashmap;

    int key = 123;
    std::string value = "Value";

    hashmap.add(key, &value);

    int size = hashmap.size();

    ASSERT_EQ(size, 0);
}

TEST(HashMapClear, clear_many_dup_key)
{
    HashMap<int, std::string> hashmap;

    int key1 = 123;
    int key2 = 123;
    int key3 = 345;

    std::string value = "Value";

    hashmap.add(key1, &value);
    hashmap.add(key2, &value); // duplicated entry
    hashmap.add(key3, &value);

    int size = hashmap.size();

    ASSERT_EQ(size, 0);
}

TEST(HashMapClear, clear_many_key)
{
    HashMap<int, std::string> hashmap;

    int key1 = 123;
    int key2 = 456;
    int key3 = 789;

    std::string value = "Value";

    hashmap.add(key1, &value);
    hashmap.add(key2, &value);
    hashmap.add(key3, &value);

    int size = hashmap.size();

    ASSERT_EQ(size, 0);
}