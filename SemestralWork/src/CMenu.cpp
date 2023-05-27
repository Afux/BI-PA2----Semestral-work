
#include "CMenu.h"
#include "rang.hpp"
#include <iomanip>

using namespace rang;
CMenu::CMenu(CSize size, unsigned int Selected, std::string Name)
:  CAbsWidnow(size, Selected, Name, this) {
    m_Content.push_back("Deduplicate file");
    m_Content.push_back("Concat files");
    m_Content.push_back("Remove by Regex");
    m_Content.push_back("Copy by Regex");
    m_Content.push_back("Move by Regex");
    m_Content.push_back("Quit");


}

void CMenu::Print() {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        for (size_t j =1; j < m_Size.m_Width; ++j) {
            cout<<" ";
        }
    }
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    //Horni
    for (size_t i =1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<"*"<<style::reset;

    }

    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        cout<<bg::black<<"*"<<style::reset;
        moveto((int)(m_Size.m_Width)+m_Size.m_PosX-1,i);
        cout<<bg::black<<"*"<<style::reset;
        moveto(m_Size.m_PosX,i);
    }
    //Dolni


    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<"*"<<style::reset;

    }

    for (size_t i = 0; i < m_Content.size() ; ++i) {
        moveto(m_Size.m_PosX+2,m_Size.m_PosY+4+i);
        if(i==m_Selected){

            cout << bg::blue<<m_Content[i]<< setw(m_Size.m_Width-m_Content[i].size())
                 <<style::reset;

        }

        else{
            cout <<m_Content[i]<<setw(m_Size.m_Width-m_Content[i].size());

        }

    }


}

void CMenu::ReadKey() {

}
