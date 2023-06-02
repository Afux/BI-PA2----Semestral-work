
#include <iomanip>
#include "CWindow.h"
#include "rang.hpp"
using namespace rang;
void CWindow::Print() {

    if(m_Selected>=m_Items->size()){
        m_Selected=-1;
    }
    //clear();
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    moveto(m_Size.m_PosX+2,1);
    cout<<m_currDir.m_Path;
    moveto(m_Size.m_PosX+2,m_Size.m_PosY+2);
    cout<<"  NAME  ";
    moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+2);
    cout<<"  SIZE  ";
    moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+2);
    cout<<"  Modify  ";

    for (size_t i =0; i < m_Size.m_Height*0.8; ++i) {
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
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }

    moveto(m_Size.m_PosX+2,m_Size.m_PosY+4);
    if(m_Selected==0){
        cout << bg::blue<<"/.."<< setw(m_Size.m_Width-3)
             <<style::reset;
    }
    else{
        cout << "/.."<< setw(m_Size.m_Width-3);
    }



    for (size_t i = 0; i < m_Items->size() ; ++i) {
        if(i==15)
            break;
        moveto(m_Size.m_PosX+2,m_Size.m_PosY+5+i);
        if(i==m_Selected-1){



                cout << bg::blue;
                m_Items->at(i)->Print();
                cout<< setw(m_Size.m_Width-m_Items->at(i)->m_Name.size())
                    <<style::reset;

            moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+5+i);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.4)+1+m_Size.m_PosX,m_Size.m_PosY+5+i);
            cout << bg::blue<<m_Items->at(i)->m_Size<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+5+i);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+1+m_Size.m_PosX,m_Size.m_PosY+5+i);
            cout << bg::blue<<"13/03/2023"<<style::reset;
            moveto((int)(m_Size.m_Width)+m_Size.m_PosX,m_Size.m_PosY+5+i);
            cout<<bg::blue<<"|"<<style::reset;
        }


        else{


                m_Items->at(i)->Print();
                cout<<setw(m_Size.m_Width-m_Items->at(i)->m_Name.size());

            moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+4+i+1);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.4)+1+m_Size.m_PosX,m_Size.m_PosY+4+i+1);
            cout <<m_Items->at(i)->m_Size;
            moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+4+i+1);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.6)+1+m_Size.m_PosX,m_Size.m_PosY+4+i+1);
            cout <<"13/03/2023";
            moveto((int)(m_Size.m_Width)+m_Size.m_PosX,m_Size.m_PosY+4+i+1);
            cout<<"|";
        }

    }
    moveto(m_Size.m_PosX,m_Size.m_Height*0.7);
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    moveto(m_Size.m_PosX+2,m_Size.m_Height*0.7+1);

    if(m_Selected>=0){
        cout <<m_Items->at(m_Selected)->m_Name;

    } else{

    }
    moveto(2,m_Size.m_Height+1);

}

CWindow::CWindow(CSize size, unsigned int Selected, std::string Name,string Path)
:  CAbsWidnow(size, Selected, Name, this), m_StartDir(CDir(Path,2,NULL,NULL)),m_currDir(m_StartDir){

   m_Items=m_StartDir.FindDir("/home/afu/PA1/df");
   // m_Items=&m_currDir.m_items;

}

void CWindow::Run() {
    int i=0;
    while (i<10){
        ReadKey();
        Refresh();
        i++;
    }


}

void CWindow::ReadKey() {}

void CWindow::Enter() {
    if(m_Selected<0){
        if(m_Items->at(m_Selected)->m_inFolder!=NULL)
            m_Items->at(m_Selected)->m_inFolder->Open(&m_Items);
        else{

        }
    }
    else{
        m_Items->at(m_Selected)->Open(&m_Items);
       // m_currDir=dynamic_cast<CDir &> ( *m_Items->at(0) );
    }

    //m_currDir=dynamic_cast<CDir&>(*m_Items->at(m_Selected));
}
