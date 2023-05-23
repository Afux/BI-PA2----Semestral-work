

#ifndef SEMESTRALWORK_CPERMISSION_H
#define SEMESTRALWORK_CPERMISSION_H
#include "iostream"

using namespace std;
class CPermission {
public:
    string m_type;
    void DeletePermision();
    string GetPermision();
    void SetPermision( string type );
};


#endif //SEMESTRALWORK_CPERMISSION_H
