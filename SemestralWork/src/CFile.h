
#ifndef SEMESTRALWORK_CFILE_H
#define SEMESTRALWORK_CFILE_H

#include "CItem.h"
using namespace std;
class CFile: public CItem{
public:
    CFile(std::string path,unsigned int size);
   // CFile* Concat(vector<CItem*> items);
    virtual void Print() override;
    virtual void Copy( CItem *item ) override;
    virtual void Copy(vector<CItem*>) override;
    virtual void Delete( CItem *item ) override;
    virtual void Delete(vector<CItem*> items) override;
    virtual void Move( CItem *item , string dest) override;
    virtual void Move(vector<CItem*>,string dest ) override;
    virtual void UpdateSize() override;
    virtual void SetDate(u_int year, u_int month, u_int day) override;
    virtual void Deduplicate() override;
    virtual std::string RemoveDialog() override;
    virtual std::string CreateDialog() override;
    virtual std::string RenameDialog() override;
    virtual void Open(std::vector<CItem*> **item)override;

};


#endif //SEMESTRALWORK_CFILE_H
