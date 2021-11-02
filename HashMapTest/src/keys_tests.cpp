#include <gtest/gtest.h>
#include <algorithm>
#include "hashMap.h"

TEST(HashMaKeys, get_keys)
{
    HashMap hashMap;

    Person p1 = {.name = "p1", .age = 23};
    Person p2 = {.name = "p2", .age = 12};
    Person p3 = {.name = "p3", .age = 32};
    Person p4 = {.name = "p4", .age = 92};
    Person p5 = {.name = "p5", .age = 62};
    
    std::vector<Person> people = {p1, p2, p3, p4, p5};
    for (size_t i = 0; i < people.size(); i++)
    {
        hashMap.add(people[i].name, &people[i]);
    }

    std::vector<std::string> result = hashMap.keys();
    bool elementFound = false;
    
    // find each key in result vector 
    for (auto str : result)
    {
        elementFound = (std::find(result.begin(), result.end(), str) != result.end());
        ASSERT_EQ(elementFound, true);
    }
}

TEST(HashMaKeys, get_empyt_keys)
{
    HashMap hashMap;

    std::vector<std::string> result = hashMap.keys();
    
    ASSERT_EQ(result.size(), 0);
}
