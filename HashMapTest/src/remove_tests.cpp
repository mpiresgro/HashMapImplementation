#include <gtest/gtest.h>
#include "hashMap.h"
#include "struct_types.cpp"

class HashMapRemove : public ::testing::Test
{
public:
    void SetUp() override
    {
        hash.add(value1.name, &value1);
        hash.add(value2.name, &value2);
        hash.add(value3.name, &value3);
    }

    HashMap<std::string, Person> hash;
    Person value1 = {.name = "John", .age = 28};
    Person value2 = {.name = "Feaocn", .age = 12};
    Person value3 = {.name = "Louia", .age = 54};
};

TEST_F(HashMapRemove, remove_one_entry)
{
    bool result = hash.remove(value1.name);

    int size = hash.size();

    ASSERT_EQ(result, true);
    ASSERT_EQ(size, 2);
}

TEST_F(HashMapRemove, remove_all_entry)
{
    bool result1 = hash.remove(value1.name);
    bool result2 = hash.remove(value2.name);
    bool result3 = hash.remove(value3.name);

    int size = hash.size();

    ASSERT_EQ(result1, true);
    ASSERT_EQ(result2, true);
    ASSERT_EQ(result3, true);
    ASSERT_EQ(size, 0);
}

TEST_F(HashMapRemove, remove_non_existent_entry)
{
    bool result = hash.remove("Non existing key");
    ASSERT_EQ(result, false);
}