#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <iostream>
#include <vector>

#include "node.h"
#include "struct_types.h"

const int TABLE_SIZE = 10;
typedef HashNode<std::string, Person*> Node;

template<class KType, class VType>
class HashMap
{
public:

    HashMap();
    ~HashMap();

    void print();
    void add(const KType& key, VType* value);
    bool get(const KType& key, VType& value);
    std::vector<KType> keys();
    bool remove(const KType& key);

private:
    uint32_t hash_func(const KType& key) const;
    Node **hash_table;
};


template<class KType, class VType>
uint32_t HashMap<KType, VType>::hash_func(const KType &key) const
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < key.size(); i++)
        sum += key[i];
    
    return sum % TABLE_SIZE;
}

template<class KType, class VType>
HashMap<KType, VType>::HashMap()
{
    hash_table = new Node* [TABLE_SIZE]();
}

template<class KType, class VType>
HashMap<KType, VType>::~HashMap()
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

template<class KType, class VType>
void HashMap<KType, VType>::print()
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

template<class KType, class VType>
void HashMap<KType, VType>::add(const KType& key, VType* value)
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

template<class KType, class VType>
bool HashMap<KType, VType>::get(const KType& key, VType& value)
{
    uint32_t hash_key = hash_func(key);
    
    Node *node = hash_table[hash_key];
    while(node != NULL && node->getKey() != key)
        node = node->getNext();
    
    if (node  == NULL) 
        return false;

    value = *node->getValue();
    return true;
}

template<class KType, class VType>
std::vector<KType> HashMap<KType, VType>::keys()
{
    std::vector<KType> out = {};
    Node *node;

    for (size_t idx = 0; idx < TABLE_SIZE; idx++)
    {
        node = hash_table[idx];
        while (node != NULL)
        {
            out.push_back(node->getKey());
            node = node->getNext();
        }
    }

    return out;
}

// return true if successful removal otherwise return false
template<class KType, class VType>
bool HashMap<KType, VType>::remove(const KType &key)
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

#endif