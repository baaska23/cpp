// 1. Олон ажилчин бүртгэж ажилчдыг нэрээр нь эрэмбэлэх. Нэрээр эрэмбэлэхдээ объектын хаяган хүснэгт үүсгээд хаягийг нь эрэмбэлбэлнэ.
// 2. Шинэ ажилчин бүртгэхдээ тухайн ажилчны ID өмнө бүртгэлтэй эсэхийг шалгаж бүртгэлтэй бол бүртгэхгүй. Өөрөөр хэлбэл ID дахин давхцахгүй болго.
#include <iostream>
#include <cstring>
using namespace std;

class Worker {
private:
    int workerId;
    char* name;
    char* position;
    float hoursWorked;

public:
    Worker() : workerId(0), hoursWorked(0), name(nullptr), position(nullptr) {}

    ~Worker() {
        delete[] name;
        delete[] position;
    }

    

    bool checkExistingId(int newId, Worker* w, int n) const {
        for (int i = 0; i < n; i++) {
            if (w[i].getWorkerId() == newId) {
                return true; 
            }
        }
        return false;
    }

    int getWorkerId() const {
        return workerId;
    }

    const char* getName() const {
        return name;
    }

    const char* getPosition() const {
        return position;
    }

    float getHoursWorked() const {
        return hoursWorked;
    }

    void setWorkerId(Worker* w, int newId, int n) {
        bool idExists;
        do {
            cout << "Worker ID: ";
            cin >> newId;
            idExists = checkExistingId(newId, w, n);
            if (idExists) {
                cout << newId << " IDtai hun ali hediin burtgegdsen bn" << endl;
            }
        } while (idExists);
        workerId = newId;
    }

    void setName(const char newName[]) {
        if (name) delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    Worker(const Worker& other) : workerId(other.workerId), hoursWorked(other.hoursWorked) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        position = new char[strlen(other.position) + 1];
        strcpy(position, other.position);
    }
    void setPosition(const char newPosition[]) {
        if (position) delete[] position;
        position = new char[strlen(newPosition) + 1];
        strcpy(position, newPosition);
    }

    void setHoursWorked(float newHoursWorked) {
        if (newHoursWorked > 0) {
            hoursWorked = newHoursWorked;
        } else {
            hoursWorked = 0;
        }
    }

    float salaryCEO() {
        int weeklyBonus = 100000;
        if (strcmp(position, "CEO") == 0) {
            return weeklyBonus * 4;
        } else {
            return 0;
        }
    }

    float salary() {
        float rate = 20000;
        if (strcmp(position, "CEO") == 0) {
            return rate * hoursWorked + salaryCEO();
        } else {
            return rate * hoursWorked;
        }
    }

    bool addWorkedHours(float hours) {
        if (hours >= 0 && hours <= 24) {
            hoursWorked += hours;
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    cout << "Niit heden ajiltan bn ve? ";
    int n;
    cin >> n;
    Worker w[n];

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "r ajiltnii medeelel" << endl;
        int id;
        float hours;
        char name[20], position[10];

        w[i].setWorkerId(w, i, n);

        cout << "Name: ";
        cin>>name;
        w[i].setName(name);

        cout << "Position: ";
        cin>>position;
        w[i].setPosition(position);

        cout << "Hours Worked: ";
        cin >> hours;
        w[i].setHoursWorked(hours);

        cout << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(w[j].getName(), w[j + 1].getName()) > 0) {
                Worker temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }

    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Worker ID: " << w[i].getWorkerId() << endl;
        cout << "Name: " << w[i].getName() << endl;
        cout << "Position: " << w[i].getPosition() << endl;
        cout << "Hours Worked: " << w[i].getHoursWorked() << endl;
        cout << "Salary: " << w[i].salary() << endl;
        cout << endl;
    }

    return 0;
}
