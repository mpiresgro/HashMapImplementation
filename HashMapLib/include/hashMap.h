#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <iostream>
#include <vector>
#include <assert.h>

const int TABLE_SIZE = 10;

#include "node.h"
#include "hashFn.h"

//  HashMap
//  C++ implementation of a HashMap
//  @tparam [KType] Key Type
//  @tparam [VType] Value Type
//  @tparam [HashFn] Hash function to use - defaults to DefaultHashFn
template <class KType, class VType, class HashFn = DefaultHashFn>
class HashMap
{
public:
    HashMap();
    ~HashMap();

    void add(const KType &key, VType *value);
    bool get(const KType &key, VType &value);
    std::vector<KType> keys() const;
    std::vector<VType> values() const;
    void clear();
    int size() const;
    bool remove(const KType &key);

private:
    HashFn hash_func;
    typedef HashNode<KType, VType *> Node;
    Node **hash_table;
    int m_size;
};

//  HashMap Constructor function
//  Allocates memory for hash_table and initializes m_size to zero
template <class KType, class VType, class HashFn>
HashMap<KType, VType, HashFn>::HashMap()
{
    hash_table = new Node *[TABLE_SIZE]();
    m_size = 0;
}

//  HashMap Destructor function
//  Clean and deallocate the memory that was previously reserved
//  for hash_table.
template <class KType, class VType, class HashFn>
HashMap<KType, VType, HashFn>::~HashMap()
{
    clear();
    delete[] hash_table;
}

//  add function - Add key and value entry.
//  Finds an empty bucket and adds node.
//  If node with same key already exists updates value.
//  @param [key] of type <KType>
//  @param [value] of type <VType>
template <class KType, class VType, class HashFn>
void HashMap<KType, VType, HashFn>::add(const KType &key, VType *value)
{
    uint32_t hash_key = hash_func(key);

    Node *prev = nullptr;
    Node *node = hash_table[hash_key];

    while (node != nullptr && node->getKey() != key)
    {
        prev = node;
        node = node->getNext();
    }

    if (node == nullptr)
    {
        // Create new node
        node = new Node(key, value);
        m_size++;
        if (prev == nullptr)
            hash_table[hash_key] = node;
        else
            prev->setNext(node);
    }
    else // Update value
        node->setValue(value);
}

//  get function - Get value from HashMap.
//  Finds bucket matching key and gets value
//  @return true if bucket exists otherwise returns false.
//  @param [key] of type <KType>
//  @param [value] of type <VType>
template <class KType, class VType, class HashFn>
bool HashMap<KType, VType, HashFn>::get(const KType &key, VType &value)
{
    uint32_t hash_key = hash_func(key);

    Node *node = hash_table[hash_key];
    while (node != nullptr && node->getKey() != key)
        node = node->getNext();

    if (node == nullptr)
        return false;

    value = *node->getValue();
    return true;
}

//  keys function
//  @return vector with all keys
template <class KType, class VType, class HashFn>
std::vector<KType> HashMap<KType, VType, HashFn>::keys() const
{
    std::vector<KType> out = {};
    Node *node = nullptr;

    for (size_t idx = 0; idx < TABLE_SIZE; idx++)
    {
        node = hash_table[idx];
        while (node != nullptr)
        {
            out.push_back(node->getKey());
            node = node->getNext();
        }
    }

    return out;
}

//  values function
//  @return vector with all values
template <class KType, class VType, class HashFn>
std::vector<VType> HashMap<KType, VType, HashFn>::values() const
{
    std::vector<VType> out = {};
    Node *node = nullptr;

    for (size_t idx = 0; idx < TABLE_SIZE; idx++)
    {
        node = hash_table[idx];
        while (node != nullptr)
        {
            out.push_back(node->getValue());
            node = node->getNext();
        }
    }

    return out;
}

//  clear function - Deletes all entries in HashMap
template <class KType, class VType, class HashFn>
void HashMap<KType, VType, HashFn>::clear()
{
    Node *prev = nullptr;
    Node *node = nullptr;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node = hash_table[i];
        while (node != nullptr)
        {
            prev = node;
            node = node->getNext();
            delete prev;
            m_size--;
        };
        delete node;
        hash_table[i] = nullptr;
    }

    assert(m_size == 0);
}

//  size function
//  @return number of entries in HashMap
template <class KType, class VType, class HashFn>
int HashMap<KType, VType, HashFn>::size() const
{
    return m_size;
}

//  remove function - Delete node from HashMap
//  @param [key] of type <KType>
//  @return true if node successfully removed otherwise return false
template <class KType, class VType, class HashFn>
bool HashMap<KType, VType, HashFn>::remove(const KType &key)
{
    uint32_t hash_key = hash_func(key);

    Node *prev = nullptr;
    Node *node = hash_table[hash_key];

    while (node != nullptr && node->getKey() != key)
    {
        prev = node;
        node = node->getNext();
    }
    if (node == nullptr)
    {
        return false;
    }
    else
    {
        if (prev == nullptr) 
        {
            hash_table[hash_key] = node->getNext();
        }
        else
        {
            prev->setNext(node->getNext());
        }
        m_size--;
        delete node;
        return true;
    }
}

#endif //_HASHMAP_H_