
#ifndef SEMESTRALWORK_CMENU_H
#define SEMESTRALWORK_CMENU_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CConfirmDialog.h"
#include "CInputDialog.h"
#include "CAbsWidnow.h"
#include "CErrDialog.h"

class CMenu: public CAbsWidnow{
public:

    CMenu(CSize size,CAbsWidnow * lastActive);
    CItem * CurrDir;
    CAbsWidnow * m_lastActive;
    CInputDialog m_inputDialog;
    CErrDialog m_errorDialog;
    CItem * m_selectedItem;
    unsigned int *m_windowSelected;
    void Print() override;
    void ReadKey() override;
    void Enter();

    void Setup( CItem * Curr,CAbsWidnow * LastActive);

private:
   std::vector<std::string> m_Content;
    void PrintBorders();
    void ClearDialogSpace();
};


#endif //SEMESTRALWORK_CMENU_H
