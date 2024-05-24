#include <iostream>
#include <cstring>
using namespace std;

#define MAX_EMPLOYEES 20
struct Address{
    char street[50];
    char city[50];
    char country[50];
};

class Employee{
    private:
        int empID;
        char* name;
        Address address;
    
    public:
        Employee(int id, const char* empName, const Address& empAddress) : empID(id), address(empAddress){
            name = new char[strlen(empName) + 1];
            strcpy(name, empName);
        }
        ~Employee(){
            delete[] name;
        }

        //getter
        int getEmpID() const{
            return empID;
        }

        const char* getName() const{
            return name;
        }

        const Address& getAddress() const{
            return address;
        }

        //setter
        void setEmpID(int id){
            empID = id;
        }

        void setName(const char* empName){
            delete[] name;
            name = new char[strlen(empName) + 1];
            strcpy(name, empName);
        }

        void setAddress(const Address& empAddress){
            address = empAddress;
        }
};

inline void printEmployeeDetails(const Employee& emp){
    cout<<"Employee ID: "<<emp.getEmpID()<<endl;
    cout<<"Employee name: "<<emp.getName()<<endl;
    cout<<"Address: "<<emp.getAddress().street<<", "<<emp.getAddress().city<<", "<<emp.getAddress().country<<endl;
}

int main(){
    Employee* ajilchid[MAX_EMPLOYEES];

    Address addr1 = {"123 Main St", "Boomtown", "UK"};
    ajilchid[0] = new Employee(1, "Kai Uuganbadrakh", addr1);

    Address addr2 = {"Heetei District", "Darkhan", "MN"};
    ajilchid[1] = new Employee(2, "Clay Jensen", addr2);

    for(int i=0; i<2; ++i){
        printEmployeeDetails(*ajilchid[i]);
    }

    ajilchid[0]->setEmpID(19);
    ajilchid[1]->setName("LeBron James");

    cout<<"After modification: \n";
    for(int i=0; i<2; ++i){
        printEmployeeDetails(*ajilchid[i]);
    }

    for(int i=0; i<2; i++){
        delete ajilchid[i];
    }
    return 0;
}