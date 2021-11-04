

class HashFnBase
{
public:
    virtual uint32_t operator()(const std::string &key) = 0;
    virtual uint32_t operator()(const int &key) = 0;
};

class DefaultHashFn : public HashFnBase
{
public:
    uint32_t operator()(const std::string &key)
    {
        uint32_t sum = 0;
        for (uint32_t i = 0; i < key.size(); i++)
            sum += key[i];

        return sum % TABLE_SIZE;
    }

    uint32_t operator()(const int &key)
    {
        return key % TABLE_SIZE;
    }
};