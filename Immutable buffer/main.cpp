#include <iostream>
#include <vector>
#include <cassert>
#define ARR_SIZE(arr)(sizeof(arr)/sizeof(arr[0]))

using namespace std;

template <typename T>
class ImmutableBuffer
{
private:

    const vector<T>buff_const;

public:
       ImmutableBuffer()   {}

       ImmutableBuffer(T *val, int size_arr): buff_const(make_vector(val,size_arr))  {}

       vector<T>make_vector(T *val, int size)                      // function for make vector
        {
            vector<T>buffer_maker;
            for(int i = 0; i < size; i++)
            {
                buffer_maker.insert(buffer_maker.end(), val[i]);
            }
            return buffer_maker;                                    // we are returning vector
        }

       friend ostream& operator <<(ostream& os, const ImmutableBuffer& buf)
        {
            for(int i = 0; i < buf.buff_const.size(); i++)
            {
                os << buf.buff_const[i] << ' ';

            }
            return os;
        }
       const T &operator [](int t)
       {
           return buff_const[t];
       }
       friend bool operator ==(const ImmutableBuffer& right, const ImmutableBuffer& left)
       {
          return right.buff_const == left.buff_const;
       }
       friend bool operator !=(const ImmutableBuffer& right, const ImmutableBuffer& left)
       {
           return !(right.buff_const == left.buff_const);
       }

       ImmutableBuffer& operator =(const ImmutableBuffer& right) = delete;

};


int main(int argc, char *argv[])
{

    double arr[] = {1.0, 232.9, 111.1};
    double arr2[] = {2.32, 2.22, 3232.11};

        ImmutableBuffer<double> buff(arr, ARR_SIZE(arr));
        ImmutableBuffer<double> buff2 = buff;
        ImmutableBuffer<double> buff3(arr2,ARR_SIZE(arr2));
        arr[0] = 0;

        assert(buff[0] == 1.0);
        assert(buff == buff2);
       //buff[0] = 42.0;       //failed of compilation
       //buff = buff3;         //failed of compilation

        cout << buff3 << endl;
        cout << buff << endl;
       // assert(buff[1] == 3.0); //failed


        return 0;
}

