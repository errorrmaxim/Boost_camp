#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;
int const N = 5;
int const M = 3;
//determ of matrix (size 3x3) Task #16
int determ();

//mutiple of matrix Task #17
int matrix_multiple();

//strucrs of students & professors Tasks #18
struct person
{
    char name[30];
    unsigned short age;};
struct professor
{
    person base;
    unsigned short salary;
};
struct student
{
    person base;
    professor head;
    float pga;
};
void student_init(student *m, professor *k, int N);
void print_student(student *m, int N);
void student_print(student* m);
void proces_student(student *m, int N);
void professor_init(professor *m, int M);
void print_professor(professor *m, int M);
void proces_professor(student *m, int N);

int main(int argc, char *argv[])
{
     assert(determ() == 255);
    cout << "Function determinate works!" << endl;
    ///////////////////////////
      matrix_multiple();
    ///////////////////////////
    student *Group = new student[N];
    professor *Professors = new professor[M];

    professor_init(Professors, M);
    print_professor(Professors, M);

    cout << "=============" << endl;

    student_init(Group, Professors, N);
    print_student(Group, N);

    cout << "=============" << endl;

    proces_student(Group, N);

    cout << "=============" << endl;

    proces_professor(Group, N);


    return 0;
}

///////Task #16 /////
int determ()
{
    int **Arr;
    int m = 1, result, z = 1, x = 1, y = 1;
    Arr = new int*[N];
    for(int i = 0; i < N; i++)
    {
        Arr[i] = new int[N];
    }
   for(int i = 0; i < N; i++)
   {
       for(int j = 0; j < N; j++)
       {
           Arr[i][j] = m;
           m++;
       }
   }

       for(int i = N - 1,j = 0; j < N; i--,j++)
       {

            x *= Arr[i][j];
            y *= Arr[j][i];
            z *= Arr[j][j];

       }
       result = x + y + z;
   return result;
}

///////Task #17 /////

int matrix_multiple()
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
        cout << "Those matrixs cant be multiple!" << endl;
        for(int i = 0; i < x1; i++)
         {
             delete []matrix1[i];
         }
        for(int i = 0; i < x2; i++)
         {
             delete []matrix2[i];
         }
     }
    else
    {
    cout << "Enter elements of matrix 1: " << endl;
    for(int i = 0; i < x1; i++)
     {
        for(int j = 0; j < y1; j++)
         {
            cout << 'a' << i + 1 << '.' << j + 1 << ": ";
             cin >> matrix1[i][j];
         }
     }
    system("clear");

    cout << "Enter elements of matrix 2: " << endl;
    for(int i = 0; i < x1; i++)
     {
      for(int j = 0; j < y1; j++)
       {
          cout << 'b' << i + 1 << '.' << j + 1 << ": ";
          cin >> matrix2[i][j];
       }
     }


    }
}

///////Task #18 /////

// Init students
void student_init(student *m, professor *k, int N)
{
    srand(time(0));
    int n;
    for(int i = 0; i < N; i++)
    {
        n = rand() % 3;//rand head of student
        sprintf(m[i].base.name, "Aaa%d", i + 1);
        m[i].base.age = i + 19;
        m[i].pga = rand() % 100;
        m[i].head = k[n];//assign professor to student
    }
}

void print_student(student *m, int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << "Student: " << m[i].base.name << endl;
        cout << "Age: " << m[i].base.age << endl;
        cout << "pga: " << m[i].pga << endl;
        cout << "Name of head: " << m[i].head.base.name << endl << endl;

    }

}

void proces_student(student *m, int N)
{
    //bad & good students
    student bad, good;
    double mid_p = 0, sum_pga;
    for(int i = 0; i < N; i++)
    {
        if(m[i].pga > m[i + 1].pga)
        {
            good = m[i];
        }
        if(m[i].pga < m[i + 1].pga)
        {
            bad = m[i];
        }
        sum_pga += m[i].pga;

    }
    mid_p = sum_pga / N;
    cout << "Middle value gpa of all students: " << mid_p << endl;
    cout << "Bad student: " << endl;
    cout << "Name: " << bad.base.name << ", age: " << bad.base.name << ", gpa: " << bad.pga << endl;
    cout << "Good student: " << endl;
    cout << "Name: " << good.base.name << ", age: " << good.base.name << ", gpa: " << good.pga << endl;
}

void professor_init(professor *m, int M)
{
    srand(time(0));
    for(int i = 0; i < M; i++)
    {
        sprintf(m[i].base.name, "Proff%d", i + 1);
        m[i].base.age = rand() % 10 + 45;//rand age of professor
        m[i].salary = rand() % 1000 + 2000;//rand salary of professor
    }
}

void print_professor(professor *m, int M)
{
    for(int i = 0; i < M; i++)
    {
        cout << "Professor: " << m[i].base.name << endl;
        cout << "Age: " << m[i].base.age << endl;
        cout << "Salary: " << m[i].salary << endl;
    }

}
//print students who have science adviser older than 50
void proces_professor(student *m, int N)
{
    for(int i = 0; i < N; i++)
    {
        if(m[i].head.base.age >= 50)
        {
            cout << "Name: " << m[i].base.name << endl;
            cout << "Age: " << m[i].base.age << endl;
            cout << "Name of sience head: " << m[i].head.base.name << endl;
            cout << "Age of sience head: " <<m[i].head.base.age << endl;
        }

    }
}







