

#ifndef SEMESTRALWORK_CINPUTDIALOG_H
#define SEMESTRALWORK_CINPUTDIALOG_H
#include "CItem.h"
#include "CSize.h"
#include "iostream"
#include "CAbsWidnow.h"
class CManager;
class CInputDialog: public CAbsWidnow{
public:

    CInputDialog(CSize size, unsigned int Selected, std::string Name);
    std::string m_Label;
    std::string m_ButtonLabel;
    CItem * m_SelectedItem;
    std::string  m_input;
    std::string  m_reg;
    std::string m_path;
    vector<std::string > m_Content;
    CManager * m_manager;
    void Print() override;
    void ReadKey() override;
    void Enter();
    void Run();
    int op;
    CAbsWidnow * m_lastActive;
    std::vector< std::shared_ptr<CItem>> *m_items;
    void parseString(const std::string& input, char delimiter);


};


#endif //SEMESTRALWORK_CINPUTDIALOG_H
