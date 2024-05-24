#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define PI 3.14

class Shape {
protected:
    char* name;

public:
    Shape() {
        this->name = new char[1];
        strcpy(this->name, "");
    }

    Shape(char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    ~Shape() {
        delete[] name;
    }

    virtual double calcPerimeter() const = 0;
};

class twoShape : public Shape {
public:
    twoShape() : Shape() {}

    twoShape(char* name) : Shape(name) {}

    virtual double calcArea() const = 0;

    void show() {
        cout << name << " ";
    }
};

class Circle : public twoShape {
private:
    double radius;
    int x, y;

public:
    Circle() : twoShape() {
        this->radius = 1;
        this->x = 0;
        this->y = 0;
    }

    Circle(char* name, double radius, int x, int y) : twoShape(name) {
        this->radius = radius;
        this->x = x;
        this->y = y;
    }

    double calcArea() const override {
        return PI * radius * radius;
    }

    double calcPerimeter() const override {
        return PI * radius * 2;
    }
};

class Square : public twoShape {
private:
    double side;
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

public:
    Square() : twoShape() {
        this->side = 1;
        this->x1 = 0;
        this->y1 = 0;
        x2 = x1 + side;
        y2 = y1;
        x3 = x1 + side;
        y3 = y1 - side;
        x4 = x1;
        y4 = y1 - side;
    }

    Square(char* name, double side, int x1, int y1) : twoShape(name) {
        this->side = side;
        this->x1 = x1;
        this->y1 = y1;
        x2 = x1 + side;
        y2 = y1;
        x3 = x1 + side;
        y3 = y1 - side;
        x4 = x1;
        y4 = y1 - side;
    }
    void set_x1(int new_x1) {
       
        this->x1 = new_x1;
        this->x2 = new_x1 + side;
        this->x3 = new_x1 + side;
        this->x4 = new_x1;
    }

    void set_y1(int new_y1) {
        
        this->y1 = new_y1;
        this->y2 = new_y1;
        this->y3 = new_y1 - side;
        this->y4 = new_y1 - side;
    }

    double calcArea() const override {
        return side * side;
    }

    double calcPerimeter() const override {
        return side * 4;
    }
};

class Triangle : public twoShape {
private:
    double side;
    int x1, x2, x3;
    int y1, y2, y3;

public:
    Triangle() : twoShape() {
        this->side = 1;
        this->x1 = 0;
        this->y1 = 0;
        calc23();
    }

    Triangle(char* name, double side, int x1, int y1) : twoShape(name) {
        this->side = side;
        this->x1 = x1;
        this->y1 = y1;
        calc23();
    }

    void calc23() {
        
        x2 = x1 + side / 2;
        y2 = y1 - sqrt(pow(side, 2) - pow((side / 2), 2));
        x3 = x1 - side / 2;
        y3 = y1 - sqrt(pow(side, 2) - pow((side / 2), 2));
    }

    void set_x1(int new_x1) {
        
        this->x1 = new_x1;
        calc23(); 
    }

    void set_y1(int new_y1) {
        
        this->y1 = new_y1;
        calc23(); 
    }

    double calcArea() const override {
        return (sqrt(3) / 4) * pow(side, 2);
    }

    double calcPerimeter() const override {
        return side * 3;
    }
};

void bubbleSort(twoShape* shapes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes[j]->calcArea() < shapes[j + 1]->calcArea()) {
                twoShape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
}

void print(twoShape* shapes[], int n) {
    for (int i = 0; i < n; i++) {
        shapes[i]->show();
        cout << shapes[i]->calcArea() << endl;
    }
}

int main() {
    Circle c1("c1", 3, 1, 1);
    Circle c2("c2", 1, 3, 1);
    Circle c3("c3", 5, 0, 0);
    Square s1("s1", 3, 0, 4);
    Square s2("s2", 2, 9, 9);
    Square s3("s3", 7, -1, 7);
    s3.set_x1(1);
    s3.set_y1(-2);
    Triangle t1("t1", 2, 0, 8);
    Triangle t2("t2", 8, 3, 1);
    Triangle t3("t3", 2, 0, 0);
    t1.set_x1(0);
    t2.set_y1(2);
    twoShape* shapes[9];
    shapes[0] = &c1;
    shapes[1] = &c2;
    shapes[2] = &c3;
    shapes[3] = &s1;
    shapes[4] = &s2;
    shapes[5] = &s3;
    shapes[6] = &t1;
    shapes[7] = &t2;
    shapes[8] = &t3;
    cout << "Talbaigaar erembelvel: " << endl;
    bubbleSort(shapes, 9);
    print(shapes, 9);
    return 0;
}