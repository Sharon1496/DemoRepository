#ifndef FILESFORMAT_H
#define FILESFORMAT_H
#include "CommonUtils.h"


class FilesFormat
{
public:
    FilesFormat();
    ~FilesFormat();
    virtual void saveData(int index,string data);
    virtual void readData();
    virtual void deleteData();

};

#endif // FILESFORMAT_H
