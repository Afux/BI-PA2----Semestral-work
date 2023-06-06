

#ifndef SEMESTRALWORK_CCONFIRMDIALOG_H
#define SEMESTRALWORK_CCONFIRMDIALOG_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CAbsWidnow.h"
#include "CErrDialog.h"
class CConfirmDialog: public CAbsWidnow{
public:
    CConfirmDialog(CSize size, unsigned int Selected);

    void Print() override;
    void PrintBorders(const char &c);
    void ClearDialogSpace();
    void PrintLabel();

    void Setup(CAbsWidnow * lastActive,CItem * SelectedItem,std::map<std::string ,std::shared_ptr<CItem>> *items, CAbsWidnow * Win,const int &Op);
    void ReadKey() override;
    void Enter();
    void Run();
    int op;

private:
    std::string m_Label;
    CItem * m_SelectedItem;
    std::vector<std::string > m_Content;
    CAbsWidnow * m_lastActive;
    CAbsWidnow * win;
    std::map<std::string ,std::shared_ptr<CItem>> *m_items;
    CErrDialog m_errDialog;


};


#endif //SEMESTRALWORK_CCONFIRMDIALOG_H
