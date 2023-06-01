
#include "CLink.h"
#include "filesystem"
namespace fs = std::filesystem;
CLink::CLink(std::string path, unsigned int size,CItem* toFile,CItem *parr) : CItem(path, size,parr),m_toFile(toFile) {

    if(!fs::exists(path)) {
        if(fs::is_directory(toFile->m_Path))
            fs::create_directory_symlink(toFile->m_Path,path);
        else
            fs::create_symlink(toFile->m_Path,path);

    }
}

void CLink::Open(std::vector<CItem *> **item) {

}

void CLink::Print() {
    cout<<"*"<<m_Name;
}

void CLink::Copy(vector<CItem *> items, std::string to) {

}

void CLink::Copy(std::string to) {
    fs::copy_symlink(m_Path,to+"/"+m_Name);
}

void CLink::Delete() {
    fs::remove_all(m_Path);

}

void CLink::Delete(vector<CItem *> items) {

}

void CLink::Move(string dest) {
    Copy(dest);
    Delete();
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

CItem *CLink::Clone() {
    CItem *tmp = ( new CLink(*this));
    return tmp;
}
