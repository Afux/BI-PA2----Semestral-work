
#include "CManager.h"
#include "CDir.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
void CManager::Print() {
    clear();

    m_LeftPanel.Print();
    m_RightPanel.Print();
    //m_Menu.Print();
    //m_Confirm.Print();
    m_HelpBar.Print();

}

CManager::CManager(CSize size, std::string Name, unsigned int Selected) :  CAbsWidnow(size, Selected, Name,this),
m_HelpBar(CHelpBar(CSize(size.m_Width/2,size.m_Height,1, size.m_Height+1),0,"BAR")),
m_LeftPanel(CWindow(CSize(size.m_Width/2,size.m_Height,1,1),0,"Window","/home/afu")),
m_RightPanel(CWindow(CSize(size.m_Width/2,size.m_Height,size.m_Width/2,1),0,"Window","/home/afu/PA1/df")),
m_Menu(CMenu(CSize(size.m_Width/2,size.m_Height*0.7,size.m_Width/4,size.m_Height*0.1),0,"Menu")),
m_Input(CInputDialog(CSize(size.m_Width/4,size.m_Height*0.2,size.m_Width/4,size.m_Height*0.2),0,"Menu")),
m_Confirm(CConfirmDialog(CSize(size.m_Width/2,size.m_Height*0.5,size.m_Width/4,size.m_Height*0.2),0,"Menu"))
{

   // m_LeftPanel.m_Items=&m_Start.m_currItems;
   // m_RightPanel.m_Items=&m_Start.m_currItems;

    m_ActivePanel=this;
    m_ActiveWindow=&m_LeftPanel;


}

void CManager::Run() {

    while (1){
        m_ActivePanel->Print();
        m_ActivePanel->ReadKey();

        // Refresh();
    }
}

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
            break;
        case 's':
        case 'S':
            m_ActiveWindow->m_Selected++;
            break;
        case 'n':
        case 'N':
            m_ActiveWindow=NextWind();
            break;
        case 'd':
        case 'D':
            m_Confirm.m_lastActive= this;
            m_ActivePanel=&m_Confirm;
          //  m_Scene=&m_Confirm;

            break;
        case 'e':
        case 'E':
            m_ActiveWindow->Enter();
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


