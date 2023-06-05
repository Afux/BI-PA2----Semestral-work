

#include "CConfirmDialog.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "../libs/rang.hpp"
using namespace rang;
using namespace std;

CConfirmDialog::CConfirmDialog(CSize size, unsigned int Selected) : CAbsWidnow(size, Selected,this) {

    op=0;
    m_Content.emplace_back("[YES]");
    m_Content.emplace_back("[No]");
    m_Label="ARE YOU SURE?";
}

void CConfirmDialog::Print() {
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
    moveto(m_Size.m_PosX+3,m_Size.m_PosY+4);
    cout<<m_Label;
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
    moveto(m_Size.m_PosX+2,m_Size.m_Height-4+m_Size.m_PosY);
    for (size_t i = 0; i < m_Content.size() ; ++i) {

        if(i==m_Selected){

            cout << bg::blue<<m_Content[i]<<style::reset;

        }
        else{

            cout <<m_Content[i];

        }
        moveto(m_Size.m_Width-10+m_Size.m_PosX,m_Size.m_Height-4+m_Size.m_PosY);

    }
    moveto(1,m_Size.m_AbsPosY+2);

}

void CConfirmDialog::ReadKey() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);

    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    char c;
    std::cin >> c;


    switch(c) {
        case 'a':
        case 'A':
            m_Selected--;
            break;
        case 'd':
        case 'D':
            m_Selected++;
            break;
        case 'e':
            Enter();
            break;


    }



    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void CConfirmDialog::Enter() {
  if(m_Selected==0){
      switch(op){
          case 1:
              if(win->iter!=m_items->begin()){
                  win->m_Selected--;
                  win->iter--;

              }
              Delete(m_SelectedItem);

              break;
          case 2:
              break;
          case 3:
              break;
      }
      op=0;
      m_Selected=0;

      m_lastActive->m_Scene=m_lastActive;


  }
  else{
      m_Selected=0;
      m_lastActive->m_Scene=m_lastActive;
  }


}
void CConfirmDialog::Run() {
    while (1){
        Print();
        ReadKey();
        clear();
    }

}
