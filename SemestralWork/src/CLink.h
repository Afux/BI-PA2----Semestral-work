
#ifndef SEMESTRALWORK_CLINK_H
#define SEMESTRALWORK_CLINK_H
#include "CItem.h"
#include "CDir.h"
class CLink:public CItem {
public:
    CLink(std::string path,unsigned int size,CItem* toFile,CItem* parr);

    CItem* m_toFile;
     void Open(std::map<std::string ,std::shared_ptr<CItem>> **item,CItem ** inFold)override;

     void Print()override;
     void Copy(std::map<std::string ,std::shared_ptr<CItem>> items, std::string to ) override;
     void Copy(std::string to) override;
     void Delete() override;
     void Delete(std::map<std::string ,std::shared_ptr<CItem>> items) override;
     void Move( std::string dest) override;
     void Move(std::map<std::string ,std::shared_ptr<CItem>> items,std::string dest ) override;
     void UpdateSize() override;
     void SetDate(u_int year, u_int month, u_int day) override;
     void Deduplicate(CItem * DeduplicateMe) override;
    void FindText(std::string FindThis,std::vector<CItem*> *Found) override;
    std::string RemoveDialog() override;
     std::string CreateDialog(std::string NewName) override;
     std::string RenameDialog(std::string NewName) override;
    std::shared_ptr<CItem>  clone() const override;
    void ConCat(std::string To) override;


};


#endif //SEMESTRALWORK_CLINK_H
