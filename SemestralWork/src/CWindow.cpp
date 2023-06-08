
#include <iomanip>
#include "CWindow.h"
#include "filesystem"
#include "../libs/rang.hpp"

using namespace rang;
using namespace std;

void CWindow::Print() {

    if (m_Selected <= 15) {
        m_FromItem = m_Items->begin();
    }
    if (m_Selected >= m_Items->size() + 1) {
        m_Selected = 0;
        iter = m_Items->begin();
        m_FromItem = m_Items->begin();
    }
    PrintBorders();
    moveto(m_Size.m_PosX + 2, m_Size.m_PosY + 4);

    if (m_Selected == 0) {
        cout << bg::blue << "/.." << setw(m_Size.m_Width - 3) << style::reset;
    } else {
        cout << "/.." << setw(m_Size.m_Width - 3);
    }

    int cnt = 0;
    for (auto it = m_FromItem; it != m_Items->end(); ++it, cnt++) {
        if (cnt == 15) {
            break;
        }

        moveto(m_Size.m_PosX + 2, m_Size.m_PosY + 5 + cnt);
        if (m_Selected != 0 && (it->second.get() == iter->second.get())) {
            cout << bg::blue;
            it->second->Print();
            cout << setw(m_Size.m_Width - it->second->m_Name.size()) << style::reset;
            moveto((int) (m_Size.m_Width) + m_Size.m_PosX, m_Size.m_PosY + 5 + cnt);
            cout << bg::blue << "|" << style::reset;
        } else {

            if (it->second->m_isSelected) {
                cout << fg::yellow;
                it->second->Print();
                cout << fg::reset << setw(m_Size.m_Width - it->second->m_Name.size());
            } else {
                it->second->Print();
                cout << setw(m_Size.m_Width - it->second->m_Name.size());
            }
            moveto((int) (m_Size.m_Width) + m_Size.m_PosX, m_Size.m_PosY + 4 + cnt + 1);
            cout << "|";
        }
    }

    moveto(2, m_Size.m_AbsPosY + 1);
}

CWindow::CWindow(CSize size, string Path) : CAbsWidnow(size, this), m_Dir(CDir(Path, 2, NULL)) {
    m_CurrFile = NULL;
    m_Dir.Open(&m_Items, &m_CurrFile);
    iter = m_Items->begin();
    m_FromItem = m_Items->begin();

}

void CWindow::Enter() {

    if (m_Selected == 0) {
        if (m_CurrFile->m_InFolder != NULL) {
            if (filesystem::exists(m_CurrFile->m_InFolder->m_Path)) {
                m_CurrFile->m_InFolder->Open(&m_Items, &m_CurrFile);
                iter = m_Items->begin();
                m_Selected = 0;
            } else
                throw logic_error("Folder doesn't exists");
        } else {
            if (filesystem::exists(filesystem::path(m_CurrFile->m_Path).parent_path())) {
                m_Dir = CDir(filesystem::path(m_CurrFile->m_Path).parent_path(), 2, NULL);
                m_Dir.Open(&m_Items, &m_CurrFile);
                m_Selected = 0;
            } else
                throw logic_error("Folder doesn't exists");

        }
    } else {
        if (iter->second->IsReadable()) {
            iter->second->Open(&m_Items, &m_CurrFile);
            iter = m_Items->begin();
            m_Selected = 0;
        }

    }
    m_Selecteditems.clear();

}

void CWindow::PrintBorders() {
    moveto(m_Size.m_PosX, m_Size.m_PosY);
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout << "-";
    }
    moveto(m_Size.m_PosX + 2, 1);
    cout << m_CurrFile->m_Path;
    moveto(m_Size.m_PosX + 2, m_Size.m_PosY + 2);
    cout << "  NAME  ";
    for (size_t i = 0; i < m_Size.m_Height; ++i) {
        moveto(m_Size.m_PosX + 1, i);
        cout << "|";
        moveto((int) (m_Size.m_Width) + m_Size.m_PosX, i);
        cout << "|";
        moveto(m_Size.m_PosX, i);
    }
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout << "-";
    }
    moveto(m_Size.m_PosX, m_Size.m_Height * 0.9);
    for (size_t i = 1; i < m_Size.m_Width; ++i) {
        cout << "-";
    }
    moveto(m_Size.m_PosX + 2, m_Size.m_Height * 0.9 + 1);
    if (m_Selected != 0) {
        cout << (iter)->second->m_Name;
    } else {
        cout << "/..";
    }

}

void CWindow::Jump(string to) {
    m_Dir = CDir(to, 2, NULL);
    m_Dir.Open(&m_Items, &m_CurrFile);
    m_Selected = 0;
}

void CWindow::ReadKey() {}