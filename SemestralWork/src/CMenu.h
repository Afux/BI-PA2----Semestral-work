
#ifndef SEMESTRALWORK_CMENU_H
#define SEMESTRALWORK_CMENU_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CConfirmDialog.h"
#include "CInputDialog.h"
#include "CAbsWidnow.h"
class CMenu: public CAbsWidnow{
public:

    CMenu(CSize size, unsigned int Selected, std::string Name,CAbsWidnow * lastActive);
    vector<string> m_Content;
    CAbsWidnow * m_lastActive;
    CInputDialog m_inputDialog;
    std::vector< std::shared_ptr<CItem>> *m_items;
    CItem * m_selectedItem;
    //CConfirmDialog   m_Dialog;
    //CInputDialog  m_InputDialog;
    void Print() override;
    void ReadKey() override;
    void Enter();
};


#endif //SEMESTRALWORK_CMENU_H
