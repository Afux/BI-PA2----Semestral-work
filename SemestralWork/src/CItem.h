
#ifndef SEMESTRALWORK_CITEM_H
#define SEMESTRALWORK_CITEM_H

#include "iostream"
#include "CDate.h"
#include "CPermission.h"
#include "vector"
#include "map"
#include <memory>
#include <iostream>
class CItem {


public:
    CItem(std::string path,unsigned int size,CItem* inFolder);
    virtual ~CItem();
    std::string m_Name;
    std::string m_Path;
    //CDate m_Date;
    //virtual void Add()=0;
    unsigned int m_Size;
    std:: vector<CPermission> m_Permisions;
    virtual void Print()=0;
    virtual void Open(std::vector< std::shared_ptr<CItem>> **item,CItem ** inFold)=0;
    virtual void Delete()=0;
    virtual void Delete(std::vector< std::shared_ptr<CItem>> items)=0;
    virtual void Move(std::string dest)=0;
    virtual void Move(std::vector< std::shared_ptr<CItem>> items,std::string dest )=0;
    virtual void Copy( std::string dest )=0;
    virtual void Copy(std::vector< std::shared_ptr<CItem>> items, std::string dest)=0;
    virtual void FindText(std::string FindThis,std::vector<CItem*> *Found)=0;
    CItem* m_inFolder;
    virtual std::shared_ptr<CItem>  clone() const=0;
    std::vector< std::shared_ptr<CItem>> m_items;
    virtual void Deduplicate(CItem * DeduplicateMe)=0;

private:
protected:


    virtual std::string RemoveDialog()=0;
    virtual std::string CreateDialog(std::string NewName)=0;
    virtual std::string RenameDialog(std::string NewName)=0;


    virtual void SetDate(u_int year, u_int month, u_int day)=0;

    virtual void UpdateSize()=0;
};


#endif //SEMESTRALWORK_CITEM_H
