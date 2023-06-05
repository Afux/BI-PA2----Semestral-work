

#include "CAbsWidnow.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "regex"

using namespace std;

int CAbsWidnow::clear() {
    return system("clear");
}

void CAbsWidnow::moveto(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";

}

CAbsWidnow::CAbsWidnow(CSize size, unsigned int Selected, CAbsWidnow* Scene): m_Size(size),m_Selected(Selected),m_Scene(Scene){
    Oper=CManagerOPs();
}

void CAbsWidnow::Refresh() {
        clear();
        Print();
}


CAbsWidnow::~CAbsWidnow() {}

