#include <iostream>
#include <tuple>

template <typename K, typename V, size_t N>
class Map
{
private:
    std::tuple<K, V>* data;
    size_t size;

public:
    Map() : data(new std::tuple<K, V>[N]), size(0) {}

    ~Map()
    {
        delete[] data;
    }

    void Set(const K& key, const V& value)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (std::get<0>(data[i]) == key)
            {
                std::get<1>(data[i]) = value;
                return;
            }
        }
        data[size++] = std::make_tuple(key, value);
    }

    bool Get(const K& key, V& value)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (std::get<0>(data[i]) == key)
            {
                value = std::get<1>(data[i]);
                return true;
            }
        }
        return false;
    }

    size_t Count()
    {
        return size;
    }

    void Clear()
    {
        size = 0;
    }

    bool Delete(const K& key)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (std::get<0>(data[i]) == key)
            {
                size--;
                data[i] = data[size];
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& oth)
    {
        for (size_t i = 0; i < oth.size; i++)
        {
            bool find = false;
            for (size_t j = 0; j < size; j++)
            {
                if (std::get<0>(oth.data[i]) == std::get<0>(data[j]))
                {
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                return false;
            }
        }
        return true;
    }

    V& operator[](const K& key)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (std::get<0>(data[i]) == key)
            {
                return std::get<1>(data[i]);
            }
        }
        data[size] = std::make_tuple(key, V());
        size++;
        return std::get<1>(data[size - 1]);
    }

    const std::tuple<K, V>* begin()
    {
        return data;
    }

    const std::tuple<K, V>* end()
    {
        return data + size;
    }
};

int main()

{

    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    m[20] = "result";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    return 0;

}