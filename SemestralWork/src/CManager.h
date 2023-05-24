
#ifndef SEMESTRALWORK_CMANAGER_H
#define SEMESTRALWORK_CMANAGER_H
#include "CSize.h"
#include "CWindow.h"
#include "CHelpBar.h"
#include "CAbsWidnow.h"
class CManager: public CAbsWidnow{
public:
    CManager( CSize size,std::string Name, unsigned int Selected);
    CWindow m_LeftPanel;
    CWindow m_RightPanel;
    CWindow * m_ActivePanel;
      CHelpBar m_HelpBar;
    void Print() override;

};


#endif //SEMESTRALWORK_CMANAGER_H
