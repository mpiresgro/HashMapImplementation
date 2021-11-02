#include <iostream>
#include "hashMap.h"

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
    hash_table = new Node* [TABLE_SIZE]();
}

HashMap::~HashMap()
{
    Node* prev;
    Node* node;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node = hash_table[i];
        while (node != NULL)
        {
            prev = node;
            node = node->getNext();
            delete prev;
        };
        delete node;
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
            Node* nodeV = hash_table[i];
            Person* value = nodeV->getValue();
            std::cout << "\t" <<  i << "\t" << value->name;
        }
    }
    std::cout << "END" << std::endl;
}

void HashMap::add(const std::string &key, Person* value)
{
    uint32_t hash_key = hash_func(key);
    
    Node *prev = NULL;
    Node *node = hash_table[hash_key];

    while (node != NULL && node->getKey() != key) {
        prev = node;
        node = node->getNext();
    }

    if (node == NULL)
    {
        // Create new node
        node = new Node(key, value);
        
        if (prev == NULL)
            hash_table[hash_key] = node;
        else 
            prev->setNext(node);
    }
    else // Update value
        node->setValue(value);

}

bool HashMap::get(const std::string& key, Person& value)
{
    uint32_t hash_key = hash_func(key);
    
    Node *prev = NULL;
    Node *node = hash_table[hash_key];
    while(node != NULL && node->getKey() != key)
    {
        prev = node;
        node = node->getNext();
    }
    
    if (node  == NULL) 
        return false;

    value = *node->getValue();
    return true;
}

// return true if successful removal otherwise return false
bool HashMap::remove(const std::string &key)
{
    uint32_t hash_key = hash_func(key);

    Node *prev = NULL;
    Node *node = hash_table[hash_key];
    
    while(node != NULL && node->getKey() != key)
    {
        prev = node;
        node = node->getNext();
    }
    if (node  == NULL) 
    {
        return false;
    }
    else 
    {
        if (node->getNext() != NULL)
        {
            prev->setNext(node->getNext());
        }
        node = NULL;
        return true;
    }
    return false;
}
