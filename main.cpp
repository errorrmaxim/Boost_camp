#include <iostream>
#include <string.h>
#include <cassert>


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
    MyString lol;

    lol = "kek";
    lol += lol;

    cout << lol << endl;


    return 0;
}
