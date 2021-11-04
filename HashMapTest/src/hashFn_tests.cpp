#include <gtest/gtest.h>
#include "hashMap.h"

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

TEST(HashMapHashFn, custom_hashFn)
{
    HashMap<int, std::string, CustomHashFn> hashmap;
}

TEST(HashMapHashFn, int_key)
{

    HashMap<int, std::string> hashmap;

    int key = 123;
    std::string value = "Value";

    hashmap.add(key, &value);

    std::string expected;

    bool result = hashmap.get(key, expected);

    ASSERT_EQ(expected, "Value");
    ASSERT_EQ(result, true);
}

TEST(HashMapHashFn, string_key)
{

    HashMap<std::string, std::string> hashmap;

    std::string key = "Key";
    std::string value = "Value";

    hashmap.add(key, &value);

    std::string expected;

    bool result = hashmap.get(key, expected);

    ASSERT_EQ(expected, "Value");
    ASSERT_EQ(result, true);
}