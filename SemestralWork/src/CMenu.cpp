
#include "CMenu.h"
#include "rang.hpp"
#include <iomanip>
#include <unistd.h>
#include <termios.h>
#include <iostream>
using namespace rang;
using namespace std;

CMenu::CMenu(CSize size, unsigned int Selected,CAbsWidnow* lastActive)
:  CAbsWidnow(size, Selected, this),m_lastActive(lastActive),
   m_inputDialog(CInputDialog(CSize(lastActive->m_Size.m_Width/2,lastActive->m_Size.m_Height*0.5,lastActive->m_Size.m_Width/4,lastActive->m_Size.m_Height*0.2,size.m_AbsPosY),0)){
    m_Content.emplace_back("Remove by Regex");
    m_Content.emplace_back("Copy by Regex");
    m_Content.emplace_back("Move by Regex");
    m_Content.emplace_back("Create symb. link");
    m_Content.emplace_back("Find by text");
    m_Content.emplace_back("Concat files");
    m_Content.emplace_back("Deduplicate file");

    m_Content.emplace_back("Quit");


}

void CMenu::Print() {
    if(m_Selected>=m_Content.size()){
        m_Selected=0;
    }
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
    moveto(1,m_Size.m_AbsPosY+2);

}

void CMenu::ReadKey() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);

    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

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
        case 'e':
        case 'E':
            Enter();
            break;


    }



    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
void CMenu::Enter() {
    switch (m_Selected) {
        case 0:
            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=1;
            m_inputDialog.m_Label="Enter Regex";
            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();

            break;
        case 1:
            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=2;
            m_inputDialog.m_Label="Enter Regex n:l";

            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();
            break;
        case 2:
            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=3;
            m_inputDialog.m_Label="Enter Regex n:l";
            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();

            break;
        case 3:
            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=13;
            m_inputDialog.m_Label="Enter name and link n:l";

            m_inputDialog.m_SelectedItem=m_selectedItem;
            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();
            break;
        case 4:

            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=5;
            m_inputDialog.m_Label="Enter text";

            m_inputDialog.m_SelectedItem=m_selectedItem;
            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();
            break;
        case 5:
            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=6;
            m_inputDialog.m_Label="Enter name";

            m_inputDialog.m_SelectedItem=m_selectedItem;
            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();
            break;
        case 6:
            m_inputDialog.m_lastActive=m_lastActive;
            m_inputDialog.op=7;
            m_inputDialog.m_Label="FIX";
            m_inputDialog.m_SelectedItem=m_selectedItem;
            m_inputDialog.m_items=m_items;
            m_inputDialog.Run();
            break;
        case 7:
            m_Selected=0;
            m_inputDialog.m_lastActive=m_lastActive;
            m_lastActive->m_Scene=m_lastActive;
            break;
    }

}