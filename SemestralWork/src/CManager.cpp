
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

CManager::CManager(CSize size, std::string path) :  CAbsWidnow(size,this),
m_HelpBar(CHelpBar(CSize(size.m_Width/2,size.m_Height,1, size.m_Height*0.8+1,size.m_Height))),
m_LeftPanel(CWindow(CSize(size.m_Width/2,size.m_Height*0.8,1,1,size.m_Width),path)),
m_RightPanel(CWindow(CSize(size.m_Width/2,size.m_Height*0.8,size.m_Width/2,1,size.m_Height),path)),
m_Menu(CMenu(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1,size.m_Height), this)),
m_Input(CInputDialog(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1,size.m_Height))),
m_Confirm(CConfirmDialog(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1,size.m_Height))),
m_ErrorDialog(CErrDialog(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1,size.m_Height)))
{

    m_runFlag= true;
    m_ActivePanel=this;
    m_ActiveWindow=&m_LeftPanel;

}

void CManager::Run() {
    while (m_runFlag){
        m_Scene->Print();
        m_Scene->ReadKey();
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
    if(c==EOF)
        m_runFlag=0;


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
                m_ActiveWindow->m_FromItem--;
            }
            break;
        case 's':
        case 'S':
            m_ActiveWindow->m_Selected++;
            if(m_ActiveWindow->m_Selected>15){
                m_ActiveWindow->m_FromItem++;
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
        case 'j':
        case 'J':
            m_ActiveWindow->Jump("/home");
            break;
        case 'k':
        case 'K':
            if(m_ActiveWindow->m_Selected!=0){
                m_ActiveWindow->iter->second->Select();
                if(m_ActiveWindow->iter->second->m_isSelected)
                    m_ActiveWindow->m_Selecteditems.insert({m_ActiveWindow->iter->first, m_ActiveWindow->iter->second});
                else{
                    m_ActiveWindow->m_Selecteditems.erase(m_ActiveWindow->iter->first);
                }
            }
            break;

        case '1':
        case '+':
            if(m_ActiveWindow->m_Selected!=0){
                m_Menu.Setup(this,m_ActiveWindow->m_Items,&m_ActiveWindow->m_Selecteditems,m_ActiveWindow->iter->second.get(),m_ActiveWindow);
                m_Scene=&m_Menu;
            }

            break;
        case '2':
            if(m_ActiveWindow->m_Selected!=0){
                m_Confirm.Setup(this,m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items,m_ActiveWindow,1);
                m_Scene=&m_Confirm;

            }
            break;
        case '3':
            if(m_ActiveWindow->m_Selected!=0) {
                m_Input.Setup(this,8,"Enter path",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items,m_ActiveWindow);
                m_Scene = &m_Input;
            }
            break;
        case '4':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(this,10,"Enter file name",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items,m_ActiveWindow);
                m_Scene=&m_Input;
            }
            break;

        case '5':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(this,12,"Enter folder name",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items,m_ActiveWindow);
                m_Scene=&m_Input;
            }
            break;
        case '6':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(this,9,"Enter path",m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items,m_ActiveWindow);
                m_Input.win=m_ActiveWindow;
                m_Scene=&m_Input;
            }
            break;

        case '7':
        case '\x04':
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








