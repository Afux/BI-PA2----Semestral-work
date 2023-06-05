
#include <iomanip>
#include "CWindow.h"
#include "../libs/rang.hpp"
using namespace rang;
using namespace std;

void CWindow::Print() {

    if(m_Selected<=15){

        tt=m_Items->begin();

    }

    if(m_Selected>=m_Items->size()+1){
        m_Selected=0;
        iter=m_Items->begin();
        tt=m_Items->begin();
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


    int cnt=0;

    for (auto it = tt; it != m_Items->end() ; ++it,cnt++) {
        if(cnt==15){
            break;
        }

        moveto(m_Size.m_PosX+2,m_Size.m_PosY+5+cnt);
        if(m_Selected!=0&&(it->second.get()==iter->second.get())){



                cout << bg::blue;
                it->second->Print();
                cout<< setw(m_Size.m_Width-it->second->m_Name.size())
                    <<style::reset;

            moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+5+cnt);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.4)+1+m_Size.m_PosX,m_Size.m_PosY+5+cnt);
            cout << bg::blue<<it->second->m_Size<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+5+cnt);
            cout<<bg::blue<<"|"<<style::reset;
            moveto((int)(m_Size.m_Width*0.6)+1+m_Size.m_PosX,m_Size.m_PosY+5+cnt);
            cout << bg::blue<<"13/03/2023"<<style::reset;
            moveto((int)(m_Size.m_Width)+m_Size.m_PosX,m_Size.m_PosY+5+cnt);
            cout<<bg::blue<<"|"<<style::reset;
        }


        else{

                if(it->second->m_isSelected){
                    cout<<fg::yellow;
                    it->second->Print();
                    cout<<fg::reset<<setw(m_Size.m_Width-it->second->m_Name.size());
                }
                else{

                   it->second->Print();
                    cout<<setw(m_Size.m_Width-it->second->m_Name.size());

                }


            moveto((int)(m_Size.m_Width*0.4)+m_Size.m_PosX,m_Size.m_PosY+4+cnt+1);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.4)+1+m_Size.m_PosX,m_Size.m_PosY+4+cnt+1);
            cout <<it->second->m_Size;
            moveto((int)(m_Size.m_Width*0.6)+m_Size.m_PosX,m_Size.m_PosY+4+cnt+1);
            cout<<"|";
            moveto((int)(m_Size.m_Width*0.6)+1+m_Size.m_PosX,m_Size.m_PosY+4+cnt+1);
            cout <<"13/03/2023";
            moveto((int)(m_Size.m_Width)+m_Size.m_PosX,m_Size.m_PosY+4+cnt+1);
            cout<<"|";
        }

    }
    moveto(m_Size.m_PosX,m_Size.m_Height*0.7);
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<"-";
    }
    moveto(m_Size.m_PosX+2,m_Size.m_Height*0.7+1);

    if(m_Selected-1< m_Items->size()){
       // cout <<(iter)->second->m_Name;

    } else{

    }
    moveto(2,m_Size.m_Height+1);

}

CWindow::CWindow(CSize size, unsigned int Selected,string Path)
:  CAbsWidnow(size, Selected, this), m_StartDir(CDir(Path,2,NULL,NULL)),m_currDir(m_StartDir){
    m_CurrFile=NULL;
   m_Items=m_StartDir.FindDir("/home/afu/PA1/df",&m_CurrFile);
    iter=m_Items->begin();
    tt=m_Items->begin();
    // m_Items=&m_currDir.m_items;

}



void CWindow::ReadKey() {}

void CWindow::Enter() {
    if(m_Selected==0){
        if(m_CurrFile!=NULL){
            m_CurrFile->Open(&m_Items,&m_CurrFile);
            iter=m_Items->begin();
            m_Selected=0;
        }
        else{
            m_currDir= CDir (filesystem::path(iter->second->m_Path).parent_path().parent_path(),2,NULL,NULL);
            m_Items=&m_currDir.m_items;
        }
    }
    else{
         iter->second->Open(&m_Items,&m_CurrFile);
         iter=m_Items->begin();
        m_Selected=0;

    }

}
