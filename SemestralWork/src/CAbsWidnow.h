

#ifndef SEMESTRALWORK_CABSWIDNOW_H
#define SEMESTRALWORK_CABSWIDNOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include <memory>
using namespace std;
class CAbsWidnow {
public:
    CAbsWidnow(CSize size, unsigned int Selected, std::string Name, CAbsWidnow * Scene);

    virtual ~CAbsWidnow();
    CSize  m_Size;
    unsigned int m_Selected;
    std::string  m_Name;
    CAbsWidnow* m_Scene;

    _Rb_tree_iterator<pair<const basic_string<char>, shared_ptr<CItem>>> iter;

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
    void ConcatFiles(std::map<std::string ,std::shared_ptr<CItem>> *Items,string to);

protected:
private:
};


#endif //SEMESTRALWORK_CABSWIDNOW_H
