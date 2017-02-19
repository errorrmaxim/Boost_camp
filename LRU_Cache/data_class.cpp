#include "data_class.h"

Data_class::Data_class():count_of_used(0)
{

}

Data_class::Data_class(std::string data):some_data(data)
{

}

Data_class::~Data_class()
{

}

std::ostream& operator <<(std::ostream& os, Data_class& obj)
{
    os << obj.some_data;
    return os;
}
bool Data_class::operator ==(const Data_class& rhs)
{
           return some_data == rhs.some_data;
}
