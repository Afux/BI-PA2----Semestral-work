
#include <iomanip>
#include "CWindow.h"
#include "rang.hpp"
using namespace rang;
void CWindow::Print() {

    if(m_Selected>=m_Items->size()){
        m_Selected=0;
    }
    //clear();
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (int i =1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    moveto(m_Size.m_PosX+2,m_Size.m_PosY+2);
    cout<<"  NAME  "<<m_Selected;
    moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+2);
    cout<<"  SIZE  ";
    moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+2);
    cout<<"  Modify  ";

    for (int i =1; i < m_Size.m_Height*0.8; ++i) {
        moveto(m_Size.m_PosX+1,i);
        cout<<"|";
        moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,i);
        cout<<"|";
        moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,i);
        cout<<"|";
        moveto((int)(m_Size.m_Width)+m_Size.m_PosX,i);
        cout<<"|";
        moveto(m_Size.m_PosX,i);
    }
    for (int i = 1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }

    for (auto i = 0; i < m_Items->size() ; ++i) {
        moveto(m_Size.m_PosX+2,m_Size.m_PosY+4+i);
        if(i==m_Selected){

            cout << bg::blue<<m_Items->at(i)->m_Name<< setw(m_Size.m_Width-m_Items->at(i)->m_Name.size())
                 <<style::reset;

            moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.4)+1+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout << bg::blue<<222<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+1+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout << bg::blue<<"13/03/2023"<<style::reset;
            moveto((int)(m_Size.m_Width)+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout<<bg::blue<<"|"<<style::reset;
        }


        else{
            cout <<m_Items->at(i)->m_Name<<setw(m_Size.m_Width-m_Items->at(i)->m_Name.size());
            moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.4)+1+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout <<m_Items->at(i)->m_Size;
            moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.6)+1+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout <<"13/03/2023";
            moveto((int)(m_Size.m_Width)+m_Size.m_PosX,m_Size.m_PosY+4+i);
            cout<<"|";
        }

    }
    moveto(m_Size.m_PosX,m_Size.m_Height*0.7);
    for (int i = 1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    moveto(m_Size.m_PosX+2,m_Size.m_Height*0.7+1);

    cout <<m_Items->at(m_Selected)->m_Name;
    moveto(2,m_Size.m_Height+1);

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
