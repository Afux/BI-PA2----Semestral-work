

#include "CAbsWidnow.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "regex"

using namespace std;

int CAbsWidnow::clear() const{
    return system("clear");
}

void CAbsWidnow::moveto(int x, int y) const {
    std::cout << "\033[" << y << ";" << x << "H";

}

CAbsWidnow::CAbsWidnow(CSize size, CAbsWidnow* Scene): m_Size(size),m_Scene(Scene){
    Oper=CManagerOPs();
    m_Selected=0;
    m_isrunning= true;
}

void CAbsWidnow::cursorOff() {

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void CAbsWidnow::cursorOn() {
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}


CAbsWidnow::~CAbsWidnow() = default;