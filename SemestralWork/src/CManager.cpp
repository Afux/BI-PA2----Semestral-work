
#include "CManager.h"
#include "CDir.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <regex>

using namespace std;

void CManager::Print() {
    clear();
    m_LeftPanel.Print();
    m_RightPanel.Print();
    m_HelpBar.Print();

}

CManager::CManager(CSize size, std::string Name, unsigned int Selected) :  CAbsWidnow(size, Selected,this),
m_HelpBar(CHelpBar(CSize(size.m_Width/2,size.m_Height,1, size.m_Height+1,size.m_Height),0)),
m_LeftPanel(CWindow(CSize(size.m_Width/2,size.m_Height,1,1,size.m_Width),0,"/home")),
m_RightPanel(CWindow(CSize(size.m_Width/2,size.m_Height,size.m_Width/2,1,size.m_Height),0,"/home")),
m_Menu(CMenu(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1,size.m_Height),0, this)),
m_Input(CInputDialog(CSize(size.m_Width/2,size.m_Height*0.5,size.m_Width/4,size.m_Height*0.2,size.m_Height),0)),
m_Confirm(CConfirmDialog(CSize(size.m_Width/2,size.m_Height*0.5,size.m_Width/4,size.m_Height*0.2,size.m_Height),0))
{


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
            if(m_ActiveWindow->m_Selected!=0)
                m_ActiveWindow->m_Selected--;
            else
                m_ActiveWindow->m_Selected=0;
            if( m_ActiveWindow->iter!=m_ActiveWindow->m_Items->begin())
                 m_ActiveWindow->iter--;
            if(m_ActiveWindow->m_Selected>15){
                m_ActiveWindow->tt--;
            }
            break;
        case 's':
        case 'S':
            m_ActiveWindow->m_Selected++;
            if(m_ActiveWindow->m_Selected>15){
                m_ActiveWindow->tt++;
            }
            if( m_ActiveWindow->m_Selected==1&&m_ActiveWindow->m_Selected!=0)
                m_ActiveWindow->iter=m_ActiveWindow->m_Items->begin();
            else {
                m_ActiveWindow->iter++;
               if( m_ActiveWindow->iter==m_ActiveWindow->m_Items->end())
                   m_ActiveWindow->iter--;
            }

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
            if(m_ActiveWindow->m_Selected!=0){
                m_ActiveWindow->iter->second->Select();
                m_ActiveWindow->m_Selecteditems.insert({iter->second->m_Path,iter->second});
            }
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
            m_Confirm.m_items=m_ActiveWindow->m_Items;
            m_Confirm.win=m_ActiveWindow;
            m_Confirm.op=1;
            m_Scene=&m_Confirm;

            }
            break;
        case '3':
            if(m_ActiveWindow->m_Selected!=0) {
                m_Input.Setup(this,8,"Enter path",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items);
                m_Scene = &m_Input;
            }
            break;
        case '4':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(this,10,"Enter file name",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items);
                m_Scene=&m_Input;
            }
            break;

        case '5':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(this,12,"Enter folder name",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items);
                m_Scene=&m_Input;
            }
            break;
        case '6':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(this,9,"Enter path",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items);
                m_Input.win=m_ActiveWindow;
                m_Scene=&m_Input;
            }
            break;

        case '7':
        case 44:
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








