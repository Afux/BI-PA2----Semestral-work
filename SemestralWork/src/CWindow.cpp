
#include <iomanip>
#include "CWindow.h"
#include "rang.hpp"
using namespace rang;
void CWindow::Print() {
    if(m_Selected>=TESTING.size()){
        m_Selected=0;
    }
    clear();
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (int i = m_Size.m_PosX; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    moveto(m_Size.m_PosX+2,m_Size.m_PosY+2);
    cout<<"  NAME  "<<m_Selected;
    moveto((int)(m_Size.m_Width*0.4+6),m_Size.m_PosY+2);
    cout<<"  SIZE  ";
    moveto((int)(m_Size.m_Width*0.6+6),m_Size.m_PosY+2);
    cout<<"  Modify  ";

    for (int i = m_Size.m_PosY; i < m_Size.m_Height; ++i) {
        moveto(m_Size.m_PosX+1,i);
        cout<<"|";
        moveto((int)(m_Size.m_Width*0.4),i);
        cout<<"|";
        moveto((int)(m_Size.m_Width*0.6),i);
        cout<<"|";
        moveto((int)(m_Size.m_Width),i);
        cout<<"|";
        moveto(1,i);
    }
    for (int i = 0; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    for (int i = 0; i < TESTING.size() ; ++i) {
        moveto(m_Size.m_PosX+2,m_Size.m_PosY+4+i);

        if(i==m_Selected){
            cout << bg::blue<<TESTING[i]<< setw(m_Size.m_Width-TESTING[i].size())
                 <<style::reset;

            moveto((int)(m_Size.m_Width*0.4),m_Size.m_PosY+4+i);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.4)+1,m_Size.m_PosY+4+i);
            cout << bg::blue<<222<<style::reset;
            moveto((int)(m_Size.m_Width*0.6),m_Size.m_PosY+4+i);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+1,m_Size.m_PosY+4+i);
            cout << bg::blue<<"13/03/2023"<<style::reset;
            moveto((int)(m_Size.m_Width),m_Size.m_PosY+4+i);
            cout<<bg::blue<<"|"<<style::reset;
        }


        else{
            cout <<TESTING[i]<<setw(m_Size.m_Width-TESTING[i].size());
            moveto((int)(m_Size.m_Width*0.4),m_Size.m_PosY+4+i);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.4)+1,m_Size.m_PosY+4+i);
            cout <<222;
            moveto((int)(m_Size.m_Width*0.6),m_Size.m_PosY+4+i);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.6)+1,m_Size.m_PosY+4+i);
            cout <<"13/03/2023";
            moveto((int)(m_Size.m_Width),m_Size.m_PosY+4+i);
            cout<<"|";
        }

    }


    moveto(m_Size.m_Width+1,m_Size.m_Height+1);

}

CWindow::CWindow(CSize size, unsigned int Selected, std::string Name)
:  CAbsWidnow(size, Selected, Name){}

void CWindow::Run() {
    int i=0;
    while (i<10){
        ReadKey();
        Refresh();
        i++;
    }


}
