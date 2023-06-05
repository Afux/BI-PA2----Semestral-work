

#ifndef SEMESTRALWORK_CWINDOW_H
#define SEMESTRALWORK_CWINDOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CMenu.h"
#include "CInputDialog.h"
#include "CConfirmDialog.h"
#include "CAbsWidnow.h"
#include "CDir.h"
class CWindow: public CAbsWidnow{
public:
    CWindow( CSize size, unsigned int Selected,std::string Path);
    std::string m_CurrPath;
    std::map<std::string ,std::shared_ptr<CItem>>   *m_Items;
    std::map<std::string ,std::shared_ptr<CItem>> m_Selecteditems;
    CDir m_StartDir;

    CDir m_currDir;
    std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, std::shared_ptr<CItem>>> tt;


    CItem* m_CurrFile;
    void Print() override;
    void ReadKey() override;
    void PrintBorders();
    void Run();
    void Enter();


};


#endif //SEMESTRALWORK_CWINDOW_H
