#include <iostream>


using namespace std;

class Person
{
private:

public:
    char name[10];
    char lname[10];
    int age;
    virtual void showing()
    {
        cout << "Base" << endl;
    }
    virtual void creating()
    {
        cout << "Base create" << endl;
    }

    void set_person()
    {
        cout << "Enter name: "; cin >> name;
        cout << "Enter last name: "; cin >> lname;
        cout << "Enter age: "; cin >> age;
    }
};

class Student : public Person
{
private:
    int GPA;
public:
    void creating()
    {
        cout << "Student: " << endl;
        set_person();
        cout << "Enter GPA: "; cin >> GPA;
    }
    void showing()
    {
        cout << "Student: " << name << ' ' << lname << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << GPA << endl;
    }

};

class  Professor : public Person
{
private:
    int salary;
public:
    void creating()
    {
        cout << "Professor: " << endl;
        set_person();
        cout << "Enter salary: "; cin >> salary;
    }
    void showing()
    {
        cout << "Professor: " << name << ' ' << lname << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }

};
void create_person(Person &m)
{
    m.creating();
}

void show_person(Person &m)
{
     m.showing();
}

int main(int argc, char *argv[])
{
    Person base_obj;
    Student std1;
    Professor prf1;

    create_person(std1);
    cout << "=====================" << endl;
    show_person(std1);
    cout << "=========== P ==========" << endl;
    create_person(prf1);
    cout << "=====================" << endl;
    show_person(prf1);

return 0;
}

