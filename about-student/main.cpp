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
public:
    void where()
    {
        cout << "Professor: " << endl;

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
    Student f_obj;
    Professor s_obj;

    create_person(f_obj);
    cout << "=====================" << endl;
    show_person(f_obj);


return 0;
}

