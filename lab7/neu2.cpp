#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {
protected:
    string name;
    double x, y, z;

public:
    Shape(const string& n, double x, double y) : name(n), x(x), y(y) {}

    string getName() const { return name; }

    double getX() const { return x; }
    double getY() const { return y; }
};

class _2DShape : public Shape {
public:
    _2DShape(const string& n, double x, double y) : Shape(n, x, y) {}

    virtual double area() const = 0;
};

class Circle : public _2DShape {
private:
    double radius;

public:
    Circle(const string& n, double x, double y, double r)
        : _2DShape(n, x, y), radius(r) {
        if (radius <= 0) {
            cout << "radius surug bhgui" << endl;
        }
    }

    void setRadius(double new_radius) {
        if (new_radius <= 0) {
            radius = 0;
            cout << "radius surug bhgui" << endl;
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
};

class Square : public _2DShape {
private:
    double side_length;

public:
    Square(const string& n, double x, double y, double sl)
        : _2DShape(n, x, y), side_length(sl) {
        if (side_length <= 0) {
            cout << "tal surug bhgui" << endl;
        }
    }

    void setSideLength(double new_side_length) {
        if (new_side_length <= 0) {
            side_length = 0;
            cout << "tal surug bhgui" << endl;
        } else {
            side_length = new_side_length;
        }
    }

    double area() const  {
        return side_length * side_length;
    }
};

class RightTriangle : public _2DShape {
private:
    double base, height;

public:
    RightTriangle(const string& n, double x, double y, double b, double h)
        : _2DShape(n, x, y), base(b), height(h) {
        if (base <= 0 || height <= 0) {
            cout << "undur suuri surug bhgui" << endl;
        }
    }

    void setBase(double new_base) {
        if (new_base <= 0) {
            cout << "suuri surug bhgui" << endl;
            base = 0;
        } else {
            base = new_base;
        }
    }

    void setHeight(double new_height) {
        if (new_height <= 0) {
            cout << "undur surug bhgui" << endl;
            height = 0;
        } else {
            height = new_height;
        }
    }

    double area() const  {
        return 0.5 * base * height;
    }
};

int main() {
    Circle circle("Circle", 0, 0, 5);
    cout << "Area of " << circle.getName() << ": " << circle.area() << endl;

    circle.setRadius(-2);
    cout<<"New area of "<<circle.getName()<<": "<<circle.area()<<endl;

    Square square("Square", 1, 1, 4);
    cout << "Area of " << square.getName() << ": " << square.area() << endl;

    RightTriangle triangle("Right Triangle", 2, 2, 3, 4);
    cout << "Area of " << triangle.getName() << ": " << triangle.area() << endl;
    
    return 0;
}
