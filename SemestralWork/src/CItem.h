
#ifndef SEMESTRALWORK_CITEM_H
#define SEMESTRALWORK_CITEM_H
#include "iostream"
#include "CDate.h"
#include "CPermission.h"
#include "vector"


class CItem {


public:
    CItem(std::string path,unsigned int size);
    std::string m_Name;
    std::string m_Path;
    //CDate m_Date;
    unsigned int m_Size;
    std:: vector<CPermission> m_Permisions;
    virtual void Print()=0;
    virtual void Open(std::vector<CItem*> **item)=0;
    virtual void Delete( CItem *item )=0;


private:
protected:

    virtual void Copy( CItem *item )=0;
    virtual void Copy(std::vector<CItem*>)=0;
    virtual void Delete(std::vector<CItem*> items)=0;
    virtual void Move( CItem *item , std::string dest)=0;
    virtual void Move(std::vector<CItem*>,std::string dest )=0;
    virtual std::string RemoveDialog()=0;
    virtual std::string CreateDialog()=0;
    virtual std::string RenameDialog()=0;
    void Rename( CItem *item );

    void Rename(std::vector<CItem*> items);

    virtual void SetDate(u_int year, u_int month, u_int day)=0;
    virtual void Deduplicate()=0;

    virtual void UpdateSize()=0;
};


#endif //SEMESTRALWORK_CITEM_H
