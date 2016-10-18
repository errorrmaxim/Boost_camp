#include <iostream>
#include <string.h>
#include <cmath>
#include <ctime>

using namespace std;


struct student{
    char name[20];
    unsigned short  age;
    float pga;
};

//concotenation
char *con(char a[], char b[]);
//count repeater of char
void counter_str(char a[]);
//cryptography
void crypto(char a[]);
//to up first signs in words
void upwords(char a[]);
//odd array random
void Odd_arr();
//delete fist sings in words
void word_del(char a[]);
//password gen
char* pass_gen();

void odd_swaper();

void multipl_matrix();

int main()
{
    int N;
    float mid_val_pga = 0,counter = 0;
//               char str1[20], str2[20];
//               cout << "Enter str1: "; gets(str1);
//               cout << "Enter str2: "; gets(str2);
//               con(str1,str2);
//               crypto(str1);
//               upwords(str1);
//               Odd_arr();
//               word_del(str1);
//               cout << pass_gen() << endl;
//  НЕРАБОТАЕТ   odd_swaper(); ///
//               multipl_matrix();

    student *group, bedstudent, goodstudent;

    cout << "Enter count of students: ";
    cin >> N;
    group = new student[N];
    for(int i = 0; i < N; i++)
    {
        cout << "Enter the name for " << i + 1 << " student: ";
        cin >> group[i].name;
        cout << "Enter age of " << i + 1 << " student: ";
        cin >> group[i].age;
        cout << "Enter pga of " << i + 1 << " student: ";
        cin >> group[i].pga;

    }

    for(int i = 0; i < N; i++)
    {
      if(group[i].pga > group[i + 1].pga)
      {
          goodstudent = group[i];
      }
      if (group[i].pga < group[i + 1].pga)
      {

          bedstudent = group[i];

      }
      counter += group[i].pga;
      mid_val_pga = counter / N;
    }

    system("clear");
    cout << "Bed student: " << endl;
    cout << bedstudent.name << endl << bedstudent.age << endl << bedstudent.pga << endl;
    cout << "Good student: " << endl;
    cout << goodstudent.name << endl << goodstudent.age << endl << goodstudent.pga << endl;
    cout << "Midle pga of group: " << mid_val_pga << endl;



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
   // cout << out_str;
}

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

void odd_swaper()
{
    int *line;
    line = new int[12];
    int flag = 0;
    for(int i = 0; i < 12; i++)
    {
        if(flag < 2)
        {
            cout << "lol";
            flag++;
        }
    }

}

void multipl_matrix()
{
    int **matrix1, x1, y1;
    int **matrix2, x2, y2;
    int **matrix_out, n;

    cout << "Enter the size of first matrix: " << endl << "x: ";
    cin >> x1;
    cout << "y: "; cin >> y1;
    cout << "Enterthe size of second matrix: " << endl << "x: ";
    cin >> x2;
    cout << "y: ";
    cin >> y2;

    matrix1 = new int*[x1];
    for(int i = 0;i < x1; i++)
    {
        matrix1[i] = new int[y1];
    }

    matrix2 = new int *[x2];
    for(int i = 0; i < x2; i++)
    {
        matrix2[i] = new int[y2];
    }

    if(y1 != x2)
    {
        cout << "Those matrixs cant be multiple!";
        for(int i = 0; i < x1; i++)
        {
            delete []matrix1[i];

        }
        for(int i = 0; i < x2; i++)
        {
            delete []matrix2[i];
        }//////////////////////////////////////////////////////////
    }else {
        cout << "Enter elements of matrix 1: " << endl;
        for(int i = 0; i < x1; i++)
        {
            for(int j = 0; j < y1; j++)
            {
               cin >> matrix1[i][j];
            }
        }
        system("clear");
        cout << "Enter elements of matrix 2: " << endl;
        for(int i = 0; i < x1; i++)
        {
            for(int j = 0; j < y1; j++)
            {
               cin >> matrix2[i][j];
            }
        }
        matrix_out = new int*[x1];
        for(int i = 0; i < x1; i++)
        {
            matrix_out[i] = new int[y2];
        }

        for(int i = 0; i < x1; i++)
        {
            for(int j = 0; j < y2; j++)
            {
                matrix_out[i][j] = 0;
            }
        }

        for(int i = 0; i < x1; i++)
        {
            for(int j = 0; j < y2; j++)
            {
                for(int m = 0; m < x1; m++)
                {
                    matrix_out[i][j] += matrix1[i][m] * matrix2[j][m];

                }

            }
        }
        for(int i = 0; i < x1; i++)
        {
            for(int j = 0; j < y2; j++)
            {
                cout << matrix_out[i][j] << ' ';
            }
            cout << endl;
        }
}
}
