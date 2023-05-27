

#include "CAbsWidnow.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>

void CAbsWidnow::clear() {
    system("clear");
    //std::cout << "\033[3J";

}

void CAbsWidnow::moveto(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";

}

CAbsWidnow::CAbsWidnow(CSize size, unsigned int Selected, std::string Name, CAbsWidnow* Scene): m_Size(size),m_Selected(Selected),m_Name(Name),m_Scene(Scene){}



void CAbsWidnow::Refresh() {
        clear();
        Print();

}

