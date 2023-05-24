
#include "CManager.h"

void CManager::Print() {
    clear();
    m_LeftPanel.TESTING.push_back("/CZ");
    m_LeftPanel.TESTING.push_back("/DFS");
    m_LeftPanel.TESTING.push_back("dsdsds-e");
    m_LeftPanel.TESTING.push_back("ddd");
    m_LeftPanel.TESTING.push_back("gggg");

    m_RightPanel.TESTING.push_back("/sd");
    m_RightPanel.TESTING.push_back("222");
    m_RightPanel.TESTING.push_back("adadad-e");
    m_RightPanel.TESTING.push_back("adad");
    m_RightPanel.TESTING.push_back("asdasdada");

    m_LeftPanel.Print();
    m_RightPanel.Print();
    m_HelpBar.Print();

}

CManager::CManager(CSize size, std::string Name, unsigned int Selected) :  CAbsWidnow(size, Selected, Name),
m_HelpBar(CHelpBar(CSize(size.m_Width/2,size.m_Height,1, size.m_Height+1),0,"BAR"))
        , m_LeftPanel(CWindow(CSize(size.m_Width/2,size.m_Height,1,1),0,"Window")),
        m_RightPanel(CWindow(CSize(size.m_Width/2,size.m_Height,size.m_Width/2,1),0,"Window")
                     ){}


