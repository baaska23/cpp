#include <iostream>
#include <cstring>
using namespace std;

class Person {
    private:
        char *firstName;
        char *lastName;
        char *SSN;
        char *sex;

    public:
        Person() {
            firstName = new char[10];
            strcpy(firstName, "Iderkhvv");
            lastName = new char[10];
            strcpy(lastName, "Gunsor");
            SSN = new char[9];
            strcpy(SSN, "80490060");
            sex = new char[2];
            strcpy(sex, "em");
        }
        Person(char *fname, char *lname, char *s) {
            firstName = new char[strlen(fname) + 1];
            strcpy(firstName, fname);
            lastName = new char[strlen(lname) + 1];
            strcpy(lastName, lname);
            sex = new char[strlen(s) + 1];
            strcpy(sex, s);
        }
        virtual void showData() = 0;

        char* getFirstName() { return firstName; }
        char* getLastName() { return lastName; }
        char* getSSN() { return SSN; }
        char* getSex() { return sex; }

        ~Person() {
            delete[] firstName;
            delete[] lastName;
            delete[] SSN;
            delete[] sex;
        }
};

class Student : public Person {
    private:
        char *sisiId;
        char *angi;

    public:
        Student() : Person() {
            sisiId = new char[20];
            strcpy(sisiId, "21b1num0021");
            angi = new char[20];
            strcpy(angi, "Software Engineering");
        }
        Student(char *fname, char *lname, char *s, char *sisiId, char *a) : Person(fname, lname, s) {
            this->sisiId = new char[strlen(sisiId) + 1];
            strcpy(this->sisiId, sisiId);
            angi = new char[strlen(a) + 1];
            strcpy(angi, a);
        }
        ~Student() {
            delete[] sisiId;
            delete[] angi;
        }

        const char* getSisiId() {
            return sisiId;
        }
        void setSisiId(const char* id) {
            if (sisiId != nullptr) {
                delete[] sisiId;
            }
            sisiId = new char[strlen(id) + 1];
            strcpy(sisiId, id);
        }

        const char* getAngi() {
            return angi;
        }
        void setAngi(const char* a) {
            if (angi != nullptr) {
                delete[] angi;
            }
            angi = new char[strlen(a) + 1];
            strcpy(angi, a);
        }

        void showData() override {
            cout << "Name: " << getFirstName() << " " << getLastName() << endl;
            cout << "SSNumber: " << getSSN() << endl;
            cout << "Sex: " << getSex() << endl;
            cout << "SisiID: " << getSisiId() << endl;
            cout << "Angi: " << getAngi() << endl;
        }
};

int main() {
    Student a;
    a.setAngi("Program hangamj");
    a.setSisiId("21b1num0021");

    Student b("Baasandorj", "Uuganbadrakh", "Male", "21b1num0021", "Program hangamj");
    a.showData();
    b.showData();

    return 0;
}