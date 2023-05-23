
#ifndef SEMESTRALWORK_CHELPBAR_H
#define SEMESTRALWORK_CHELPBAR_H
using namespace std;
#include "CSize.h"
#include "iostream"
#include "vector"
#include "CAbsWidnow.h"

class CHelpBar: public CAbsWidnow{
public:
    vector<string> m_Content;
   virtual void Print() override;
};


#endif //SEMESTRALWORK_CHELPBAR_H
