
#ifndef SEMESTRALWORK_CLINK_H
#define SEMESTRALWORK_CLINK_H
#include "CItem.h"
using namespace std;
class CLink:public CItem {
public:
    CItem* m_toFile;
    virtual void Print()override;
    virtual void Copy( CItem *item ) override;
    virtual void Copy(vector<CItem*>) override;
    virtual void Delete( CItem *item ) override;
    virtual void Delete(vector<CItem*> items) override;
    virtual void Move( CItem *item , string dest) override;
    virtual void Move(vector<CItem*>,string dest ) override;
    virtual unsigned int GetSize() override;
    virtual void SetDate(u_int year, u_int month, u_int day) override;
    virtual void Deduplicate() override;
};


#endif //SEMESTRALWORK_CLINK_H
