
#ifndef SEMESTRALWORK_CFILE_H
#define SEMESTRALWORK_CFILE_H

#include "CItem.h"
#include "CDir.h"
class CFile: public CItem{
public:
    CFile(std::string path,unsigned int size, CItem * parr);
   // CFile* Concat(std::map<std::string ,std::shared_ptr<CItem>> items);
     void Print() override;
     void Copy(std::string to) override;
     void Delete() override;
     void Move( std::string dest) override;
    void FindText(std::string FindThis,std::vector<CItem*> *Found) override;

     void Deduplicate(CItem * DeduplicateMe) override;
     std::string RemoveDialog() override;
     std::string CreateDialog(std::string NewName) override;
     void Open(std::map<std::string ,std::shared_ptr<CItem>> **item,CItem ** inFold)override;
    bool identicalFiles(std::string file1, std::string file2);
    void ConCat(std::string To) override;

};


#endif //SEMESTRALWORK_CFILE_H
