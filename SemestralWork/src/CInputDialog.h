

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
     void Print() override;

};


#endif //SEMESTRALWORK_CINPUTDIALOG_H
