

#ifndef SEMESTRALWORK_CWINDOW_H
#define SEMESTRALWORK_CWINDOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CAbsWidnow.h"
#include "CDir.h"
#include "unordered_map"
class CWindow: public CAbsWidnow{
public:
    CWindow( CSize size,std::string Path);
    std::map<std::string ,std::shared_ptr<CItem>>   *m_Items;
    std::map<std::string ,std::shared_ptr<CItem>> m_Selecteditems;
    CDir m_Dir;

    std::map<std::string ,std::shared_ptr<CItem>>::iterator m_FromItem;

    CItem* m_CurrFile;
    void Print() override;
    void ReadKey() override;
    void PrintBorders();
    void Run();
    void Enter();
    void Jump(std::string to);


};


#endif //SEMESTRALWORK_CWINDOW_H
