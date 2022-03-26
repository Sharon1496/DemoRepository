#include "CSVFormat.h"
#include "PersonDetails.h"
CSVFormat::CSVFormat()
{
    cout<<"CSV constructor"<<endl;
}

CSVFormat::~CSVFormat()
{
    cout<<"CSV destructor"<<endl;
}

void CSVFormat::saveData(int index,string data)
{
    cout<<"CSV save data"<<endl;
    fstream file;
    file.open("C:\\C++ Training Tasks\\Week 2\\Persondetails.csv",ios::out | ios::app);

    if(!file)
    {
        cout<<"File opening failed"<<endl;
    }
    else
    {
        cout<<"File opening is successful"<<endl;
        cout<<"Before file write"<<endl;
        file<<index<<","<<data<<"," << endl;
        cout<<"After file write"<<endl;
    }
    file.close();

}
void CSVFormat::readData()
{
    cout<<"CSV read data"<<endl;
    fstream file1;
    file1.open("C:\\C++ Training Tasks\\Week 2\\Persondetails.csv",ios::in);
    if(!file1)
    {
        cout<<"File opening failed"<<endl;
    }
    else
    {
        cout<<"File opening is successful"<<endl;
        string line;
        while(!file1.eof())
        {
            //            file1>>line;
            getline(file1,line);
            cout<<line<<" "<<endl;
        }
    }
}

void CSVFormat::deleteData()
{
    cout<<"CSV delete data"<<endl;
    string sub_index,refined_data;
    fstream file2,file3;
    file2.open("C:\\C++ Training Tasks\\Week 2\\Persondetails.csv",ios::in /*| ios::app*/);
    if(!file2)
    {
        cout<<"File opening failed"<<endl;
    }
    else
    {
        cout<<"File opening is successful"<<endl;
        cout<<"Enter the index of data you want to delete"<<endl;
        cin>>index_delete;
        int myIndex = 0;
        while(!file2.eof())
        {
            getline(file2,sub_index);
            //            file2>>sub_index;
            cout<<sub_index<<endl;
            if (sub_index.size() > 0)
            {
                if(!sub_index.find(to_string(index_delete)))
                {
                    cout<<"Substring found"<<endl;
                }
                else
                {
                    cout<<"Substring not found"<<endl;
                    //                refined_data += sub_index + "\n";
                    refined_data += to_string(++myIndex) + sub_index.erase(0,sub_index.find(",")) + "\n";
                }
            }
        }
        cout<<refined_data<<endl;
    }
    file2.close();

    file3.open("C:\\C++ Training Tasks\\Week 2\\Persondetails.csv",ios::out);
    if(!file3)
    {
        cout<<"File opening failed"<<endl;
    }
    else
    {
        cout<<"File opening is successful"<<endl;
        cout<<"Before file write"<<endl;
        file3<<refined_data;
        cout<<"After file write"<<endl;
    }
    file3.close();
}
