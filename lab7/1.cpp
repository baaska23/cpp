#include <iostream>
#include <string.h>
using namespace std;

#define p 3.14

class Shape{
    public:
    float x, y, len;
    char name[10];
};

class Circle : public Shape{
    public:
    Circle(float x, float y, float radius, const char* name) {
        this->x = x;
        this->y = y;
        this->len = radius; 
        strcpy(this->name, name);
    }

    float findArea(){
        return p * len * len;
    }

    float findCircum(){
        return 2 * p * len;
    }

};

class Quad : public Shape{
    public:
    float findArea(){
        return len * len;
    }

    float findPeri(){
        return 4*len;
    }
};

class Triangle : public Shape{
    public:
    float findArea(){
        return (len * len)/2;
    }
    
    float findPeri(){
        return 3*len;
    }
};

int main(){
    Circle circle(0, 0, 5, "Circle");
    cout<<"Circle area is: "<<circle.findArea()<<endl;
}