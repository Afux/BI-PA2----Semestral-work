
#ifndef SEMESTRALWORK_CDIR_H
#define SEMESTRALWORK_CDIR_H

#include "CItem.h"
class CDir: public CItem{
public:
    CDir(std::string path,unsigned int size,CDir* Parr,CItem* inFolder);
    std::vector<CItem*>m_items;
    std::vector<CItem*>m_currItems;
    //std::map<std::string,CItem*> m_items;
    CDir * m_parr;
    std::vector<CItem*>* FindDir(const std::string& path);
    virtual void Open(std::vector<CItem*> **item)override;

    virtual void Copy(std::vector<CItem*> items, std::string to ) override;
    virtual void Copy(std::string to) override;
    virtual void Delete() override;
    virtual void Delete(std::vector<CItem*> items) override;
    virtual void Move( std::string dest) override;
    virtual void Move(std::vector<CItem*>,std::string dest ) override;
    virtual void UpdateSize() override;
    virtual void SetDate(u_int year, u_int month, u_int day) override;
    virtual void Deduplicate() override;
    virtual void Print() override;
    virtual std::string RemoveDialog() override;
    virtual std::string CreateDialog(std::string NewName) override;
    virtual std::string RenameDialog(std::string NewName) override;
    std::vector<std::string> parseString(const std::string& input, char delimiter);
};


#endif //SEMESTRALWORK_CDIR_H
