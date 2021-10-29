#include <iostream>
#include "HashMap.h"

uint32_t HashMap::hash_func(const std::string &key) const
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < key.size(); i++)
    {
        sum += key[i];
    }
    std::cout << "HASH RES > " <<sum % TABLE_SIZE << std::endl; 
    return sum % TABLE_SIZE;
}

void HashMap::print()
{
    std::cout << "START " << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            std::cout << "\t" <<  i << "\t------------" << std::endl;
        }
        else
        {
            Node n = *hash_table[i];
            std::cout << "\t" <<  i << "\t" << n.getValue() << std::endl;
        }
    }
    std::cout << "END" << std::endl;
}

void HashMap::add(const std::string &key, const std::string &value)
{
    uint32_t hash_key = hash_func(key);

    if (hash_table[hash_key] != NULL)
    {
        std::cout << "\t >> Colision \n";
    } 
    else 
    {
        Node n (key, value);
        hash_table[hash_key] = &n;
    }
}

// return true if successful removal otherwise return false
bool HashMap::remove(const std::string &key)
{
    uint32_t hash_key = hash_func(key);
    if (hash_table[hash_key] != NULL)
    {
        hash_table[hash_key] = NULL;
        return true;
    }
    else
    {
        return false;
    }
}
