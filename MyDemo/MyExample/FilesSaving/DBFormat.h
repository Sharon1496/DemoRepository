#ifndef DBFORMAT_H
#define DBFORMAT_H
#include "FilesFormat.h"
#include "CommonUtils.h"
#include <QObject>
#include <QSqlDatabase>
class PersonDetails;
class DBFormat:public FilesFormat, public QObject
{
public:
    DBFormat();
    ~DBFormat();
    void saveData(int index,string data);
    void readData();
    void deleteData();
private:
    string name;
    QSqlDatabase m_db;
    int age;
    float salary;
};

#endif // DBFORMAT_H
