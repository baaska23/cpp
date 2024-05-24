#include <iostream>
using namespace std;

class Person {
public:
  virtual void introduce() {
    cout << "Hello! I'm a person." << endl;
  }
};

class Student : public Person {
public:
  void introduce() override {
    cout << "Hello! I'm a student." << endl;
  }
};

class Teacher : public Person {
public:
  void introduce() override {
    cout << "Hello! I'm a teacher." << endl;
  }
};

int main() {
  Person* person1 = new Student();
  Person* person2 = new Teacher();

  person1->introduce(); 
  person2->introduce(); 

  delete person1;
  delete person2;

  return 0;
}
