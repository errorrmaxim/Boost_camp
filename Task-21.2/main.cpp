#include <iostream>
#include <cmath>

using namespace std;

double PI = 3.1415;

//function for get values
int val_input();

//===================================================
//ABSTRACT SHAPE
class Shape
{
    // coordunates
    int X;
    int Y;
public:
    Shape()
    {
//        cout << "Coordinates: " << endl;
//        cout << "X: "; X = val_input();
//        cout << "Y: "; Y = val_input();
    }

    virtual float Area() = 0;
};
//===================================================
//RECTANGLE
class Rectangle : public Shape
{
private:
    float width;
    float hight;
    float rec_area;

public:

    Rectangle()
    {
        cout << "~Rectangle~" << endl;
        width = val_input();
        hight = val_input();
    }

    float Area()
    {
        rec_area = width * hight;
        cout << "Area of rectangle = " << rec_area << endl;
        return rec_area;
    }
};
//===================================================
//TRIANGLE
class Triangle : public Shape
{
    float length_1side;
    float length_2side;
    float length_3side;
    float half_perim;
    float trian_area;
public:


    Triangle()
    {
        cout << "~Triangle~" << endl;
        cout << "Side 1 ";
        length_1side = val_input();
        cout << "Side 2 ";
        length_2side = val_input();
        cout << "Side 3 ";
        length_3side = val_input();
    }

    float Area()
    {

        half_perim = (length_1side + length_2side + length_3side) / 2;
        trian_area = sqrt(half_perim * (half_perim - length_1side) * (half_perim - length_2side) * (half_perim - length_3side));
        cout << "Area of triangle = " << trian_area << endl;
        return trian_area;
    }
};
//===================================================
//CIRCLE
class Circle : public Shape
{
private:
    float radius;
    float area_circ;

public:
    Circle()
    {
      cout << "~Circle~" << endl;
      radius = val_input();
    }

    float Area()
    {
        area_circ = PI * pow(radius, 2);
        cout << "Area of circle = " << area_circ << endl;
        return area_circ;
    }

};
//==================================================
int val_input()                                   //
{                                                 //
    int value;                                    //
    cout << "Enter value in cm: ";                //
    cin >> value;                                 //
    return value;                                 //
}                                                 //
// func for get area of shape                     //
float get_area(Shape &r)                          //
{                                                 //
    r.Area();                                     //
}                                                 //
//==================================================


int main(int argc, char *argv[])
{
    float answ = 0;

   Shape *p[3];
   p[0] = new Rectangle;
   p[1] = new Triangle;
   p[2] = new Circle;


//area sum of shapes

  for(int i = 0; i < 3; i++)
  {
      answ += p[i]->Area();
  }

  cout << "Sum of area is: " << answ << endl;



    return 0;
}



