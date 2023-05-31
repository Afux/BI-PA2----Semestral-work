
#include "CLink.h"

CLink::CLink(std::string path, unsigned int size,CItem* toFile) : CItem(path, size),m_toFile(toFile) {

}

void CLink::Open(std::vector<CItem *> **item) {

}

void CLink::Print() {
    cout<<"*"<<m_Name;
}

void CLink::Copy(vector<CItem *> items, std::string to) {

}

void CLink::Copy(std::string to) {

}

void CLink::Delete() {

}

void CLink::Delete(vector<CItem *> items) {

}

void CLink::Move(string dest) {

}

void CLink::Move(vector<CItem *>, string dest) {

}

void CLink::UpdateSize() {

}

void CLink::SetDate(u_int year, u_int month, u_int day) {

}

void CLink::Deduplicate() {

}

std::string CLink::RemoveDialog() {
    return std::string();
}

std::string CLink::CreateDialog(std::string NewName) {
    return std::string();
}

std::string CLink::RenameDialog(std::string NewName) {
    return std::string();
}
