
#include "CHelpBar.h"
#include "iostream"
CHelpBar::CHelpBar(CSize size, unsigned int Selected, std::string Name) : CAbsWidnow(size, Selected, Name, this) {

    m_Content.push_back("Menu");
    m_Content.push_back("Delete");
    m_Content.push_back("Copy");
    m_Content.push_back("Create");
    m_Content.push_back("MKDIR");




}

void CHelpBar::Print() {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i = 0; i < m_Content.size(); ++i) {
        std::cout<<i+1<<" "<<m_Content[i]<<"   ";
    }
    moveto(m_Size.m_PosX,m_Size.m_PosY+1);

}

void CHelpBar::ReadKey() {

}


