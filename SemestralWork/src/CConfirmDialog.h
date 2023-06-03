

#ifndef SEMESTRALWORK_CCONFIRMDIALOG_H
#define SEMESTRALWORK_CCONFIRMDIALOG_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CAbsWidnow.h"
class CConfirmDialog: public CAbsWidnow{
public:
    CConfirmDialog(CSize size, unsigned int Selected, std::string Name);
    std::string m_Label;
    std::string m_File_name;
    CItem * m_SelectedItem;
    vector<std::string > m_Content;
    void Print() override;
    void ReadKey() override;
    void Enter();
    void Run();
    int op;
    CAbsWidnow * m_lastActive;

    CAbsWidnow * win;
    std::map<std::string ,std::shared_ptr<CItem>> *m_items;



};


#endif //SEMESTRALWORK_CCONFIRMDIALOG_H
