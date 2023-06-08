
#ifndef SEMESTRALWORK_CDIR_H
#define SEMESTRALWORK_CDIR_H

#include "CItem.h"

class CDir : public CItem {
public:
    CDir(std::string path, unsigned int size, CItem *inFolder);


    void Open(std::map<std::string, std::shared_ptr<CItem>> **item, CItem **inFold) override;

    void Copy(const std::string &to) override;

    void Delete() override;

    void Move(const std::string &dest) override;

    void Deduplicate(CItem *DeduplicateMe) override;

    void Print() override;

    void FindText(const std::string &FindThis, std::vector<CItem *> *Found) override;

    void ConCat(const std::string &To) override;

    void FillItems();


    std::string RemoveDialog() override;

private:
    void Refresh();

};


#endif //SEMESTRALWORK_CDIR_H
