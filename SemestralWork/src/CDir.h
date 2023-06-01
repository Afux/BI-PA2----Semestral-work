
#ifndef SEMESTRALWORK_CDIR_H
#define SEMESTRALWORK_CDIR_H

#include "CItem.h"
class CDir: public CItem{
public:
    CDir(std::string path,unsigned int size,CItem* Parr,CItem* inFolder);
    std::vector<CItem*>m_items;
    std::vector<CItem*>m_currItems;
    //std::map<std::string,CItem*> m_items;
    CItem * m_parr;
    std::vector<CItem*>* FindDir(const std::string& path);
    CItem* Clone() override;

    void Open(std::vector<CItem*> **item)override;

     void Copy(std::vector<CItem*> items, std::string to ) override;
     void Copy(std::string to) override;
     void Delete() override;
     void Delete(std::vector<CItem*> items) override;
     void Move( std::string dest) override;
     void Move(std::vector<CItem*>,std::string dest ) override;
     void UpdateSize() override;
     void SetDate(u_int year, u_int month, u_int day) override;
     void Deduplicate() override;
     void Print() override;
     std::string RemoveDialog() override;
     std::string CreateDialog(std::string NewName) override;
     std::string RenameDialog(std::string NewName) override;
     std::vector<std::string> parseString(const std::string& input, char delimiter);
};


#endif //SEMESTRALWORK_CDIR_H
