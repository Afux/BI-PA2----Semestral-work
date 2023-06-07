

#include "CAbsWidnow.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "regex"

using namespace std;

int CAbsWidnow::clear() const{
    return system("clear");
}

void CAbsWidnow::moveto(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";

}

CAbsWidnow::CAbsWidnow(CSize size, CAbsWidnow* Scene): m_Size(size),m_Scene(Scene){
    Oper=CManagerOPs();
    m_Selected=0;
}



CAbsWidnow::~CAbsWidnow() = default;