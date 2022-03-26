#include "DBFormat.h"
#include "PersonDetails.h"
DBFormat::DBFormat()
{
    cout<<"DB constructor"<<endl;
    m_db.addDatabase("SQLITE");
    m_db.setDatabaseName("MyDb.db");
}

DBFormat::~DBFormat()
{
    cout<<"DB destructor"<<endl;
}

void DBFormat::saveData(int index,string data)
{
    cout<<"DB save data"<<endl;
}

void DBFormat::readData()
{
    cout<<"DB read data"<<endl;
}

void DBFormat::deleteData()
{
cout<<"DB Format delete data"<<endl;
}


