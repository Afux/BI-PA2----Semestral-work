

#ifndef SEMESTRALWORK_CABSWIDNOW_H
#define SEMESTRALWORK_CABSWIDNOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include <memory>
class CAbsWidnow {
public:
    CAbsWidnow(CSize size, unsigned int Selected, CAbsWidnow * Scene);

    virtual ~CAbsWidnow();
    CSize  m_Size;
    unsigned int m_Selected;
    CAbsWidnow* m_Scene;

   std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, std::shared_ptr<CItem>>> iter;

    void Refresh();
    virtual void Print()=0;
    virtual void  ReadKey()=0;

    void clear();
    void moveto(int x = 1, int y = 1);

   //OPS
    void Copy( CItem *item, std::string to);
    void Copy( std::string reg,std::string to,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void Delete( CItem *item);
    void Delete(std::string reg,std::map<std::string ,std::shared_ptr<CItem>> *Items) ;
    void Move( CItem *item , std::string dest) ;
    void Move(std::string reg, std::string dest,std::map<std::string ,std::shared_ptr<CItem>> *Items) ;
    void CreateFolder(std::string name,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void CreateFile(std::string name,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void CreateLink(std::string name,CItem * to,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void FindByText(std::string text,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void Deduplicate(CItem* item,std::map<std::string ,std::shared_ptr<CItem>> *Items);
    void ConcatFiles(std::map<std::string ,std::shared_ptr<CItem>> *Items,std::string to);

protected:
private:
};


#endif //SEMESTRALWORK_CABSWIDNOW_H
