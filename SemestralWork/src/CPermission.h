

#ifndef SEMESTRALWORK_CPERMISSION_H
#define SEMESTRALWORK_CPERMISSION_H
#include "iostream"

class CPermission {
public:
    std::string m_type;
    void DeletePermision();
    std::string GetPermision();
    void SetPermision( std::string type );
};


#endif //SEMESTRALWORK_CPERMISSION_H
