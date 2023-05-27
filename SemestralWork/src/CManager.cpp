
#include "CManager.h"
#include "CDir.h"
void CManager::Print() {
    clear();
    m_LeftPanel.Print();
    m_RightPanel.Print();
    m_HelpBar.Print();

}

CManager::CManager(CSize size, std::string Name, unsigned int Selected) :  CAbsWidnow(size, Selected, Name),
m_HelpBar(CHelpBar(CSize(size.m_Width/2,size.m_Height,1, size.m_Height+1),0,"BAR"))
        , m_LeftPanel(CWindow(CSize(size.m_Width/2,size.m_Height,1,1),0,"Window")),
        m_RightPanel(CWindow(CSize(size.m_Width/2,size.m_Height,size.m_Width/2,1),0,"Window")),
        m_Start(CDir ("/home/afu/PA1/df",2,NULL)
                     ){

    m_LeftPanel.m_Items=&m_Start.m_items;
    m_RightPanel.m_Items=&m_Start.m_items;

    m_ActivePanel=&m_LeftPanel;

}

void CManager::Run() {
    while (1){
        Print();
        m_ActivePanel->ReadKey();
        Refresh();
    }
}


