#include <iostream>
using namespace std;

struct person{
    int age;
    char name[20];
    float height;
};

void ref_func(person &pp)
    {
        strcpy(pp.name, "Tengo");
        pp.age = 24;
        pp.height = 203;
}

struct point{
    int a, b;
    void draw(void);
};

void point::draw(){
    cout<<a<<"\n"<<b<<endl;
}

int main(){
    person p;
    ref_func(p);
    cout<<p.name<<endl;
    cout<<p.age<<endl;
    cout<<p.height<<endl;

    point a, b;
    a.a = 10;
    a.b = 20;
    a.draw();

    b = a;
    b.b = 123;
    b.draw();
}

