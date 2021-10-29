#include <iostream>
#include "HashMap.h"

uint32_t HashMap::hash_func(const std::string &key) const
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < key.size(); i++)
    {
        sum += key[i];
    }
    
    return sum % TABLE_SIZE;
}

HashMap::HashMap()
{
    hash_table = new Node* [TABLE_SIZE];
}

HashMap::~HashMap()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    delete[] hash_table;
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
            Person* value = hash_table[i]->getValue();
            std::cout << "\t" <<  i << "\t" << value->name << std::endl;
        }
    }
    std::cout << "END" << std::endl;
}

void HashMap::add(const std::string &key, Person* value)
{
    uint32_t hash_key = hash_func(key);
    
    Node* node = hash_table[hash_key];

    if (node != NULL)
    {
        std::cout << "\t >> Colision \n";
    } 
    else 
    {
        node = new Node (key, value);
        hash_table[hash_key] = node;
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
