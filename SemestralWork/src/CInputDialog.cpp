

#include "CInputDialog.h"
#include "../libs/rang.hpp"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "filesystem"
using namespace rang;
using namespace std;
namespace fs = std::filesystem;
CInputDialog::CInputDialog(CSize size) : CAbsWidnow(size,this),m_errDialog(CErrDialog(size)) {
    op=0;
    m_Label="Enter input";
}

void CInputDialog::Print() {



    ClearDialogSpace();
    PrintBorders();
    PrintLabel();

    moveto(1,m_Size.m_AbsPosY+2);

}

void CInputDialog::ReadKey() {
  cursorOn();
    cout<<bg::yellow<<m_Label<<": "<<bg::reset;
    std::getline(std::cin, m_input);
    if (cin.eof()) {
        m_lastActive->m_isrunning= false;
    }
    if(m_input.empty()){
        op=0;
        m_lastActive->m_Scene=m_lastActive;
    }

    parseString(m_input,':');
    Enter();
    op=0;
    m_lastActive->m_Scene=m_lastActive;
}

void CInputDialog::Enter() {
    try{
        switch (op) {
            case 1:
                Oper.Delete(m_input,CurrDir);
                m_winActive->m_Selected=0;
                break;
            case 2:
                Oper.Copy(m_reg,m_path,CurrDir);
                break;
            case 3:
                Oper.Move(m_reg,m_path, CurrDir);
                m_winActive->m_Selected=0;
                break;
            case 5:
                Oper.FindByText(m_input,CurrDir);
                break;
            case 6:
                //selected
                Oper.ConcatFiles(m_SelectedItems,m_input);
                break;
            case 7:
                Oper.Deduplicate(m_SelectedItem,CurrDir);
                break;
            case 8:
                Oper.Copy(m_SelectedItem,m_input);
                break;
            case 9:
                Oper.Move(m_SelectedItem,m_input);
                m_winActive->m_Selected=0;
                break;
            case 10:
                Oper.CreateFile(m_input,CurrDir);
                break;
            case 12:
                Oper.CreateFolder(m_input,CurrDir);
                break;
            case 13:
                Oper.CreateLink(m_input,m_SelectedItem,CurrDir);
                break;
            default:
                op=0;
                m_lastActive->m_Scene=m_lastActive;
                break;

        }
    }
    catch (logic_error &e){
        m_errDialog.Setup(m_lastActive,e.what());
        m_errDialog.Run();
    }
    catch (const fs::filesystem_error &e){
        m_errDialog.Setup(m_lastActive,e.code().message());
        m_errDialog.Run();
    }

    op=0;
    m_lastActive->m_Scene=m_lastActive;


}

void CInputDialog::Run() {
    Print();
    ReadKey();
}

//...
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

void CInputDialog::Setup(CItem *Curr,CAbsWidnow *lastActive, const int &Op, const string &Label, CItem *SelectedItem,CAbsWidnow *lastWin, std::map<std::string ,std::shared_ptr<CItem>> *Selecteditems) {
    CurrDir=Curr;
    m_lastActive=lastActive;
    op=Op;
    m_Label=Label;
    m_SelectedItem=SelectedItem;
    m_winActive=lastWin;
    m_SelectedItems=Selecteditems;
}

void CInputDialog::PrintBorders() {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =1; i < m_Size.m_Width; ++i) {
        cout<<bg::black<<"*"<<style::reset;
    }
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

}

void CInputDialog::ClearDialogSpace() {
    moveto(m_Size.m_PosX,m_Size.m_PosY);
    for (size_t i =m_Size.m_PosY; i < m_Size.m_Height+m_Size.m_PosY; ++i) {
        moveto(m_Size.m_PosX,i);
        for (size_t j =1; j < m_Size.m_Width; ++j) {
            cout<<" ";
        }
    }
}

void CInputDialog::PrintLabel() {
    moveto(m_Size.m_PosX+3,m_Size.m_PosY+4);
    cout<<m_Label;
}


