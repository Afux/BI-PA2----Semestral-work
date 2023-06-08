

#include "CInputDialog.h"
#include "../libs/rang.hpp"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "filesystem"
using namespace rang;
using namespace std;
namespace fs = std::filesystem;
CInputDialog::CInputDialog(CSize size) : CAbsWidnow(size,this),m_errDialog(size) {
    op=0;
    m_Label="Enter input";
}

void CInputDialog::Print() {

    if(m_Selected>=m_Content.size()){
        m_Selected=0;
    }

    ClearDialogSpace();
    PrintBorders();
    PrintLabel();

    moveto(1,m_Size.m_AbsPosY+3);

}

void CInputDialog::ReadKey() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    cout<<bg::yellow<<m_Label<<": "<<bg::reset;

     std::getline(std::cin, m_input);
    if (cin.eof()) {
        throw logic_error("EOF");
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

        switch (op) {
            case 1:
                try{
                    Oper.Delete(m_input,&CurrDir->m_items);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                *WinSelected=0;

                break;
            case 2:
                try{
                    Oper.Copy(m_reg,m_path,&CurrDir->m_items);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                break;
            case 3:
                try{
                    Oper.Move(m_reg,m_path,&CurrDir->m_items);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                *WinSelected=0;
                break;

            case 5:
                try{
                    Oper.FindByText(m_input,&CurrDir->m_items);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                break;
            case 6:
                try{
                    Oper.ConcatFiles(&CurrDir->m_items,m_input);
                }
               catch (logic_error &e){
                   m_errDialog.Setup(m_lastActive,e.what());
                   m_errDialog.Run();
               }

                break;
            case 7:
                try{
                    Oper.Deduplicate(m_SelectedItem,&CurrDir->m_items);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }

                break;
            case 8:
                try{
                    Oper.Copy(m_SelectedItem,m_input);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                break;
            case 9:
                try{
                    Oper.Move(m_SelectedItem,m_input);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                *WinSelected=0;
                break;
            case 10:
                try{
                    Oper.CreateFile(m_input,CurrDir);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                catch (const fs::filesystem_error &e){
                    m_errDialog.Setup(m_lastActive,e.code().message());
                    m_errDialog.Run();
                }
                break;
            case 12:
                try{
                    Oper.CreateFolder(m_input,CurrDir);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                break;
            case 13:
                try{
                    Oper.CreateLink(m_input,m_SelectedItem,CurrDir);
                }
                catch (logic_error &e){
                    m_errDialog.Setup(m_lastActive,e.what());
                    m_errDialog.Run();
                }
                break;
            default:
                op=0;
                m_lastActive->m_Scene=m_lastActive;
                break;

        }
        op=0;
        m_lastActive->m_Scene=m_lastActive;


}

void CInputDialog::Run() {
        Print();
        ReadKey();
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

void CInputDialog::Setup(CItem *Curr,CAbsWidnow *lastActive, const int &Op, const string &Label, CItem *SelectedItem,unsigned int *WinSel) {
    CurrDir=Curr;
    m_lastActive=lastActive;
    op=Op;
    m_Label=Label;
    m_SelectedItem=SelectedItem;
    WinSelected=WinSel;
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


