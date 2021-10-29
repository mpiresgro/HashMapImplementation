

template <class K, class V>
class HashNode
{
public:
    HashNode(K key, V value) : m_key(key), m_value(value), m_next(NULL)
    {
    }

    V getValue()
    {
        return m_value;
    }

    
private:
    K m_key;
    V m_value;
    HashNode<K, V> *m_next;
};
