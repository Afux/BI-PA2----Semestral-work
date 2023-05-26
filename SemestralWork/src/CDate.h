
#ifndef SEMESTRALWORK_CDATE_H
#define SEMESTRALWORK_CDATE_H
#include "iostream"
class CDate {
public:
    CDate(unsigned int Year, unsigned int Motnh, unsigned  int Day);
    unsigned int m_Year;
    unsigned int   m_Month;
    unsigned int  m_Day;
    friend std::ostream &operator<<(std::ostream &os, const CDate &x);
};


#endif //SEMESTRALWORK_CDATE_H
