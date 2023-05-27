

#ifndef SEMESTRALWORK_CWINDOW_H
#define SEMESTRALWORK_CWINDOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CMenu.h"
#include "CInputDialog.h"
#include "CConfirmDialog.h"
#include "CAbsWidnow.h"
using namespace std;
class CWindow: public CAbsWidnow{
public:
    CWindow( CSize size, unsigned int Selected, std::string Name);
    std::string m_CurrPath;
    vector<CItem*>   *m_Items;
    vector<CItem*> m_Selecteditems;
    //vector<std::string> TESTING;

    // CInputDialog  m_InputDialog;

    //CConfirmDialog m_Dialog;
    //CMenu m_Menu;
    CItem* m_CurrFile;
    void Print() override;
    void Run();


};


#endif //SEMESTRALWORK_CWINDOW_H
