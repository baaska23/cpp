#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Date {
    int on;
    int sar;
    int udur;
};

//Person class
class Person {
protected:
    char* name;
    char* SSNum;
    int age;
public:
    Person(){
        name = new char[8];
        strcpy(name, "unknown");
        SSNum = new char[8];
        strcpy(SSNum, "unknown");
        age = 0;
    }
    Person(const char* name, const char* SSNum, int age){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->SSNum = new char[strlen(SSNum)+1];
        strcpy(this->SSNum, SSNum);
        if (age >= 0)
            this->age = age;
        else cout<<"Invalid age.";
    }
    ~Person(){
        delete[] name;
        delete[] SSNum;
    }
    const char* getName() const;
    const char* getSSNum() const;
    int getAge();
    void setName(const char * x);
    void setSSNum(const char * x);
    void setAge(int x);
    virtual void print() = 0;
    Person& operator=(const Person& other);
};

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] name;
        delete[] SSNum;
        age = other.age;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        SSNum = new char[strlen(other.SSNum) + 1];
        strcpy(SSNum, other.SSNum);
    }
    return *this;
}
const char* Person::getName() const {
    return name;
}
const char* Person::getSSNum() const {
    return SSNum;
}
int Person::getAge(){
    return age;
}
void Person::setName(const char * x){
    if (name != nullptr)
        delete[] name;
    name = new char[strlen(x) + 1];
    strcpy(name, x);
}
void Person::setSSNum(const char * x){
    if (SSNum != nullptr)
        delete[] SSNum;
    SSNum = new char[strlen(x) + 1];
    strcpy(SSNum, x);
}
void Person::setAge(int x){
    if (age < 0)
    {
        cout << "Invalid age." << endl;
        return;
    }
    age = x;
}

//Spouse class
class Spouse : public Person{
private:
    Date anniversaryDate;
public:
    Spouse() : Person(){
        anniversaryDate.on = 2000;
        anniversaryDate.sar = 1;
        anniversaryDate.udur = 1;
    }
    Spouse(int on, int sar, int udur, const char* name, const char* SSNum, int age) : Person(name, SSNum, age){
        anniversaryDate.on = on;
        anniversaryDate.sar = sar;
        anniversaryDate.udur = udur;
    }
    Date getAnnDate();
    void setAnnDate(int on, int sar, int udur);
    void print(){
        cout << "\nSpouse name: " << getName();
        cout << "\nSSNum: " << getSSNum();
        cout << "\nAge: " << getAge();
        cout << "\nAnniversary date: "<<getAnnDate().on <<"-"<< getAnnDate().sar<<"-"<< getAnnDate().udur;
    }
};

Date Spouse::getAnnDate(){
    return anniversaryDate;
}
void Spouse::setAnnDate(int on, int sar, int udur){
    anniversaryDate.on = on;
    anniversaryDate.sar = sar;
    anniversaryDate.udur = udur;
}

// Child class
class Child : public Person{
private:
    char* favoriteToy;
public:
    Child() : Person(){
        favoriteToy = new char[8];
        strcpy(favoriteToy, "unknown");
    }
    Child(const char* favoriteToy, const char* name, const char* SSNum, int age) : Person(name, SSNum, age){
        this->favoriteToy = new char[strlen(favoriteToy) + 1];
        strcpy(this->favoriteToy, favoriteToy);
    }
    ~Child(){
        delete[] favoriteToy;
    }
    Child(const Child& other);
    const char* getFavToy();
    void setFavToy(const char* x);
    Child& operator=(const Child& other);
    void print(){
        cout << "\nChild name: " << getName();
        cout << "\nSSNum: " << getSSNum();
        cout << "\nAge: " << getAge();
        cout << "\nFavourite toy: " << getFavToy();
    }
};
Child::Child(const Child& other) : Person(other) {
    this->favoriteToy = new char[strlen(other.favoriteToy) + 1];
    strcpy(this->favoriteToy, other.favoriteToy);
}

Child& Child::operator=(const Child& other) {
    if (this != &other) {
        Person::operator=(other);
        delete[] favoriteToy;
        favoriteToy = new char[strlen(other.favoriteToy) + 1];
        strcpy(favoriteToy, other.favoriteToy);
    }
    return *this;
}
const char* Child::getFavToy(){
    return favoriteToy;
}
void Child::setFavToy(const char* x){
    if (favoriteToy != nullptr)
        delete[] favoriteToy;
    favoriteToy = new char[strlen(x) + 1];
    strcpy(favoriteToy, x);
}

// Division class
class Division{
private:
    char* divisionName;
public:
    Division(){
        divisionName = new char[8];
        strcpy(divisionName, "unknown");
    }
    Division(const char* divisionName){
        this->divisionName = new char[strlen(divisionName) + 1];
        strcpy(this->divisionName, divisionName);
    }
    ~Division(){
        delete[] divisionName;
    }
    const char* getDivName();
    void setDivName(const char* x);
    Division(const Division& other);
    Division& operator=(const Division& other);
};
const char* Division::getDivName(){
    return divisionName;
}
void Division::setDivName(const char* x){
    if (divisionName != nullptr)
        delete[] divisionName;
    divisionName = new char[strlen(x) + 1];
    strcpy(divisionName, x); 
}
Division::Division(const Division& other) {
    this->divisionName = new char[strlen(other.divisionName) + 1];
    strcpy(this->divisionName, other.divisionName);
}

Division& Division::operator=(const Division& other) {
    if (this != &other) {
        delete[] divisionName;
        divisionName = new char[strlen(other.divisionName) + 1];
        strcpy(divisionName, other.divisionName);
    }
    return *this;
}


//JobDescription class
class JobDescription{
private:
    char* description;
public:
    JobDescription(){
        description = new char[8];
        strcpy(description, "unknown");
    }
    JobDescription(const char* description){
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);
    }
    ~JobDescription(){
        delete[] description;
    }
    const char* getDescription();
    void setDescription(const char* x);
    JobDescription(const JobDescription& other);
    JobDescription& operator=(const JobDescription& other);
};
JobDescription::JobDescription(const JobDescription& other) {
    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);
}
JobDescription& JobDescription::operator=(const JobDescription& other) {
    if (this != &other) {
        delete[] description;
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    return *this;
}
const char* JobDescription::getDescription(){
    return description;
}
void JobDescription::setDescription(const char* x){
    if (description != nullptr)
        delete[] description;
    description = new char[strlen(x) + 1];
    strcpy(description, x);
}

// Employee class
// Employee class
class Employee : public Person {
private:
    char* companyID;
    char* title;
    Date startDate;
    Spouse *spouse;
    Division division;
    vector<Child*> children;
    vector<JobDescription*> jobDescriptionList;
public:
    static int k;
    Employee() : Person(){
        companyID = new char[8];
        strcpy(companyID, "unknown");
        title = new char[8];
        strcpy(title, "unknown");
        startDate.on = 2000;
        startDate.sar = 1;
        startDate.udur = 1;
        division = Division(); // Changed to create a Division object instead of a pointer
        jobDescriptionList.push_back(new JobDescription());
    }
    Employee(int on, int sar, int udur, const char* companyID, const char* title, const char* name, const char* SSNum, int age, Division d, JobDescription* jd, Spouse* s, Child* c) : Person(name, SSNum, age){
        this->companyID = new char[strlen(companyID)+1];
        strcpy(this->companyID, companyID);
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
        startDate.on = on;
        startDate.sar = sar;
        startDate.udur = udur;
        division = d; // Directly use the Division object
        if (jd != nullptr) {
            jobDescriptionList.push_back(new JobDescription(*jd));
        }
        if (s != nullptr) {
            spouse = new Spouse(*s);
        }
        if (c != nullptr) {
            children.push_back(new Child(*c));
        }
    }
    ~Employee(){
        delete[] companyID;
        delete[] title;
    }
    void print(){
        cout << "\n-------------------------------\n";
        cout << "\nEmployee name: " << getName();
        cout << "\nSSNum: " << getSSNum();
        cout << "\nAge: " << getAge();
        cout << "\nCompany ID: " << getComID();
        cout << "\nTitle: " << getTitle();
        cout << "\nDivision: " << division.getDivName(); // Changed to access method of Division object
        cout << "\nStart date: "<<getStartDate().on <<"-"<< getStartDate().sar<<"-"<< getStartDate().udur;
        cout << "\nJob description----------------";
        for (int i = 0; i < jobDescriptionList.size(); i++)
        {
            cout <<"\nDescription "<< i <<": "<< jobDescriptionList[i]->getDescription();
        }
        if (spouse != nullptr)
        {
            cout << "\nSpouse-------------------------";
            spouse->print();
        }
        if (!children.empty())
        {
            cout << "\nChildren-----------------------";
            for (int i = 0; i < children.size(); i++)
            {
                children[i]->print();
            }
        }
        cout << "\n-------------------------------\n";
    }
    const char* getComID();
    const char* getTitle();
    Date getStartDate();
    void setComID(const char* x);
    void setTitle(const char* x);
    void setStartDate(int on, int sar, int udur);
    bool addSpouse(Spouse* sp);
    bool removeSpouse();
    bool removeChild(const Child* c);
    void addChild(Child* c);
    void addJobDescription(JobDescription* js);
    void removeJobDescription(JobDescription* js);
};

int Employee::k = 0;
const char* Employee::getComID(){
    return companyID;
}
const char* Employee::getTitle(){
    return title;
}
Date Employee::getStartDate(){
    return startDate;
}
void Employee::setComID(const char* x){
    if (companyID != nullptr)
        delete[] companyID;
    companyID = new char[strlen(x) + 1];
    strcpy(companyID, x);
}
void Employee::setTitle(const char* x){
    if (title != nullptr)
        delete[] title;
    title = new char[strlen(x) + 1];
    strcpy(title, x);
}
void Employee::setStartDate(int on, int sar, int udur){
    startDate.on = on;
    startDate.sar = sar;
    startDate.udur = udur;
}
bool Employee::addSpouse(Spouse* sp){
    if (spouse == nullptr)
    {
        spouse = sp;
        return true;
    }
    return false;
}
bool Employee::removeSpouse(){
    if (spouse != nullptr)
    {
        spouse = nullptr;
        return true;
    }
    return false;
}
bool Employee::removeChild(const Child* c){
    if (!children.empty())
    {
        for (int i = 0; i < children.size(); i++)
        {
            if(strcmp(children[i]->getSSNum(), c->getSSNum()) == 0){
                children.erase(children.begin() + i);
                return true;
            }
        }
    }
    return false;
}
void Employee::addChild(Child* c){
    children.push_back(c);
}
void Employee::addJobDescription(JobDescription* js){
    jobDescriptionList.push_back(js);
}

void Employee::removeJobDescription(JobDescription* js){
    jobDescriptionList.pop_back();
}

int main() {
    Division division("IT");
    JobDescription jd1("Software Engineer");
    JobDescription jd2("Data Analyst");
    Spouse spouse(2005, 5, 5, "Alice", "123456789", 30);
    Child child("Teddy Bear", "Bob", "987654321", 7);

    Employee e(2020, 10, 1, "ACME", "Manager", "John", "123456789", 35, division, &jd1, &spouse, &child);

    e.print();

    JobDescription jd3("Product Manager");
    e.addJobDescription(&jd3);
    e.removeJobDescription(&jd3);
    
    if(!e.removeSpouse()){
        cout << "Ehner ustsangui.";
    }else cout << "Ehner ustlaa.";
    Child child2("Doll", "Emma", "456789123", 5);
    e.addChild(&child2);

    e.print();
    return 0;
}
