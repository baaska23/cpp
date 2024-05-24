#include <iostream>
using namespace std;

class Person{
    private: 
        char *firstName;
        char *lastName;
        char *SSN;
        char *sex;
    
    public:
        Person();
        Person(char *fname, char *lname, char *s);
        virtual void showData()=0;
};

class Student : public Person{
    private: 
        char *sisiId;
        char *angi;
    
    public:
        Student();
        Student(char *fname, char *lname, char *s, char *sisi_id, char *a);
        ~Student();

        const char* getSisiId() const;
        void setSisiId(const char* id);

        const char* getAngi() const;
        void setAngi(const char* a);
};

const char* Student::getSisiId() const {
    return sisiId;
}

void Student::setSisiId(const char* id) {
    if (sisiId != nullptr)
        delete[] sisiId;
    sisiId = new char[strlen(id) + 1];
    strcpy(sisiId, id);
}

const char* Student::getAngi() const {
    return angi;
}

void Student::setAngi(const char* a) {
    if (angi != nullptr)
        delete[] angi;
    angi = new char[strlen(a) + 1];
    strcpy(angi, a);
}



int main(){
    Student a;
    a.setAngi("Program hangamj");
    a.setSisiId("21b1num0021");

    Student b;
    b("Baasandorj", "Uuganbadrakh", "Male", "21b1num0021", "Program hangamj");

}