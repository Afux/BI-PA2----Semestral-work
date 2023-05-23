
#ifndef SEMESTRALWORK_CITEM_H
#define SEMESTRALWORK_CITEM_H
#include "iostream"
#include "CDate.h"
#include "CPermission.h"
#include "vector"

using namespace std;

class CItem {
    CItem(string name, string path,string type, CDate date,unsigned int size);

public:
    string m_Name;
    string m_Path;
    string m_Type;
    CDate m_Date;
    unsigned int m_Size;
    vector<CPermission> m_Permisions;
private:
protected:

    virtual void Print()=0;
    virtual void Copy( CItem *item )=0;
    virtual void Copy(vector<CItem*>)=0;
    virtual void Delete( CItem *item )=0;
    virtual void Delete(vector<CItem*> items)=0;
    virtual void Move( CItem *item , string dest)=0;
    virtual void Move(vector<CItem*>,string dest )=0;

    void Rename( CItem *item );

    void Rename(vector<CItem*> items);

    virtual unsigned int GetSize()=0;
    virtual void SetDate(u_int year, u_int month, u_int day)=0;
    virtual void Deduplicate()=0;

};


#endif //SEMESTRALWORK_CITEM_H
