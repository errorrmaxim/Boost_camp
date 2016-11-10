#include <iostream>

using namespace std;

class Shape
{
    // coordunates
    int X;
    int Y;
public:
    Shape()
    {
        cout << "Enter coordinates for center of shape: " << endl;
        cout << "X: "; cin >> X;
        cout << "Y: "; cin >> Y;
    }
    virtual float Area()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return 1;
    }
};

class Rectangle : public Shape
{
private:
    int widt;
    int hight;
    float rec_area;

public:
    Rectangle() : Shape()
    {
        cout << "Enter width of rectangle in cm: "; cin >> width;
        cout << "Enter hight of rectangle in cm: "; cin >> hight;

    }
    float Area()
    {
        rec_area = (float)width * hight;
    }
};

class Triangle : public Shape
{
    int length_1side;
    int length_2side;
    int length_3side;
    float trian_area;
public:
    Triangle() : Shape()
    {
        cout << "Enter length of first side: "; cin >> length_1side;
        cout << "Enter length of second side: "; cin >> length_2side;
        cout << "Enter length of third side: "; cin >> length_3side;
    }
    float Area()
    {

    }
};
int main(int argc, char *argv[])
{





    return 0;
}
