#ifndef CSVFORMAT_H
#define CSVFORMAT_H
#include "fstream"
#include "string.h"
#include "FilesFormat.h"
#include "CommonUtils.h"
//#include "PersonDetails.h"

class PersonDetails;
class CSVFormat:public FilesFormat
{
  public:
    CSVFormat();
    ~CSVFormat();
    void saveData(int index, string data);
    void readData();
    void deleteData();
private:

    string name;
    int age;
    float salary;
    int index;
    int choice;
    int index_delete;
    static int m_index;
};

#endif // CSVFORMAT_H
