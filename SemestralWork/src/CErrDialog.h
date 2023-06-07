//
// Created by afu on 06.06.23.
//

#ifndef SEMESTRALWORK_CERRDIALOG_H
#define SEMESTRALWORK_CERRDIALOG_H

#include "iostream"
#include "CAbsWidnow.h"
class CErrDialog:CAbsWidnow {
public:
    CErrDialog(CSize size);
    std::string m_Label;
    CAbsWidnow * m_lastActive;

    void Print() override;
    void PrintBorders();
    void ClearDialogSpace();
    void PrintLabel();
    void Setup(CAbsWidnow* lastActive, const std::string &Label);
    void ReadKey() override;
    void Run();
};


#endif //SEMESTRALWORK_CERRDIALOG_H
