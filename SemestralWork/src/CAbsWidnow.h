

#ifndef SEMESTRALWORK_CABSWIDNOW_H
#define SEMESTRALWORK_CABSWIDNOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"

using namespace std;
class CAbsWidnow {
public:
    CAbsWidnow(CSize size, unsigned int Selected, std::string Name, CAbsWidnow * Scene);

    virtual ~CAbsWidnow()
    { }
    CSize  m_Size;
    unsigned int m_Selected;
    std::string  m_Name;
    CAbsWidnow* m_Scene;


    void Refresh();
    virtual void Print()=0;
    virtual void  ReadKey()=0;
    void clear();
    void moveto(int x = 1, int y = 1);
    void Copy( CItem *item, std::string to);
    void Copy( std::string reg,std::string to,vector<CItem*> *Items);
    void Delete( CItem *item);
    void Delete(std::string reg,vector<CItem*> *Items) ;
    void Move( CItem *item , std::string dest) ;
    void Move(std::string reg, std::string dest,vector<CItem*> *Items) ;

    void CreateFolder(std::string name,vector<CItem*> *Items);
    void CreateFile(std::string name,vector<CItem*> *Items);
    void CreateLink(std::string name,CItem * to,vector<CItem*> *Items);

protected:
private:
};


#endif //SEMESTRALWORK_CABSWIDNOW_H
