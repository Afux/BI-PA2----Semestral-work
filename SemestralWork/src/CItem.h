
#ifndef SEMESTRALWORK_CITEM_H
#define SEMESTRALWORK_CITEM_H

#include "iostream"
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
    CItem* m_inFolder;
    std::map<std::string ,std::shared_ptr<CItem>> m_items;

    virtual void Print()=0;
    virtual void Open(std::map<std::string ,std::shared_ptr<CItem>> **item,CItem ** inFold)=0;
    virtual void Delete()=0;
    virtual void Move(std::string dest)=0;
    virtual void Copy( std::string dest )=0;
    virtual void FindText(std::string FindThis,std::vector<CItem*> *Found)=0;
    virtual void ConCat(std::string To)=0;
    virtual void Deduplicate(CItem * DeduplicateMe)=0;
    virtual std::string RemoveDialog()=0;
    virtual std::string CreateDialog(std::string NewName)=0;
    virtual std::string RenameDialog(std::string NewName)=0;
    bool IsReadable();
protected:
    bool IsReadable(const std::filesystem::path& p);
    bool IsWriteable(const std::filesystem::path& p);


};


#endif //SEMESTRALWORK_CITEM_H
