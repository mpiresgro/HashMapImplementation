#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <iostream>
#include <vector>

const int TABLE_SIZE = 10;

#include "node.h"
#include "hashFn.h"

template <class KType, class VType, class HashFn = DefaultHashFn>
class HashMap
{
public:
    HashMap();
    ~HashMap();

    void add(const KType &key, VType *value);
    bool get(const KType &key, VType &value);
    std::vector<KType> keys();
    std::vector<VType> values();
    bool remove(const KType &key);

private:
    HashFn hash_func;
    typedef HashNode<KType, VType *> Node;
    Node **hash_table;
};

template <class KType, class VType, class HashFn>
HashMap<KType, VType, HashFn>::HashMap()
{
    hash_table = new Node *[TABLE_SIZE]();
}

template <class KType, class VType, class HashFn>
HashMap<KType, VType, HashFn>::~HashMap()
{
    Node *prev;
    Node *node;
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

template <class KType, class VType, class HashFn>
void HashMap<KType, VType, HashFn>::add(const KType &key, VType *value)
{
    uint32_t hash_key = hash_func(key);

    Node *prev = NULL;
    Node *node = hash_table[hash_key];

    while (node != NULL && node->getKey() != key)
    {
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

template <class KType, class VType, class HashFn>
bool HashMap<KType, VType, HashFn>::get(const KType &key, VType &value)
{
    uint32_t hash_key = hash_func(key);

    Node *node = hash_table[hash_key];
    while (node != NULL && node->getKey() != key)
        node = node->getNext();

    if (node == NULL)
        return false;

    value = *node->getValue();
    return true;
}

template <class KType, class VType, class HashFn>
std::vector<KType> HashMap<KType, VType, HashFn>::keys()
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

template <class KType, class VType, class HashFn>
std::vector<VType> HashMap<KType, VType, HashFn>::values()
{
    std::vector<VType> out = {};
    Node *node;

    for (size_t idx = 0; idx < TABLE_SIZE; idx++)
    {
        node = hash_table[idx];
        while (node != NULL)
        {
            out.push_back(node->getValue());
            node = node->getNext();
        }
    }

    return out;
}

// return true if successful removal otherwise return false
template <class KType, class VType, class HashFn>
bool HashMap<KType, VType, HashFn>::remove(const KType &key)
{
    uint32_t hash_key = hash_func(key);

    Node *prev = NULL;
    Node *node = hash_table[hash_key];

    while (node != NULL && node->getKey() != key)
    {
        prev = node;
        node = node->getNext();
    }
    if (node == NULL)
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

#endif //_HASHMAP_H_