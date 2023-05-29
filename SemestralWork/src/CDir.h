
#ifndef SEMESTRALWORK_CDIR_H
#define SEMESTRALWORK_CDIR_H

#include "CItem.h"

class CDir: public CItem{
public:
    CDir(std::string path,unsigned int size,CDir* Parr);
    std::vector<CItem*>m_items;
    std::vector<CItem*>m_currItems;
    //std::map<std::string,CItem*> m_items;
    CDir * m_parr;
    virtual void Open(std::vector<CItem*> **item)override;

    virtual void Copy( CItem *item ) override;
    virtual void Copy(std::vector<CItem*>) override;
    virtual void Delete( CItem *item ) override;
    virtual void Delete(std::vector<CItem*> items) override;
    virtual void Move( CItem *item , std::string dest) override;
    virtual void Move(std::vector<CItem*>,std::string dest ) override;
    virtual void UpdateSize() override;
    virtual void SetDate(u_int year, u_int month, u_int day) override;
    virtual void Deduplicate() override;
    virtual void Print() override;
    virtual std::string RemoveDialog() override;
    virtual std::string CreateDialog() override;
    virtual std::string RenameDialog() override;

};


#endif //SEMESTRALWORK_CDIR_H
