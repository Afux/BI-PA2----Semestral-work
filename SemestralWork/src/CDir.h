
#ifndef SEMESTRALWORK_CDIR_H
#define SEMESTRALWORK_CDIR_H
#include "CItem.h"

class CDir: public CItem{
public:
    CDir(std::string path,unsigned int size,CItem* inFolder);
    CDir(const CDir& rhs);

    std::shared_ptr<CItem>  clone() const override;

    void Open(std::map<std::string ,std::shared_ptr<CItem>> **item,CItem ** inFold)override;

     void Copy(std::string to) override;
     void Delete() override;
     void Move( std::string dest) override;
     void SetDate(u_int year, u_int month, u_int day) override;
     void Deduplicate(CItem * DeduplicateMe) override;
     void Print() override;
     void FindText(std::string FindThis,std::vector<CItem*> * Found) override;
     void ConCat(std::string To) override;
    void FillItems();
    void Refresh();
    std::string RemoveDialog() override;
     std::string CreateDialog(std::string NewName) override;
     std::string RenameDialog(std::string NewName) override;

protected:
    void UpdateSize() override;

};


#endif //SEMESTRALWORK_CDIR_H
