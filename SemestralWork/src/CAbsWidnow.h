

#ifndef SEMESTRALWORK_CABSWIDNOW_H
#define SEMESTRALWORK_CABSWIDNOW_H
#include "iostream"
#include "CSize.h"

class CAbsWidnow {
public:
    CAbsWidnow(CSize size, unsigned int Selected, std::string Name);

    virtual ~CAbsWidnow()
    { }
    CSize  m_Size;
    unsigned int m_Selected;
    std::string  m_Name;

    void Refresh();
    virtual void Print()=0;
    void  ReadKey();
    void clear();
    void moveto(int x = 1, int y = 1);

protected:
private:
};


#endif //SEMESTRALWORK_CABSWIDNOW_H
