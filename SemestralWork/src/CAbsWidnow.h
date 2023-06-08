

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
    /**
 * @brief This is a brief description of the function or class.
 *
 * This is a more detailed description of the function or class.
 * You can include information about parameters, return values, exceptions, etc.
 *
 * @param param1 Description of the first parameter.
 * @param param2 Description of the second parameter.
 * @return Description of the return value.
 * @throws ExceptionType Description of when this function throws an exception.
 */
    CAbsWidnow(CSize size, CAbsWidnow * Scene);
    virtual ~CAbsWidnow();
    CSize  m_Size;
    unsigned int m_Selected;
    CAbsWidnow* m_Scene;
    CManagerOPs Oper;
    typedef std::map<std::string ,std::shared_ptr<CItem>>::iterator MyIterator;
    MyIterator iter;

    virtual void Print()=0;
    virtual void  ReadKey()=0;
protected:
    int clear() const;
    void moveto(int x = 1, int y = 1);
private:
};


#endif //SEMESTRALWORK_CABSWIDNOW_H
