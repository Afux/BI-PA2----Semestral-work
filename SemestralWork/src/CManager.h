
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

    CAbsWidnow * m_ActivePanel;
   // CDir m_Start;


    void Print() override;
    void Run();
    void ReadKey() override;
    CWindow *NextWind();

};


#endif //SEMESTRALWORK_CMANAGER_H
