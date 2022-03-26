#include "PersonDetails.h"
int PersonDetails:: m_index=0;
PersonDetails::PersonDetails()
{
    cout<<"Person details constructor"<<endl;
    m_count = 0;
}

PersonDetails::~PersonDetails()
{
    cout<<"Person details destructor"<<endl;
}

void PersonDetails::init()
{
    cout<<"Person init function"<<endl;
    cout<<"Enter how many details do you want to write to file"<<endl;
    cin>>m_count;
    for(int i=0;i<m_count;i++)
    {
        cout<<"Enter name"<<endl;
        cin>>m_name;
        cout<<"Enter age"<<endl;
        cin>>m_age;
        cout<<"Enter salary"<<endl;
        cin>>m_salary;

        string person_data = m_name+","+to_string(m_age)+","+to_string(m_salary);
        cout<<"Enter the type in which you want to save the data"<<endl;
        cin>>choice;

        switch(choice)
        {
        case CSV : csv = new CSVFormat;
                   csv->saveData(++m_index,person_data);
                  break;
        case DB : static FilesFormat *db = new DBFormat;
                  db->saveData(++m_index,person_data);
                  break;
        default : cout<<"Entered option is invalid"<<endl;
                  break;
        }
    }
    csv->readData();
    option();
}

void PersonDetails::option()
{
    cout<<"Enter your option"<<endl;
    cout<<"Do your operation"<<endl;
    cout<<"1.Enter data"<<"\n"<<"2.Delete data"<<"\n"<<"3.Read data"<<"\n"<<"4.Exit"<<endl;
    cin>>choice;
    switch(choice)
    {
    case ENTERDATA :init();
              break;
    case DELETEDATA : csv->deleteData();
              break;
    case READDATA:readOption();
    case EXIT:exit(0);
    default : cout<<"Entered option is invalid"<<endl;
              break;
    }
}

void PersonDetails::readOption()
{
    cout<<"Enter from which file you want to read"<<endl;
    cout<<"1.CSV"<<"\n"<<"2.DB"<<"\n"<<endl;
    cin>>choice;
    switch(choice)
    {
    case CSV :csv->readData();
              break;
    case DB : db->readData();
              break;
    default : cout<<"Entered option is invalid"<<endl;
              break;
    }
}

void PersonDetails::setName(const string Name)
{
    cout<<"Set name function"<<endl;
    m_name = Name;
}
string PersonDetails::getName() const
{
    cout<<"get name function"<<endl;
    return m_name;
}

void PersonDetails::setAge(const int Age)
{
    cout<<"Set age function"<<endl;
    m_age = Age;
}

int PersonDetails::getAge() const
{
    cout<<"get age function"<<endl;
    return m_age;
}

void PersonDetails::setSalary(const float Salary)
{
    cout<<"Set salary function"<<endl;
    m_salary = Salary;
}

float PersonDetails::getSalary() const
{
    cout<<"get salary function"<<endl;
    return m_salary;
}
