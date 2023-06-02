

#include "CInputDialog.h"
#include "rang.hpp"
#include <unistd.h>
#include <termios.h>
#include <iostream>
using namespace rang;
CInputDialog::CInputDialog(CSize size, unsigned int Selected, std::string Name) : CAbsWidnow(size, Selected, Name,this) {
    op=0;
    m_Content.push_back("[YES]");
    m_Content.push_back("[No]");
    m_Label="Zadej Vstup";
}

void CInputDialog::Print() {

    if(m_Selected>=m_Content.size()){
        m_Selected=0;
    }
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        for (size_t j =1; j < m_Size.m_Width; ++j) {
            cout<<" ";
        }
    }
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    //Horni
    for (size_t i =1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<"*"<<style::reset;

    }
    moveto(m_Size.m_PosX+3,m_Size.m_PosY+4);
    cout<<m_Label;

    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        cout<<bg::black<<"*"<<style::reset;
        moveto((int)(m_Size.m_Width)+m_Size.m_PosX-1,i);
        cout<<bg::black<<"*"<<style::reset;
        moveto(m_Size.m_PosX,i);
    }
    //Dolni


    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<"*"<<style::reset;

    }
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


}

void CInputDialog::ReadKey() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    moveto(m_Size.m_PosX+4,m_Size.m_PosY+8);
    std::getline(std::cin, m_input);
    parseString(m_input,':');

    Enter();
   // m_lastActive->m_Scene=m_lastActive;


}

void CInputDialog::Enter() {

        switch (op) {
            case 1:
                Delete(m_input,m_items);
                break;
            case 2:
                Copy(m_reg,m_path,m_items);
                break;
            case 3:
                if(m_items->empty())
                    throw std::invalid_argument("");


                Move(m_reg,m_path,m_items);
                break;
            case 4:
                //Create();
                break;
            case 5:
                //Find by
                break;
            case 6:
                //Conacat by
                break;
            case 7:
                //Dedup by
                break;
            case 8:
                Copy(m_SelectedItem,m_input);
                break;
            case 9:
                Move(m_SelectedItem,m_input);
                break;
            case 10:
                CreateFile(m_input,m_items);
                break;
            case 12:
                CreateFolder(m_input,m_items);
                break;
            case 13:
                CreateLink(m_input,m_SelectedItem,m_items);
                break;

        }
        op=0;
        m_lastActive->m_Scene=m_lastActive;


}

void CInputDialog::Run() {

        Print();
        ReadKey();
        //clear();


}

void CInputDialog::parseString(const string &input, char delimiter) {
    std::string::size_type start = 0;
    std::string::size_type end = input.find(delimiter);

    while (end != std::string::npos) {
        m_reg=input.substr(start, end - start);

        start = end + 1;
        end = input.find(delimiter, start);
    }


    m_path=input.substr(start);

}


