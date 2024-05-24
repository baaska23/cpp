// 5. Ажилчин гэсэн класс тодорхойлно. Ажилчдын ажилласан цаг бүрийг өөрчилж цалинг тооцоолох жижиг програм бич.

// +Дугаар : int
// +Нэр : char[20]
// +Албан тушаал : char[10]
// +Ажилласан цаг : float

// -------------------------------------------------------
// +Гарааны утга оноох() : void // дугаар=0, нэр="", албан тушаал="ажилчин", ажилласан цаг=0
// +Гараас утга авах() : void
// +Мэдээлэл дэлгэцлэх() : void
// +Цалин бодох() : float // хэрэв албан тушаал нь захирал байвал Захирлын цалин бодох() функцийг дуудаж үндсэн цалин дээр нэмнэ
// +Захирлын цалин бодох() : float
// ???+Ажилласан цаг нэмэгдүүлэх(float) : boolean /0, 1/
// //"Ажилласан цаг" гэсэн шинжийг нэмэгдүүлэх бөгөөд 0-оос 24-ийн хооронд утга авч байгааг шалгаад хэрэв амжилттай болвол ажилласан цагийг нэмэгдүүлээд 1, үгүй бол нэмэгдүүлэхгүйгээр 0 гэсэн утга буцаана

#include <iostream>
using namespace std;

class Worker{
    public:
        int workerId;
        char name[20];
        char position[10];
        float hoursWorked;
    
    public:
        void initialValue(){
            workerId = 0;
            strcpy(name, "");
            strcpy(position, "ажилчин");
            hoursWorked = 0;
        }

        void getInfo(){
            cout<<"Ajiltnii dugaar: ";
            cin>>workerId;
            cout<<"Ajiltnii ner: ";
            cin>>name;
            cout<<"Ajiltnii alban tushaal: ";
            cin>>position;
            cout<<"Ajilsan tsag: ";
            cin>>hoursWorked;
        }

        void showInfo(){
            cout<<"Ajiltnii dugaar: "<<workerId<<endl;
            cout<<"Ajiltnii ner: "<<name<<endl;
            cout<<"Ajiltnii alban tushaal: "<<position<<endl;
            cout<<"Ajilsan tsag: "<<hoursWorked<<endl;
        }

        float salaryCEO(){
            int weeklyBonus = 100000;
            if(strcmp(position, "CEO")== 0){
                return weeklyBonus*4;
            } else return 0;
        }

        float salary(){
            float rate = 20000;
            if(strcmp(position, "CEO") == 0){
                return rate*hoursWorked + salaryCEO();
            } else return rate*hoursWorked;
        }

        bool addWorkedHours(float hours) {
        if (hours >= 0 && hours <= 24) {
            hoursWorked += hours;
            return true; 
        }
        else return false;
    }
};

int main(){
    Worker w1;
    w1.getInfo();
    w1.showInfo();
    float tsalin = w1.salary();
    cout<<"Ajiltnii tsalin bol: "<<tsalin<<endl;
    
}
