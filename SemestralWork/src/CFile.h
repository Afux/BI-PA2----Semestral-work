
#ifndef SEMESTRALWORK_CFILE_H
#define SEMESTRALWORK_CFILE_H

#include "CItem.h"
#include "CDir.h"
using namespace std;
class CFile: public CItem{
public:
    CFile(std::string path,unsigned int size, CItem * parr);
   // CFile* Concat(vector<CItem*> items);
    virtual void Print() override;
    virtual void Copy(vector<CItem*> items, std::string to ) override;
    virtual void Copy(std::string to) override;
    virtual void Delete() override;
    virtual void Delete(vector<CItem*> items) override;
    virtual void Move( string dest) override;
    virtual void Move(vector<CItem*>,string dest ) override;

    virtual void UpdateSize() override;
    virtual void SetDate(u_int year, u_int month, u_int day) override;
    virtual void Deduplicate() override;
    virtual std::string RemoveDialog() override;
    virtual std::string CreateDialog(std::string NewName) override;
    virtual std::string RenameDialog(std::string NewName) override;
    virtual void Open(std::vector<CItem*> **item)override;

};


#endif //SEMESTRALWORK_CFILE_H
