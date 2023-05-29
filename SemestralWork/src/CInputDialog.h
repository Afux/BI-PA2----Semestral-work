

#ifndef SEMESTRALWORK_CINPUTDIALOG_H
#define SEMESTRALWORK_CINPUTDIALOG_H
#include "CItem.h"
#include "CSize.h"
#include "iostream"
#include "CAbsWidnow.h"

class CInputDialog: public CAbsWidnow{
public:

    CInputDialog(CSize size, unsigned int Selected, std::string Name);
    std::string m_Label;
    std::string m_ButtonLabel;
    CItem * m_SelectedItem;
    std::string  m_input;
    vector<std::string > m_Content;
    void Print() override;
    void ReadKey() override;
    void Enter();
    void Run();
    CAbsWidnow * m_lastActive;


};


#endif //SEMESTRALWORK_CINPUTDIALOG_H
