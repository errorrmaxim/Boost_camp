#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

// 1) verify parity with bite method Task #1.1
int bite_parity(int);

// 1) verify parity with out bite method Task #1.2
int parity(int);

// 2) sum of three numbers Task #2
int sum_val(int);

// 3) print numbers with 7 (from 0 till 1000) Task #3
void sev_return();

// 4) circle Task #4
bool circle_lol();

// 5) 3-rd pow of 2, from 0 till 10000000  Task #5
void pow_3_to();

// 6) return pow of number Task #6
void task_6(int);


int main(int argc, char *argv[])
{


    int num;


    cin >> num;
    bite_parity(num);
    parity(num);
    sum_val(num);
    sev_return();
    pow_3_to();
    task_6(num);
    int kek = circle_lol();

    if(kek == 1)
    {
        cout << "Cross!";
    }
    else
    {
        cout << "Miss!";
    }



    return 0;
}

////////// Task#1 ////////
int bite_parity(int num)
{
    if(num & 1)
    {
         cout << num << " is odd!" << endl;
    }else {
         cout << num << " is even!" << endl;
    }
}

////////// Task#1 ////////
int parity(int num)
{
    if(num % 2 == 0)
    {
        cout << num << " is even!" << endl;
    }else {
        cout << num << " is odd!" << endl;
    }
}

////////// Task#2 ////////
int sum_val(int num)
{

    int x;
    int y;
    int z;
    int sum;

    if(num > 999)
    {
        cout << "Error";
        return 0;
    }
    x = num / 100;
    y = (num % 100) / 10;
    z = num % 10;

    return x + y + z;
}

////////// Task#3 ////////
void sev_return()
{
    int x;
    int y;
    int z;

    for(int i = 0; i < 1000; i++)
    {
        x = i / 100;
        y = (i % 100) / 10;
        z = i % 10;
        if(x == 7 || y == 7 || z == 7 || x == 1 || y == 1 || z == 1)
        {
            cout << i << endl;
        }
    }
}

///////// Task#4 /////////
bool circle_lol()
{
    double x1,y1,r1;
    double x2,y2,r2;
    double r;
    cout << "Enter x1: "; cin >> x1;
    cout << "Enter y1: "; cin >> y1;
    cout << "Enter r1: "; cin >> r1;
    cout << "Enter x2: "; cin >> x2;
    cout << "Enter y2: "; cin >> y2;
    cout << "Enter r2: "; cin >> r2;

    r = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    if(x1 == x2 && y1 == y2 && r1 != r2)//1) Eсли центры совподают
    {
       return 0;
    }
    if(r <= r1 + r2)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

//////// Task#5 //////////
void pow_3_to()
{
    int val;
    for(int i = 0;;i++)
    {
        val = pow(i,3);

        if(val <= 1000000)
        {
            cout << val << endl;
        }else{
            break;
        }
    }
}

//////// Task#6 ///////////
void task_6(int num)
{
    int m = log2(num);
    if(num == pow(2,m))
    {
        cout << num << " is " << m << " pow of number 2!" << endl;
    }else {
       cout << num << " is not pow of number 2!" << endl;
    }
}



















