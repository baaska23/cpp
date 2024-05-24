#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
  Course(const string& subject) : subject_(subject) {}

  void setTeacher(const string& teacher) {
    teacher_ = teacher;
  }

  const string& getSubject() const {
    return subject_;
  }

  const string& getTeacher() const {
    return teacher_;
  }

private:
  string subject_;
  string teacher_;
};

class Student {
public:
  Student(int id) : id_(id) {}

  void setAttendance(const string& attendance) const {
    attendance_ = attendance;
  }

  int getId() const {
    return id_;
  }

  const string& getAttendance() const {
    return attendance_;
  }

private:
  int id_;
  mutable string attendance_; 
};

int main() {
  string subject;
  cout << "Hicheeliin ner: ";
  getline(cin, subject);

  Course course(subject);

  string teacher;
  cout << "Bagshiin ner: ";
  getline(cin, teacher);
  course.setTeacher(teacher);

  vector<Student> students;
  int numStudents;
  cout << "Oyutnii too: ";
  cin >> numStudents;
  cin.ignore();

  for (int i = 0; i < numStudents; ++i) {
    int id;
    cout << "Oyutnii ID (" << i + 1 << "): ";
    cin >> id;
    cin.ignore();
    students.push_back(Student(id));
  }

  cout << "\nCourse: " << course.getSubject() << endl;
  cout << "Teacher: " << course.getTeacher() << endl;

  for (const Student& student : students) { 
    string attendance;
    cout << "Oyutnii irtsiin baidal " << student.getId() << " (present, absent, sick, free, late): ";
    getline(cin, attendance);
    student.setAttendance(attendance);
  }

  cout << "\nOyutnii Irts:\n";
  cout << "ID ba Irts\n";
  for (const Student& student : students) {
    cout << student.getId() << "\t" << student.getAttendance() << endl;
  }

  return 0;
}
