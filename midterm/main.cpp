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

    Worker(const Worker& other) : workerId(other.workerId), hoursWorked(other.hoursWorked) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        position = new char[strlen(other.position) + 1];
        strcpy(position, other.position);
    }

    bool checkExistingId(const Worker* w, int index, int newId) const {
        for (int j = 0; j < index; j++) {
            if (w[j].getWorkerId() == newId) {
                cout << newId << " IDtai ajiltan burtgegdsen bn. Shalgana uu" << endl;
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

    void setWorkerId(const Worker* w, int index) {
        int id;
        bool idExists;
        do {
            cout << "Worker ID: ";
            cin >> id;
            idExists = checkExistingId(w, index, id);
        } while (idExists);
        workerId = id;
    }

    void setName(const char newName[]) {
        if (name) delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    void setPosition(const char newPosition[]) {
        if (position) delete[] position;
        position = new char[strlen(newPosition) + 1];
        strcpy(position, newPosition);
    }

    void setHoursWorked(float newHoursWorked) {
        hoursWorked = (newHoursWorked >= 0 && newHoursWorked <= 24) ? newHoursWorked : 0;
    }

    float salaryCEO() {
        int weeklyBonus = 100000;
        return (strcmp(position, "CEO") == 0) ? (weeklyBonus * 4) : 0;
    }

    float salary() {
        float rate = 20000;
        return (strcmp(position, "CEO") == 0) ? (rate * hoursWorked + salaryCEO()) : (rate * hoursWorked);
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

void bubbleSortByName(Worker w[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(w[j].getName(), w[j + 1].getName()) > 0) {
                Worker temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
}

void bubbleSortBySalary(Worker w[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (w[j].salary() < w[j + 1].salary()) {
                Worker temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
}

int main() {
    cout << "Niit heden ajiltan bn ve? ";
    int n;
    cin >> n;
    Worker w[n];

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "r ajiltnii medeelel" << endl;
        char name[20], position[10];
        float hours;

        w[i].setWorkerId(w, i);

        cout << "Name: ";
        cin >> name;
        w[i].setName(name);

        cout << "Position: ";
        cin >> position;
        w[i].setPosition(position);

        cout << "Hours Worked: ";
        cin >> hours;
        w[i].setHoursWorked(hours);

        cout << endl;
    }

    bubbleSortByName(w, n);


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
