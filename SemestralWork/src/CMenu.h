
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

    CMenu(CSize size,CAbsWidnow * lastActive);
    CAbsWidnow * m_lastActive;
    CInputDialog m_inputDialog;
    CConfirmDialog m_ConfirmDialog;
    std::map<std::string ,std::shared_ptr<CItem>> *m_items;
    std::map<std::string ,std::shared_ptr<CItem>> *m_SelectedItems;
    CItem * m_selectedItem;
    CAbsWidnow * win;
    void Print() override;
    void ReadKey() override;
    void Enter();

    void Setup( CAbsWidnow * LastActive,  std::map<std::string ,std::shared_ptr<CItem>> *Items,std::map<std::string ,std::shared_ptr<CItem>> *SelectedItems, CItem *SelectedItem,CAbsWidnow *win);

private:
   std::vector<std::string> m_Content;
    void PrintBorders();
    void ClearDialogSpace();
};


#endif //SEMESTRALWORK_CMENU_H
