
#ifndef SEMESTRALWORK_CLINK_H
#define SEMESTRALWORK_CLINK_H
#include "CItem.h"
#include "CDir.h"
using namespace std;
class CLink:public CItem {
public:
    CLink(std::string path,unsigned int size,CItem* toFile,CItem* parr);

    CItem* m_toFile;
    virtual void Open(std::vector<CItem*> **item)override;

     void Print()override;
     void Copy(vector<CItem*> items, std::string to ) override;
     void Copy(std::string to) override;
     void Delete() override;
    void Delete(vector<CItem*> items) override;
     void Move( string dest) override;
     void Move(vector<CItem*>,string dest ) override;
     void UpdateSize() override;
     void SetDate(u_int year, u_int month, u_int day) override;
     void Deduplicate() override;
     std::string RemoveDialog() override;
     std::string CreateDialog(std::string NewName) override;
     std::string RenameDialog(std::string NewName) override;
     CItem* Clone() override;
};


#endif //SEMESTRALWORK_CLINK_H
