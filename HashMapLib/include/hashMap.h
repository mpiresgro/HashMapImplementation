#include "node.h"
#include "struct_types.h"

const int TABLE_SIZE = 10;
typedef HashNode<std::string, Person*> Node;

class HashMap
{
public:

    HashMap();
    ~HashMap();

    void print() ;
    void add(const std::string& key, Person* value);
    bool get(const std::string& key, Person& value);
    bool remove(const std::string& key);

private:
    uint32_t hash_func(const std::string& key) const;
    Node **hash_table;
};
