// Хэрэгжүүлэлт:
// Лаб04 - д тодорхойлсон классын нэр:char[20], албан тушаал:char[10] гэсэн гишүүн өгөгдлийг хаяган хувьсагч болгон өөрчилж гараас өгсөн тэмдэгтийн цуваатай яг ижил урттай санах ой new оператор ашиглан нөөцөлдөг болго. 
// Үүний тулд анхдагч болон параметертэй байгуулагч функцууд тодорхойлж гишүүн өгөгдөлд гарааны утга онооно. Мөн объект устах үед дээрх хоёр гишүүн өгөгдөлд нөөцөлсөн санайх ойг чөлөөлдөг болгож өөрчил.
// Өөрчлөлтийг оруулаад дараах даалгаврыг гүйцэтгэ
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

    // huulagch baiguulagch
    Worker(const Worker& other) : workerId(other.workerId), hoursWorked(other.hoursWorked) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        position = new char[strlen(other.position) + 1];
        strcpy(position, other.position);
    }

    

    // Getter and setter functions
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
        return hoursWorked > 0;
    }

    void setWorkerId(int newWorkerId) {
        workerId = newWorkerId;
    }

    void setName(const char newName[]) {
        if (name) delete[] name; // Release existing memory
        name = new char[strlen(newName) + 1]; // Allocate memory
        strcpy(name, newName); // Copy string
    }

    void setPosition(const char newPosition[]) {
        if (position) delete[] position; // Release existing memory
        position = new char[strlen(newPosition) + 1]; // Allocate memory
        strcpy(position, newPosition); // Copy string
    }

    void setHoursWorked(float newHoursWorked) {
        hoursWorked = newHoursWorked;
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
        if(hoursWorked < 0){
            return 0;
        }
        float rate = 20000;
        if (strcmp(position, "CEO") == 0) {
            return rate * hoursWorked + salaryCEO();
        } else {
            return rate * hoursWorked ;
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

        bool idExists = false;
        do {
            cout << "Worker ID: ";
            cin >> id;
            idExists = false;
            for (int j = 0; j < i; j++) {
                if (w[j].getWorkerId() == id) {
                    cout << id<< " IDtai ajiltan " << " burtgegdsen bn. Shalgana uu" << endl;
                    idExists = true;
                    break;
                }
            }
        } while (idExists);

        w[i].setWorkerId(id);

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