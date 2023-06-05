//
// Created by afu on 05.06.23.
//

#ifndef SEMESTRALWORK_CMANAGEROPS_H
#define SEMESTRALWORK_CMANAGEROPS_H
#include "iostream"
#include "map"
#include "memory"
#include "CItem.h"




class CManagerOPs {
public:
    void Copy( CItem *item, const std::string &to);
    void Copy( const std::string &reg,const std::string &to,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void Delete( CItem *item);
    void Delete(std::string reg,std::map<std::string ,std::shared_ptr<CItem>> *Items) ;
    void Move( CItem *item , std::string dest) ;
    void Move(std::string reg, std::string dest,std::map<std::string ,std::shared_ptr<CItem>> *Items) ;
    void CreateFolder(std::string name,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void CreateFile(std::string name,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void CreateLink(std::string name,CItem * to,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void FindByText(const std::string &text,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void Deduplicate(CItem* item,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void ConcatFiles(std::map<std::string ,std::shared_ptr<CItem>> *Items,std::string to);
};


#endif //SEMESTRALWORK_CMANAGEROPS_H
