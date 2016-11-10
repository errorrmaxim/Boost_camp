#include <iostream>
#include <cmath>

using namespace std;

double PI = 3.1415;
class Shape
{
    // coordunates
    int X;
    int Y;
public:
    Shape()
    {
//        cout << "Enter coordinates for center of shape: " << endl;
//        cout << "X: "; cin >> X;
//        cout << "Y: "; cin >> Y;
    }
    virtual  void cin_val()
    {
       cout << __PRETTY_FUNCTION__ <<  endl;
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
    float width;
    float hight;
    float rec_area;

public:

    void cin_val()
    {
        cout << "Enter width of rectangle in cm: "; cin >> width;
        cout << "Enter hight of rectangle in cm: "; cin >> hight;
    }
    float Area()
    {
        rec_area = width * hight;
        cout << "Area of rectangle = " << rec_area << endl;
        return rec_area;
    }
};

class Triangle : public Shape
{
    float length_1side;
    float length_2side;
    float length_3side;
    float half_perim;
    float trian_area;
public:

    void cin_val()
    {
        cout << "Enter length of first side: "; cin >> length_1side;
        cout << "Enter length of second side: "; cin >> length_2side;
        cout << "Enter length of third side: "; cin >> length_3side;
    }

    float Area()
    {

        half_perim = (length_1side + length_2side + length_3side) / 2;
        trian_area = sqrt(half_perim * (half_perim - length_1side) * (half_perim - length_2side) * (half_perim - length_3side));
                cout << "Area of triangle = " << trian_area << endl;
        return trian_area;
    }
};

class Circle : public Shape
{
private:
    float radius;
    float diameter;
    float area_circ;
    char answ;
public:
    void cin_val()
    {
        cout << "Chose diameter or radius: D/R : "; cin >> answ;
        switch (answ) {
        case 'D':  cout << "Enter diameter of circle: "; cin >> diameter;
                   area_circ = (PI / 4) * pow(diameter, 2);
            break;
        case 'R': cout << "Enter radius of circle: "; cin >> radius;
                  area_circ = PI * pow(radius, 2);
            break;
        case 'd':  cout << "Enter diameter of circle: "; cin >> diameter;
                   area_circ = (PI / 4) * pow(diameter, 2);
            break;
        case 'r': cout << "Enter radius of circle: "; cin >> radius;
                  area_circ = PI * pow(radius, 2);
            break;
        default:
                  cout << "Error 404";
            break;
        }
    }
    float Area()
    {
        cout << "Area of circle = " << area_circ << endl;
       return area_circ;
    }

};

void get_val(Shape &r)
{
    r.cin_val();
}

float get_area(Shape &r)
{
    r.Area();
}

int main(int argc, char *argv[])
{
    Circle cir1[2];
    Triangle trg1[2];
    Rectangle rec1[2];
    float sum_area = 0;
    for(int i = 0; i < 2; i++)
    {
        cout << "Circle num" << i+1 << endl;
        get_val(cir1[i]);
        cout << "Triangle num" << i+1 << endl;
        get_val(trg1[i]);
        cout << "Rectangle num" << i+1 << endl;
        get_val(rec1[i]);

    }
    for(int i = 0; i < 2; i++)
    {
       sum_area += get_area(cir1[i]) + get_area(rec1[i]) + get_area(trg1[i]);

    }

cout << sum_area << endl;

    return 0;
}

