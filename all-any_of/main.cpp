#include <iostream>
#include <cassert>
#define ARR_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T))
{
    bool val;
    for(size_t i = 0; i < length; i++)
    {
        val = p(arr[i]);
        if(!val)
        {
            return val;;
        }
    }
    return val;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T))
{
    bool val;
    for(size_t i = 0; i < length; i++)
    {
        val = p(arr[i]);
        if(val)
        {
            return val;;
        }
    }
    return val;
}

bool isOdd( int integer )
{

  if ( integer % 2== 0 )
     return true;
  else
     return false;
}
bool isEven( int integer )
{

  if ( integer % 2== 0 )
     return false;
  else
     return true;
}


int main(int argc, char *argv[])
{

    int arr0[] = {3,3,3};//all of elem is even
    int arr1[] = {3,2,3};//any of elem is odd
    int arr2[] = {2,2,2};//all of elem is odd
    int arr3[] = {2,1,2};//any of elem is even

    assert(all_of(arr0, ARR_SIZE(arr0), isEven) == true);
    assert(any_of(arr0, ARR_SIZE(arr0), isEven) == true);
    assert(all_of(arr0, ARR_SIZE(arr0), isOdd) == false);
    assert(any_of(arr0, ARR_SIZE(arr0), isOdd) == false);
    cout << "Assert for arr0 successful!" << endl;

    assert(all_of(arr1, ARR_SIZE(arr1), isEven) == false);
    assert(any_of(arr1, ARR_SIZE(arr1), isEven) == true);
    assert(all_of(arr1, ARR_SIZE(arr1), isOdd) == false);
    assert(any_of(arr1, ARR_SIZE(arr1), isOdd) == true);
    cout << "Assert for arr1 successful!" << endl;

    assert(all_of(arr2, ARR_SIZE(arr2), isEven) == false);
    assert(any_of(arr2, ARR_SIZE(arr2), isEven) == false);
    assert(all_of(arr2, ARR_SIZE(arr2), isOdd) == true);
    assert(any_of(arr2, ARR_SIZE(arr2), isOdd) == true);
    cout << "Assert for arr2 successful!" << endl;

    assert(all_of(arr3, ARR_SIZE(arr3), isEven) == false);
    assert(any_of(arr3, ARR_SIZE(arr3), isEven) == true);
    assert(all_of(arr3, ARR_SIZE(arr3), isOdd) == false);
    assert(any_of(arr3, ARR_SIZE(arr3), isOdd) == true);
    cout << "Assert for arr3 successful!" << endl;




    cout << all_of(arr0, ARR_SIZE(arr0), isEven) << endl;
    cout << any_of(arr0, ARR_SIZE(arr0), isOdd) << endl;

    cout << all_of(arr1, ARR_SIZE(arr1), isEven) << endl;;
    cout << any_of(arr1, ARR_SIZE(arr1), isOdd) << endl;

    cout << all_of(arr2, ARR_SIZE(arr2), isEven) << endl;;
    cout << any_of(arr2, ARR_SIZE(arr2), isOdd) << endl;

    cout << all_of(arr3, ARR_SIZE(arr3), isEven) << endl;;
    cout << any_of(arr3, ARR_SIZE(arr3), isOdd) << endl;


    return 0;
}
