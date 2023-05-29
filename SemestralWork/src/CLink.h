
#ifndef SEMESTRALWORK_CLINK_H
#define SEMESTRALWORK_CLINK_H
#include "CItem.h"
using namespace std;
class CLink:public CItem {
public:
    CItem* m_toFile;
    virtual void Open(std::vector<CItem*> **item)override;

    virtual void Print()override;
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
};


#endif //SEMESTRALWORK_CLINK_H
