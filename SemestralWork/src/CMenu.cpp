
#include "CMenu.h"
#include "../libs/rang.hpp"
#include <iomanip>
#include <unistd.h>
#include <termios.h>
#include <iostream>

using namespace rang;
using namespace std;

CMenu::CMenu(CSize size,CAbsWidnow* lastActive):  CAbsWidnow(size, this),m_lastActive(lastActive),
m_inputDialog(CInputDialog(CSize(size))), m_errorDialog(CErrDialog(size)){

    m_Content.emplace_back("Remove by Regex");
    m_Content.emplace_back("Copy by Regex");
    m_Content.emplace_back("Move by Regex");
    m_Content.emplace_back("Create sym. link");
    m_Content.emplace_back("Find by text");
    m_Content.emplace_back("Concat files");
    m_Content.emplace_back("Deduplicate file");
    m_Content.emplace_back("Quit");
}

void CMenu::Print() {
    if(m_Selected>=m_Content.size()){
        m_Selected=0;
    }
    ClearDialogSpace();
    PrintBorders();
    for (size_t i = 0; i < m_Content.size() ; ++i) {
        moveto(m_Size.m_PosX+2,m_Size.m_PosY+4+i);
        if(i==m_Selected){
            cout << bg::blue<<m_Content[i]<< setw(m_Size.m_Width-m_Content[i].size())<<style::reset;
        }
        else{
            cout <<m_Content[i]<<setw(m_Size.m_Width-m_Content[i].size());
        }
    }
    moveto(1,m_Size.m_AbsPosY+2);

}

void CMenu::ReadKey() {
   cursorOff();
    char c;
    std::cin >> c;


    switch(c) {
        case 'W':
        case 'w':
            m_Selected--;
            break;
        case 'S':
        case 's':
            m_Selected++;
            break;
        case '\x04':
            m_lastActive->m_isrunning= false;
            break;
        case 'e':
        case 'E':
            Enter();
            break;


    }



cursorOn();
}
void CMenu::Enter() {
    switch (m_Selected) {
        case 0:
            m_inputDialog.Setup(CurrDir, m_lastActive,1,"Enter Regex",m_selectedItem,m_winActive);
            m_inputDialog.Run();
            break;
        case 1:
            m_inputDialog.Setup(CurrDir,m_lastActive,2,"Enter Regex n:l",m_selectedItem,m_winActive);
            m_inputDialog.Run();
            break;
        case 2:
            m_inputDialog.Setup(CurrDir,m_lastActive,3,"Enter Regex n:l",m_selectedItem,m_winActive);
            m_inputDialog.Run();
            break;
        case 3:
            m_Selected=0;
            if(m_winActive->m_Selected!=0) {
                m_inputDialog.Setup(CurrDir, m_lastActive, 13, "Enter name", m_selectedItem, m_winActive);
                m_inputDialog.Run();
            }
            break;
        case 4:
            m_Selected=0;
            m_inputDialog.Setup(CurrDir,m_lastActive,5,"Enter text",m_selectedItem,m_winActive);
            m_inputDialog.Run();
            break;
        case 5:
            m_Selected=0;
            m_inputDialog.Setup(CurrDir,m_lastActive,6,"Enter name",m_selectedItem,m_winActive);
            m_inputDialog.Run();
            break;
        case 6:
            m_Selected=0;
            if(m_winActive->m_Selected!=0) {
                try {
                    Oper.Deduplicate(m_selectedItem, &CurrDir->m_items);
                }
                catch (logic_error &e) {
                    m_errorDialog.Setup(m_lastActive, e.what());
                    m_errorDialog.Run();
                }
            }
            break;
        case 7:
            m_Selected=0;
            m_inputDialog.m_lastActive=m_lastActive;
            m_lastActive->m_Scene=m_lastActive;

            break;
    }

}

void CMenu::PrintBorders() {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
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
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<"*"<<style::reset;

    }

}

void CMenu::ClearDialogSpace() {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        for (size_t j =1; j < m_Size.m_Width; ++j) {
            cout<<" ";
        }
    }
}

void CMenu::Setup(CItem * Curr,CAbsWidnow *LastActive,CAbsWidnow *winActive) {
    CurrDir=Curr;
    m_lastActive=LastActive;
    m_winActive=winActive;
    if(m_winActive->m_Selected!=0){
        m_selectedItem=winActive->iter->second.get();
    }
    else
        m_selectedItem= nullptr;


}

