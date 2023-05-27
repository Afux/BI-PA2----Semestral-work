
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
    CMenu(CSize size, unsigned int Selected, std::string Name);
    vector<string> m_Content;
    CItem * m_SelectedItem{};
    //CConfirmDialog   m_Dialog;
    //CInputDialog  m_InputDialog;
    void Print() override;
    void ReadKey() override;
};


#endif //SEMESTRALWORK_CMENU_H
