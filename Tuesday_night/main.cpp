#include <iostream>
using namespace std;

class FuckOff
{
private:
    float value;
public:
    FuckOff(): value(0)
    {}
    FuckOff(float i): value(i)
    {}
    float get_val()
    {
        return value;
    }


    friend FuckOff& operator*=(FuckOff& left, const FuckOff& right)
    {
        left.value *= right.value;
        return left;
    }

    friend FuckOff& operator/=(FuckOff& left, const FuckOff& right)
    {
           left.value /= right.value;
           return left;
    }

    friend FuckOff& operator+=(FuckOff& left, const FuckOff& right)
    {
        left.value += right.value;
        return left;
    }

    friend FuckOff& operator-=(FuckOff& left, const FuckOff& right)
    {
        left.value -= right.value;
        return left;
    }

     friend FuckOff& operator++(FuckOff& i)
     {
        i.value++;
        return i;
     }


     friend FuckOff operator++(FuckOff& i, int)
     {
        FuckOff oldValue(i.value);
        i.value++;
        return oldValue;
      }
     FuckOff& operator=(const int i)
        {
            value = i;
            return *this;
        }
};



int main(int argc, char *argv[])
{

   FuckOff c1;
   FuckOff c2;
    c1 = 20;
    cout << c1.get_val() << endl;
    c1 /= 12.0;
    cout << c2.get_val() << endl;

    cout << c1.get_val() << endl;
 return 0;
}
