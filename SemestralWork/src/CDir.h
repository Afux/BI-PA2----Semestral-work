
#ifndef SEMESTRALWORK_CDIR_H
#define SEMESTRALWORK_CDIR_H
#include "CItem.h"

class CDir: public CItem{
public:
    CDir(std::string path,unsigned int size,CItem* Parr,CItem* inFolder);
    CDir(const CDir& rhs);

    std::vector< std::shared_ptr<CItem>> m_currItems;
    //std::map<std::string,CItem*> m_items;
    CItem* m_parr;
    std::vector< std::shared_ptr<CItem>> * FindDir(const std::string& path,CItem **item);
    std::shared_ptr<CItem>  clone() const override;

    CItem *m_DeleteMe;
    void Open(std::vector< std::shared_ptr<CItem>> **item,CItem ** inFold)override;

     void Copy(std::vector< std::shared_ptr<CItem>> items, std::string to ) override;
     void Copy(std::string to) override;
     void Delete() override;
     void Delete(std::vector< std::shared_ptr<CItem>> items) override;
     void Move( std::string dest) override;
     void Move(std::vector< std::shared_ptr<CItem>> ,std::string dest ) override;
     void UpdateSize() override;
     void SetDate(u_int year, u_int month, u_int day) override;
     void Deduplicate() override;
     void Print() override;
    void FindText(std::string FindThis) override;

    std::string RemoveDialog() override;
     std::string CreateDialog(std::string NewName) override;
     std::string RenameDialog(std::string NewName) override;
     std::vector<std::string> parseString(const std::string& input, char delimiter);
};


#endif //SEMESTRALWORK_CDIR_H
