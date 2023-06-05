
#ifndef SEMESTRALWORK_CITEM_H
#define SEMESTRALWORK_CITEM_H

#include "iostream"
#include "CDate.h"
#include "CPermission.h"
#include "vector"
#include "map"
#include <memory>
#include <iostream>
#include <filesystem>
class CItem {


public:
    CItem(std::string path,unsigned int size,CItem* inFolder);
    virtual ~CItem();
    std::string m_Name;
    std::string m_Path;
    bool m_isSelected;
    void Select();

    unsigned int m_Size;
    std:: vector<CPermission> m_Permisions;
    CItem* m_inFolder;
    virtual std::shared_ptr<CItem>  clone() const=0;
    std::map<std::string ,std::shared_ptr<CItem>> m_items;

    virtual void Print()=0;
    virtual void Open(std::map<std::string ,std::shared_ptr<CItem>> **item,CItem ** inFold)=0;
    virtual void Delete()=0;
    virtual void Delete(std::map<std::string ,std::shared_ptr<CItem>> items)=0;
    virtual void Move(std::string dest)=0;
    virtual void Move(std::map<std::string ,std::shared_ptr<CItem>> items,std::string dest )=0;
    virtual void Copy( std::string dest )=0;
    virtual void Copy(std::map<std::string ,std::shared_ptr<CItem>> items, std::string dest)=0;
    virtual void FindText(std::string FindThis,std::vector<CItem*> *Found)=0;
    virtual void ConCat(std::string To)=0;
    virtual void Deduplicate(CItem * DeduplicateMe)=0;
    virtual void UpdateSize()=0;



private:
protected:

    bool IsReadable(const std::filesystem::path& p);
    bool IsWriteable(const std::filesystem::path& p);
    virtual std::string RemoveDialog()=0;
    virtual std::string CreateDialog(std::string NewName)=0;
    virtual std::string RenameDialog(std::string NewName)=0;
    virtual void SetDate(u_int year, u_int month, u_int day)=0;
};


#endif //SEMESTRALWORK_CITEM_H
