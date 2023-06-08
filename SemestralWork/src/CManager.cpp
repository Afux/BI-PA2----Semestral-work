
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
    while (m_isrunning){
        m_Scene->Print();
        m_Scene->ReadKey();
    }
    clear();
}
/*
 * OP---
 *
 *
 *
 */


void CManager::ReadKey() {
    cursorOff();

    char c;
    std::cin >> c;



    switch(c) {
        case 'w':
        case 'W':
            if(m_ActiveWindow->m_Selected!=0)
                m_ActiveWindow->m_Selected--;
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
            try{
                m_ActiveWindow->Enter();
            }
            catch (...){
                moveto(1,m_Size.m_AbsPosY+1);
                cout<<"Cant open dir";
                m_runFlag= false;
            }
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

                m_Menu.Setup(m_ActiveWindow->m_CurrFile,this,m_ActiveWindow);
                m_Scene=&m_Menu;

            break;
        case '2':
            if(m_ActiveWindow->m_Selected!=0){
                m_Confirm.Setup(this,m_ActiveWindow->iter->second.get(),m_ActiveWindow->m_Items,m_ActiveWindow,1);
                m_Scene=&m_Confirm;
            }
            break;
        case '3':
            if(m_ActiveWindow->m_Selected!=0) {
                m_Input.Setup(m_ActiveWindow->m_CurrFile,this,8,"Enter path",m_ActiveWindow->iter->second.get(),m_ActiveWindow);
                m_Scene = &m_Input;
            }
            break;
        case '4':
                m_Input.Setup(m_ActiveWindow->m_CurrFile,this,10,"Enter file name",nullptr,m_ActiveWindow);
                m_Scene=&m_Input;
            break;

        case '5':
                m_Input.Setup(m_ActiveWindow->m_CurrFile,this,12,"Enter folder name", nullptr,m_ActiveWindow);
                m_Scene=&m_Input;
            break;
        case '6':
            if(m_ActiveWindow->m_Selected!=0)
            {
                m_Input.Setup(m_ActiveWindow->m_CurrFile,this,9,"Enter path",m_ActiveWindow->iter->second.get(),m_ActiveWindow);
                m_Scene=&m_Input;
            }
            break;

        case '7':
        case '\x04':
            m_isrunning= false;
            break;


    }
    cursorOn();



}



CWindow *CManager::NextWind() {
    if(m_ActiveWindow==&m_LeftPanel)
        return &m_RightPanel;
    else
        return &m_LeftPanel;
}








