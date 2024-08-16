#include <iostream>
#include <string>

using namespace std;

class Employee  {
public:
  string name;
  string position;
  int age;
  Employee(const string& n = "Praskouya Horbach", const string& pos = "CEO", int a = 19) : name(n), position(pos), age(a){};
};

ostream& operator<< (ostream& os, Employee emp) {
  cout << "Name: " << emp.name << "\nPosition: " << emp.position << "\nAge: " << emp.age << endl;
  return os;
}
