#ifndef DATA_CLASS_H
#define DATA_CLASS_H
#include <cstring>
#include <iostream>

class Data_class
{
    std::string some_data;
    int count_of_used;
public:
    Data_class();
    Data_class(std::string);
    ~Data_class();
    friend std::ostream& operator <<(std::ostream& os, Data_class& obj);
    friend class LRU_Cache;
    bool operator ==(const Data_class& rhs);
};

#endif // DATA_CLASS_H
