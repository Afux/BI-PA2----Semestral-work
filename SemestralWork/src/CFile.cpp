
#include "CFile.h"
#include "filesystem"

CFile::CFile(std::string path, unsigned int size) : CItem(path, size) {

}

void CFile::Print() {
    cout<<m_Name;

}

void CFile::Copy(string to) {
    std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);

}

void CFile::Copy(vector<CItem *> items, string to) {

}

void CFile::Delete() {
    std::filesystem::remove_all(m_Path);
}

void CFile::Delete(vector<CItem *> items) {

}

void CFile::Move(string dest) {
    std::filesystem::copy(m_Path, dest, std::filesystem::copy_options::recursive);
    Delete();
}

void CFile::Move(vector<CItem *> items, string dest) {

}

void CFile::UpdateSize() {
    m_Size=filesystem::file_size(m_Path);
}

void CFile::SetDate(u_int year, u_int month, u_int day) {

}

void CFile::Deduplicate() {

}

std::string CFile::RemoveDialog() {
    std::string tmp="File "+m_Name+" will be removed";
    return tmp;
}

std::string CFile::CreateDialog(std::string NewName) {
    std::string tmp="File "+NewName+" will be created";
    return tmp;
}

std::string CFile::RenameDialog(std::string NewName) {
    std::string tmp="File "+m_Name+" will be removed to "+NewName;
    return tmp;
}

void CFile::Open(std::vector<CItem*> **item) {

}
