

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

CAbsWidnow::CAbsWidnow(CSize size, unsigned int Selected, std::string Name): m_Size(size),m_Selected(Selected),m_Name(Name){}

void CAbsWidnow::ReadKey() {
   // Refresh();

    termios term;
    tcgetattr(STDIN_FILENO, &term);

    term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    char c;
    std::cin >> c;


        switch(c) {
            case 'w':
            case 'W':
                m_Selected--;
                break;
            case 's':
            case 'S':
                m_Selected++;
                break;

        }



    term.c_lflag |= ECHO | ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

}

void CAbsWidnow::Refresh() {
        clear();
        Print();

}

