#include <iostream>
#include <string.h>
#include <cmath>
#include <ctime>

using namespace std;

char *con(char a[], char b[]);
void counter_str(char a[]);
void crypto(char a[]);
void upwords(char a[]);
void Odd_arr();

int main()
{
    char str1[20], str2[20];
    cout << "Enter str1: "; cin >> str1;
    cout << "Enter str2: "; cin >> str2;
    con(str1,str2);//конкатенация
    crypto(str1);//аля шифр
    upwords(str2);//перевод в верхний регистр
    Odd_arr();//вывод масива нечетных чисел в ранд порядке



return 0;
}


char *con(char a[], char b[])
{
    int n;
    char *str;


      n = strlen(a) + strlen(b);

      str = new char[n];

      for (int i = 0, j = 0; i < n + 1;i++)
      {
          if(a[i] != '\0')
          {
              str[i] = a[i];
          }
          else {
              str[i] = b[j];
              j++;
          }

      }
    return str;
}

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

void crypto(char a[])
{

    int n = strlen(a);
    int ch;
    char *m = new char[n];


    for(int i = 0; i < n; i++)
    {
        ch = a[i];
        if(ch + 6 > 122)
        {
            ch = ch + 5;
            ch = ch - 25;
            m[i] = ch;
        }
        else
        {
            m[i] = a[i] + 5;

        }
    }
cout << m;
}

void upwords(char a[])
{
    char out_str[10];
    int n = strlen(a);
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
   // cout << out_str;
}

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




