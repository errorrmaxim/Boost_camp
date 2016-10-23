#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

//concotenation Task #7
char *con(char a[], char b[]);

//count repeater of char Task #8
void counter_str(char a[]);

//to up first signs in words Tsak #10
void upwords(char a[]);

//delete fist sings in words Task #11
void word_del(char a[]);

//odd array random Task #13
void Odd_arr();

//password gen Task #14
char* pass_gen();

int main()
{
    /////Task #7 //////
   char str1[] = "qwerty";
   char str2[] = "ytrewq";
   cout << con(str1, str2) << endl;
   cout << "==============" << endl;

   /////Task #8 ///////
   counter_str("introducing");
   cout << "==============" << endl;

   /////Task #10 /////
   upwords("qwe rty uio");
   cout << endl << "==============" << endl;

   /////Task #11 /////
   word_del("qwe rty uio");
   cout << endl << "==============" << endl;

   /////Task #13 /////
   Odd_arr();
   cout << endl << "==============" << endl;

   /////Task #14 /////
   cout << pass_gen();
   cout << "==============" << endl;

   return 0;
}

//Task #7
char *con(char a[], char b[])
{
    int n;
    char *str;


      n = strlen(a) + strlen(b);

      str = new char[n];

      strcpy(str, a);
      strcat(str,b= b);

    return str;
}

//Task #8
void counter_str(char a[])
{
    int counter = 0, n = strlen(a);

    char *second = new char[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n;j++)
        {
            if(a[i] == a[j])
            {
                counter++;
            }
        }
        cout << a[i] << ' ' << counter << endl;
        counter = 0;

    }
}

//Task #10
void upwords(char a[])
{

   const int n = strlen(a);
   char out_str[n];
    bool flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(isalpha(a[i]) && flag == 0)
        {
            out_str[i] = toupper(a[i]);
            cout << out_str[i];
            flag = 1;
            continue;
        }
        if(!isalpha(a[i]))
        {
            flag = 0;
            out_str[i] = a[i];
            cout << out_str[i];
        }
        else {
            out_str[i] = a[i];
            cout << out_str[i];
        }


    }
}

//Task #11
void word_del(char a[])
{

   const int n = strlen(a);
   char out_str[n];
    bool flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(isalpha(a[i]) && flag == 0)
        {
            out_str[i] = 0;
            cout << out_str[i];
            flag = 1;
            continue;
        }
        if(!isalpha(a[i]))
        {
            flag = 0;
            out_str[i] = a[i];
            cout << out_str[i];
        }
        else {
            out_str[i] = a[i];
            cout << out_str[i];
        }


    }
}

//Task #13
void Odd_arr()
{
    srand(time(0));
    int odd[50],n1,n2;
   for(int i = 1, j = 0; i < 100;i++)
   {
      if(i & 1)
      {
          odd[j] = i;
          cout << odd[j] << ' ';
          j++;

      }
   }

        for ( int i =0 ; i < 50;i++)
        {

              n1 = rand() % 50;
              n2 = rand() % 50;
              swap(odd[n1], odd[n2]);

        }
        cout << endl;
        for(int i = 0; i < 50 ; i++)
        {
            cout << odd[i] << '-';
        }
}

//Task #14
char* pass_gen()
{
    char *pas;
    pas = new char[8];
    int answ,counter = 0, counter2 = 0;
    bool flag = 0;
    srand(time(0));
    for(int i = 0; i < 8; i++)
    {
        answ = rand() % 4;
        if(answ == 0 || answ == 1 && counter2 > 3)
        {
            pas[i] = rand() % 26 + 97;
        }else if(answ == 1 || answ == 3 && flag == 1 && counter < 4)
        {
            pas[i] = rand() % 26 + 65;
            counter2++;
        }else  if(answ == 2 || answ == 3 && flag == 1)
        {
            pas[i] = rand() % 10 + 48;
            counter++;
        }else if(answ == 3 && flag == 0 && i > 0 && i < 8){
            pas[i] = '_';
            flag = 1;
        }
    }
   return pas;
}
