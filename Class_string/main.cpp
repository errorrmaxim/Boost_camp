#include <iostream>
#include <string.h>
#include <cassert>
#include <thread>

using namespace std;

class MyString
{
    private:
        int length;
        char *str;

    public:
        MyString ()
        {
            length = 1;
            str = '\0';
        }
        MyString (const char *c)
        {
            from_c_str (c);
        }
        MyString (const MyString& t)
        {
            from_c_str (t.str);
        }
        ~MyString ()
        {
            delete[] str;
        }

        MyString& operator= (const MyString& t)
        {
            from_c_str (t.str);

            return *this;
        }
        MyString& operator= (const char *c)
        {
            from_c_str (c);

            return *this;
        }

        MyString operator+ (const MyString& t) const
        {
            return (MyString(str) += t.str);
        }
        MyString& operator+= (const MyString& t)
        {
            length = strlen (str) + strlen (t.str) + 1;
            char *newStr = new char[length];
            strcpy (newStr, str);
            strcat (newStr, t.str);
            delete[] str;
            str = new char[length];
            strcpy (str, newStr);
            str[length-1] = '\0';
            delete[] newStr;

            return *this;
        }

        void from_c_str (const char *c)
        {
            length = strlen (c) + 1;
            str = new char[length];
            strcpy (str, c);
        }

        friend std::ostream& operator<< (std::ostream& out, const MyString& t)
        {
            out << t.str;
            return out;
        }

};


int main(int argc, char *argv[])
{
    MyString lol1, lol2;

    lol1 = "kek";
    lol2 = lol1;
    lol2 += "kekkek";
    cout << lol2 << endl;


    string m = "asd";
    string n;
    n = m;


    cout << "m: " << &m << endl;
    cout << "n: " << &n << endl;

    return 0;
}





















