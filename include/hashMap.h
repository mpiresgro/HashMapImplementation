#include <iostream>
#include "node.h"
#include "struct_types.h"

const int TABLE_SIZE = 10;
typedef HashNode<std::string, std::string> Node;

class HashMap
{
public:
    void print() ;
    void add(const std::string& key, const std::string& value);
    bool remove(const std::string& key);

private:
    uint32_t hash_func(const std::string& key) const;
    Node *hash_table[TABLE_SIZE] = {};
};
