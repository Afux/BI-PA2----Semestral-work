
#include "CManager.h"
#include "CDir.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <regex>
void CManager::Print() {
    clear();
    m_LeftPanel.Print();
    m_RightPanel.Print();
    m_HelpBar.Print();

}

CManager::CManager(CSize size, std::string Name, unsigned int Selected) :  CAbsWidnow(size, Selected, Name,this),
m_HelpBar(CHelpBar(CSize(size.m_Width/2,size.m_Height,1, size.m_Height+1),0,"BAR")),
m_LeftPanel(CWindow(CSize(size.m_Width/2,size.m_Height,1,1),0,"Window","/home/afu/PA1")),
m_RightPanel(CWindow(CSize(size.m_Width/2,size.m_Height,size.m_Width/2,1),0,"Window","/home/afu/PA1")),
m_Menu(CMenu(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1),0,"Menu", this)),
m_Input(CInputDialog(CSize(size.m_Width/2,size.m_Height*0.5,size.m_Width/4,size.m_Height*0.2),0,"Menu")),
m_Confirm(CConfirmDialog(CSize(size.m_Width/2,size.m_Height*0.5,size.m_Width/4,size.m_Height*0.2),0,"Menu"))
{

   // m_LeftPanel.m_Items=&m_Start.m_currItems;
   // m_RightPanel.m_Items=&m_Start.m_currItems;
    m_runFlag= true;
    m_ActivePanel=this;
    m_ActiveWindow=&m_LeftPanel;


}

void CManager::Run() {

    while (m_runFlag){
        m_Scene->Print();
        m_Scene->ReadKey();

        // Refresh();
    }
}
/*
 * OP---
 *
 *
 *
 */


void CManager::ReadKey() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);

    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    char c;
    std::cin >> c;


    switch(c) {
        case 'w':
        case 'W':
            m_ActiveWindow->m_Selected--;
            if( m_ActiveWindow->iter!=m_ActiveWindow->m_Items->begin())
                 m_ActiveWindow->iter--;

            break;
        case 's':
        case 'S':
            m_ActiveWindow->m_Selected++;
            if( m_ActiveWindow->m_Selected==1)
                m_ActiveWindow->iter=m_ActiveWindow->m_Items->begin();
            else
                 m_ActiveWindow->iter++;

            break;
        case 'n':
            m_ActiveWindow=NextWind();
            break;
        case 'e':
        case 'E':
            m_ActiveWindow->Enter();
            break;
        case 'k':
        case 'K':
            if(m_ActiveWindow->m_Selected!=0)
                m_ActiveWindow->iter->second->Select();
              //  m_ActiveWindow->m_Items->at(m_ActiveWindow->m_Selected-1).get()->Select();
            break;

        case '1':
        case '+':
            if(m_ActiveWindow->m_Selected!=0){
                m_Menu.m_lastActive= this;
                m_Menu.m_items=m_ActiveWindow->m_Items;

                m_Menu.m_selectedItem=m_ActiveWindow->iter->second.get();
                m_Scene=&m_Menu;
            }

            break;
        case '2':
            if(m_ActiveWindow->m_Selected!=0){
            m_Confirm.m_lastActive= this;
            m_Confirm.m_SelectedItem=m_ActiveWindow->iter->second.get();
            m_Confirm.op=1;
            m_Scene=&m_Confirm;
            }
            break;
        case '3':
            if(m_ActiveWindow->m_Selected!=0) {
                m_Input.m_Label = "Enter path";
                m_Input.m_lastActive = this;
                m_Input.op = 8;
                m_Input.m_SelectedItem =m_ActiveWindow->iter->second.get();
                m_Scene = &m_Input;
            }
           // Move("(a)(.*)","/home/afu/PA1/df/copyhere",m_ActiveWindow->m_Items);
            break;
        case '4':
            if(m_ActiveWindow->m_Selected!=0) {
            m_Input.m_Label="Enter file name";
            m_Input.m_lastActive= this;
            m_Input.op=10;
            m_Input.m_items=m_ActiveWindow->m_Items;
            m_Input.m_SelectedItem=m_ActiveWindow->iter->second.get();
            m_Scene=&m_Input;
            }
            break;

        case '5':
            if(m_ActiveWindow->m_Selected!=0) {
            m_Input.m_Label="Enter folder name";
            m_Input.m_lastActive= this;
            m_Input.op=12;
            m_Input.m_items=m_ActiveWindow->m_Items;

            m_Input.m_SelectedItem=m_ActiveWindow->iter->second.get();
            m_Scene=&m_Input;
            }
            break;
        case '6':
            if(m_ActiveWindow->m_Selected!=0) {
            m_Input.m_Label="Enter path";
            m_Input.m_lastActive= this;
            m_Input.op=9;
            m_Input.m_SelectedItem=m_ActiveWindow->iter->second.get();
            m_Scene=&m_Input;
            }
            break;
        case '7':
            m_runFlag= false;
            break;


    }


    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}



CWindow *CManager::NextWind() {
    if(m_ActiveWindow==&m_LeftPanel)
        return &m_RightPanel;
    else
        return &m_LeftPanel;
}








