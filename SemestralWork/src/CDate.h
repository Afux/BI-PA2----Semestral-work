
#ifndef SEMESTRALWORK_CDATE_H
#define SEMESTRALWORK_CDATE_H
using namespace std;
#include "iostream"
class CDate {
public:
    unsigned int m_Year;
    unsigned int   m_Month;
    unsigned int  m_Day;
    friend ostream &operator<<(ostream &os, const CDate &x);
};


#endif //SEMESTRALWORK_CDATE_H
