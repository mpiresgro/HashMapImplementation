

template <class K, class V>
class HashNode
{
public:
    HashNode(K key, V value) : m_key(key), m_value(value), m_next(NULL)
    {
    }
    
    V getValue() const
    {
        return m_value;
    }

    K getKey() const
    {
        return m_key;
    }

    HashNode<K, V>* getNext()
    {
        return m_next;
    }

    void setNext(HashNode<K, V>* next)
    {
        m_next = next;
    }
    
    void setValue(const V& value)
    {
        m_value = value;
    }

private:
    K m_key;
    V m_value;
    HashNode<K, V> *m_next;
};
