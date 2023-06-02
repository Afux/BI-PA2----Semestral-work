

#ifndef SEMESTRALWORK_CWINDOW_H
#define SEMESTRALWORK_CWINDOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CMenu.h"
#include "CInputDialog.h"
#include "CConfirmDialog.h"
#include "CAbsWidnow.h"
#include "CDir.h"
using namespace std;
class CWindow: public CAbsWidnow{
public:
    CWindow( CSize size, unsigned int Selected, std::string Name,string Path);
    std::string m_CurrPath;
    std::vector< std::shared_ptr<CItem>>   *m_Items;
    std::vector< std::shared_ptr<CItem>> m_Selecteditems;
    //vector<std::string> TESTING;
    CDir m_StartDir;

    CDir m_currDir;

    // CInputDialog  m_InputDialog;

    //CConfirmDialog m_Dialog;
    //CMenu m_Menu;
    CItem* m_CurrFile;
    void Print() override;
    void ReadKey() override;
    void Run();
    void Enter();


};


#endif //SEMESTRALWORK_CWINDOW_H
