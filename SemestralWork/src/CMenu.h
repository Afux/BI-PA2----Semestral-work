
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

    CMenu(CSize size, unsigned int Selected,CAbsWidnow * lastActive);
    CAbsWidnow * m_lastActive;
    CInputDialog m_inputDialog;
    std::map<std::string ,std::shared_ptr<CItem>> *m_items;
    CItem * m_selectedItem;
    void Print() override;
    void ReadKey() override;
    void Enter();

private:
   std::vector<std::string> m_Content;

};


#endif //SEMESTRALWORK_CMENU_H
