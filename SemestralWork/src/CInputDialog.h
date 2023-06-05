

#ifndef SEMESTRALWORK_CINPUTDIALOG_H
#define SEMESTRALWORK_CINPUTDIALOG_H
#include "CItem.h"
#include "CSize.h"
#include "iostream"
#include "CAbsWidnow.h"
class CManager;
class CInputDialog: public CAbsWidnow{
public:

    CInputDialog(CSize size, unsigned int Selected);
    std::string m_Label;
    CItem * m_SelectedItem;

    std::vector<std::string > m_Content;
    CManager * m_manager;
    void Print() override;
    void ReadKey() override;
    void PrintBorders();
    void ClearDialogSpace();
    void PrintLabel();
    void Run();
    int op;
    CAbsWidnow * m_lastActive;
    CAbsWidnow * win;
    std::map<std::string ,std::shared_ptr<CItem>> *m_items;

    void Setup( CAbsWidnow * lastActive,const int &Op, const std::string &Label,CItem * SelectedItem,   std::map<std::string ,std::shared_ptr<CItem>> *items);

private:
    std::string  m_input;
    std::string  m_reg;
    std::string m_path;
    void parseString(const std::string& input, char delimiter);
    void Enter();
};


#endif //SEMESTRALWORK_CINPUTDIALOG_H
