

#include "CConfirmDialog.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "../libs/rang.hpp"
using namespace rang;
using namespace std;

CConfirmDialog::CConfirmDialog(CSize size) : CAbsWidnow(size,this), m_errDialog(size) {
    op=0;
    m_Content.emplace_back("[YES]");
    m_Content.emplace_back("[No]");
    m_Label="ARE YOU SURE?";
}

void CConfirmDialog::Print() {
    if(m_Selected>=m_Content.size()){
        m_Selected=0;
    }

    ClearDialogSpace();
    PrintBorders('*');
    PrintLabel();


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
    cursorOff();

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
        case '\x04':
            m_lastActive->m_isrunning= false;
        break;
        case 'E':
        case 'e':
            Enter();
            break;


    }

    cursorOn();
}

void CConfirmDialog::Enter() {
  if(m_Selected==0){
      switch(op){
          case 1:
              win->m_Selected--;
              if(win->iter!=m_items->begin()){
                  win->iter--;
              }
              try {
                  Oper.Delete(m_SelectedItem);
              }
              catch (logic_error &e){
                  m_errDialog.Setup(m_lastActive,e.what());
              }
              break;
          case 2:
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

void CConfirmDialog::PrintBorders(const char &c) {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    //Upper borders
    for (size_t i =1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<c<<style::reset;

    }
    //SIDE BORDES
    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        cout<<bg::black<<c<<style::reset;
        moveto((int)(m_Size.m_Width)+m_Size.m_PosX-1,i);
        cout<<bg::black<<c<<style::reset;
        moveto(m_Size.m_PosX,i);
    }
    //Bottom bordesr
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<c<<style::reset;

    }
}

void CConfirmDialog::ClearDialogSpace() {
    //CLEAR DIALOG
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        for (size_t j =1; j < m_Size.m_Width; ++j) {
            cout<<" ";
        }
    }
}

void CConfirmDialog::PrintLabel() {
    //LABEL
    moveto(m_Size.m_PosX+3,m_Size.m_PosY+4);
    cout<<m_Label;
}

void
CConfirmDialog::Setup(CAbsWidnow *lastActive, CItem *SelectedItem, std::map<std::string, std::shared_ptr<CItem>> *items,
                      CAbsWidnow *Win, const int &Op) {
m_lastActive=lastActive;
m_SelectedItem=SelectedItem;
m_items=items;
win=Win;
op=Op;
}
