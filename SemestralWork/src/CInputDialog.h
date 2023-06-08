

#ifndef SEMESTRALWORK_CINPUTDIALOG_H
#define SEMESTRALWORK_CINPUTDIALOG_H
#include "CItem.h"
#include "CSize.h"
#include "iostream"
#include "CAbsWidnow.h"
#include "CErrDialog.h"
class CManager;
class CInputDialog: public CAbsWidnow{
public:

    CInputDialog(CSize size);
    std::string m_Label;
    CItem * m_SelectedItem;
    CItem *CurrDir;
    std::vector<std::string > m_Content;
    void Print() override;
    void ReadKey() override;
    void PrintBorders();
    void ClearDialogSpace();
    void PrintLabel();
    void Run();
    int op;
    CAbsWidnow * m_lastActive;
    unsigned int *WinSelected;
    std::map<std::string ,std::shared_ptr<CItem>> *m_items;
    CErrDialog m_errDialog;

    void Setup(CItem * Curr ,CAbsWidnow * lastActive,const int &Op, const std::string &Label,CItem * SelectedItem,unsigned int *WinSel);

private:
    std::string  m_input;
    std::string  m_reg;
    std::string m_path;
    void parseString(const std::string& input, char delimiter);
    void Enter();
};


#endif //SEMESTRALWORK_CINPUTDIALOG_H
