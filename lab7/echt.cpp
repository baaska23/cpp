#include <iostream>
#include <cmath>
#include <string>
using namespace std;
 
class Shape {
protected:
    string name;

public:
    Shape(const string& n) : name(n) {}
 
    string getName() const {
        return name;
    }
};
 
class _2DShape : public Shape {
public:
    _2DShape(const string& n) : Shape(n), pair<double, double> point {}
    
};
 
class Circle : public _2DShape {
private:
    // pair<double, double> center; // x,y coordinate
    double radius;
 
public:
    Circle(const string& n, double cx, double cy, double r)
        : _2DShape(n), center(make_pair(cx, cy)), radius(r) {}
 
    double area() {
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
    pair<double, double> vertices[4]; 
    double side_length;
 
public:
    Square(const string& n, double ulx, double uly, double sl)
        : _2DShape(n), side_length(sl) {
        
        vertices[0] = make_pair(ulx, uly); // zuun deed
        vertices[1] = make_pair(ulx + sl, uly); // baruun deed
        vertices[2] = make_pair(ulx, uly - sl); // zuun dood
        vertices[3] = make_pair(ulx + sl, uly - sl); // baruun dood
    }
 
    double area() {
        return side_length * side_length;
    }
 
    string getName() const {
        return name;
    }
};
 
class Triangle : public _2DShape {
private:
    pair<double, double> vertices[3]; 
    double side_length;
 
public:
    Triangle(const string& n, double topx, double topy, double sl)
        : _2DShape(n), side_length(sl) {
 
        vertices[0] = make_pair(topx, topy); // Top
        vertices[1] = make_pair(topx - sl / 2, topy - (sqrt(3) / 2) * sl); // zuun dood
        vertices[2] = make_pair(topx + sl / 2, topy - (sqrt(3) / 2) * sl); // baruun dood
    }
 
    double area() {
        return (sqrt(3) / 4) * side_length * side_length;
    }
 
    string getName() const {
        return name;
    }
};
 
int main() {
    Circle circle("Circle", 0, 0, 5);
    cout << "Area of " << circle.getName() << ": " << circle.area() << endl;
    cout << "Circumference of " << circle.getName() << ": " << circle.circumference() << endl;
 
    Square square("Square", 0, 0, 5);
    cout << "Area of " << square.getName() << ": " << square.area() << endl;
 
    Triangle triangle("Triangle", 0, 5, 5);
    cout << "Area of " << triangle.getName() << ": " << triangle.area() << endl;
 
    return 0;
}

// setter tavij ug -> taluud uurchlugvul oroin tseguuded yj nuluulhu, esregeree uurchlugdvul bas yu bolhu : kvadrat, gurvaljin
// udamshil -> shape2d class hooson bn there must be logic