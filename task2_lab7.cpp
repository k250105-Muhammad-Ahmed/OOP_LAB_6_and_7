#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{
protected:
    string position;
    string color;
    int borderThickness;

public:
    Shape(string posi, string i_color, int bor) : position(posi), color(i_color), borderThickness(bor) {}

    virtual void draw() = 0;

    virtual void calculateArea() = 0;

    virtual void calculatePerimeter() = 0;
};

class Circle : public Shape
{
private:
    double radius;
    string center_position;

public:
    Circle(string posi, string i_color, int bor, double i_radius, string center) : Shape(posi, i_color, bor), radius(i_radius), center_position(center) {}

    void draw() override
    {
        cout << "\nCircle draw of color" << color << " and border thickness:" << borderThickness << " cm" << endl;
    }

    void calculateArea() override
    {
        cout << "Area:" << M_PI * radius * radius << endl;
    }

    void calculatePerimeter() override
    {
        cout << "Perimeter:" << 2 * M_PI * radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;
    string top_left_position;

public:
    Rectangle(string posi, string i_color, int bor, double i_width, double i_height, string i_top_left) : Shape(posi, i_color, bor), width(i_width), height(i_height), top_left_position(i_top_left) {}

    void draw() override
    {
        cout << "\nRectangle draw of color" << color << " and border thickness:" << borderThickness << " cm" << endl;
    }

    void calculateArea() override
    {
        cout << "Area:" << width * height << endl;
    }

    void calculatePerimeter() override
    {
        cout << "Perimeter:" << 2 * (width + height) << endl;
    }
};

class Triangle : public Shape
{
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(string posi, string color, int bor, double s1, double s2, double s3)
        : Shape(posi, color, bor), side1(s1), side2(s2), side3(s3) {}

    void draw() override
    {
        cout << "\nTriangle draw of color" << color << " and border thickness:" << borderThickness << " cm" << endl;
    }

    void calculateArea() override
    {
        double s = (side1 + side2 + side3) / 2;
        cout << "Area:" << sqrt(s * (s - side1) * (s - side2) * (s - side3)) << endl;
    }

    void calculatePerimeter() override
    {
        cout << "Perimeter:" << side1 + side2 + side3 << endl;
    }
};

int main()
{
    Circle c1("0,0", "black", 3, 4, "0,0");
    Rectangle r1("0,0", "black", 3, 4, 5, "0,0");
    Triangle t1("0,0", "black", 3, 2, 4, 5);

    c1.draw();
    c1.calculateArea();
    c1.calculatePerimeter();

    r1.draw();
    r1.calculateArea();
    r1.calculatePerimeter();

    t1.draw();
    t1.calculateArea();
    t1.calculatePerimeter();

    return 0;
}