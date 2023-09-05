#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    string address;
    string sex;

public:
    Person()
    {
    }
    Person(string _name, string _address, string _sex) : name(_name), address(_address), sex(_sex)
    {
    }

    virtual ~Person() {}

    string GetPersonName()
    {
        return name;
    }
    string GetPersonAddress()
    {
        return address;
    }
    string GetPersonSex()
    {
        return sex;
    }
};

class Teacher : Person
{
private:
    vector<Course *> courses;

public:
    Teacher()
    {
    }
};

class Student : Person
{
private:
    vector<Course *> courses;
    vector<Teacher *> teachers;

public:
    Student(Person &_person) : Person(_person)
    {
    }
    void AddTeachers(Teacher *_teacher)
    {
        teachers.push_back(_teacher);
    }
    void AddCourse(Course *_course)
    {
        courses.push_back(_course);
    }
};

class Course
{
public:
    Course() {}

private:
    string name;
};
