#ifndef PERSONDETAILS_H
#define PERSONDETAILS_H
#include "CommonUtils.h"
#include "FilesFormat.h"
#include "CSVFormat.h"
#include "DBFormat.h"


class PersonDetails
{
    enum Choice{
        CSV = 1,
        DB = 2
    };
    enum Operations{
        ENTERDATA = 1,
        DELETEDATA = 2,
        READDATA = 3,
        EXIT = 4
    };

public:
    PersonDetails();
    ~PersonDetails();

    void init();
    void print();
    void option();
    void readOption();
    void setName(const string Name);
    string getName() const;

    void setAge(const int Age);
    int getAge() const;

    void setSalary(const float Salary);
    float getSalary() const;

private:
    int choice;
    FilesFormat *csv,*db;
    string m_name;
    int m_age;
    float m_salary;
    static int m_index;
    int m_count;
};

#endif // PERSONDETAILS_H
