
#ifndef SEMESTRALWORK_CMANAGER_H
#define SEMESTRALWORK_CMANAGER_H
#include "CSize.h"
#include "CWindow.h"
#include "CHelpBar.h"
#include "CAbsWidnow.h"
#include "CInputDialog.h"
#include "CMenu.h"
#include "CDir.h"


class CManager: public CAbsWidnow{
public:
    CManager( CSize size,std::string Name, unsigned int Selected);
    CHelpBar m_HelpBar;
    CWindow m_LeftPanel;
    CWindow m_RightPanel;
    CMenu m_Menu;
    CInputDialog m_Input;
    CConfirmDialog m_Confirm;
    CWindow *m_ActiveWindow;
    bool m_runFlag;
    CAbsWidnow * m_ActivePanel;

   // CDir m_Start;


    void Print() override;
    void Run();
    void ReadKey() override;
     void Copy( CItem *item, std::string to);
     void Copy( CItem *item,vector<CItem*> items,std::string to);
     void Delete( CItem *item);
     void Delete(vector<CItem*> items) ;
     void Move( CItem *item , std::string dest) ;
     void Move( CItem *item,vector<CItem*>,std::string dest ) ;
    CWindow *NextWind();

};


#endif //SEMESTRALWORK_CMANAGER_H
