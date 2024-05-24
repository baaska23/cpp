#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point {
public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x, y;
};

class Shape {
protected:
    string name;

public:
    Shape(const string& n) : name(n) {}
    string getName() const { return name; }
};

class _2DShape : public Shape {
public:
    _2DShape(const string& n) : Shape(n) {}

    virtual double area() const = 0;
};

class Circle : public _2DShape {
private:
    Point center;
    double radius;

public:
    Circle(const string& n, const Point& c, double r)
        : _2DShape(n), center(c), radius(r) {
        if (radius <= 0) {
            cout << "Invalid radius: Radius cannot be negative." << endl;
        }
    }

    void setRadius(double new_radius) {
        if (new_radius <= 0) {
            radius = 0;
            cout << "Radius surug bj bolku" << endl;
        } else {
            radius = new_radius;
        }
    }

    double area() const {
        return M_PI * radius * radius;
    }

    double circumference() {
        return 2 * M_PI * radius;
    }

    string getName() const {
        return name;
    }
};

class Square : public _2DShape {
private:
    Point topLeft;
    double side_length;

public:
    Square(const string& n, const Point& tl, double sl)
        : _2DShape(n), topLeft(tl), side_length(sl) {
        if (side_length <= 0) {
            cout << "Taliin urt surug bj bolohgui" << endl;
        }
    }

    void setSideLength(double new_side_length) {
        if (new_side_length <= 0) {
            side_length = 0;
            cout << "Taliin urt surug bj bolohgui" << endl;
        } else {
            side_length = new_side_length;
        }
    }

    double area() const  {
        return side_length * side_length;
    }

    string getName() const  {
        return name;
    }
};

class RightTriangle : public _2DShape {
private:
    Point top;
    double base, height;

public:
    RightTriangle(const string& n, const Point& t, double b, double h)
        : _2DShape(n), top(t), base(b), height(h) {
        if (base <= 0 || height <= 0) {
            cout << "Suuri, undur eyreg bh ysto" << endl;
        }
    }

    void setBase(double new_base) {
        if (new_base <= 0) {
            cout << "Suuri  surug bj bolohgui" << endl;
            base = 0;
        } else {
            base = new_base;
        }
    }

    void setHeight(double new_height) {
        if (new_height <= 0) {
            cout << "Undur surug bj blku" << endl;
            height = 0;
        } else {
            height = new_height;
        }
    }

    double area() const  {
        return 0.5 * base * height;
    }

    string getName() const  {
        return name;
    }
};

int main() {
    Point center(0, 0);
    Circle circle("toirog", center, 5);
    cout << "Area of " << circle.getName() << ": " << circle.area() << endl;

    Point topLeft(1, 1);
    Square square("kvadrat", topLeft, 4);
    square.setSideLength(-2);
    cout << "Area of " << square.getName() << ": " << square.area() << endl;
    square.setSideLength(3);
    cout << "Area of " << square.getName()<< ": "<<square.area() << endl;

    Point top(2, 2);
    RightTriangle triangle("gurvaljin", top, 3, 4);
    cout << "Area of " << triangle.getName() << ": " << triangle.area() << endl;
    
    return 0;
}