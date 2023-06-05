

#ifndef SEMESTRALWORK_CABSWIDNOW_H
#define SEMESTRALWORK_CABSWIDNOW_H
#include "iostream"
#include "CSize.h"
#include "CItem.h"
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include <memory>
#include "CManagerOPs.h"

class CAbsWidnow {
public:
    CAbsWidnow(CSize size, unsigned int Selected, CAbsWidnow * Scene);

    virtual ~CAbsWidnow();
    CSize  m_Size;
    unsigned int m_Selected;
    CAbsWidnow* m_Scene;
    CManagerOPs Oper;
   std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, std::shared_ptr<CItem>>> iter;

    void Refresh();
    virtual void Print()=0;
    virtual void  ReadKey()=0;

    int clear();
    void moveto(int x = 1, int y = 1);

   //OPs

protected:
private:
};


#endif //SEMESTRALWORK_CABSWIDNOW_H
