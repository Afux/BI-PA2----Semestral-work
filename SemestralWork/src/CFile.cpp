
#include "CFile.h"
#include "filesystem"

CFile::CFile(std::string path, unsigned int size) : CItem(path, size) {

}

void CFile::Print() {
    cout<<m_Name<<endl;

}

void CFile::Copy(CItem *item) {

}

void CFile::Copy(vector<CItem *>) {

}

void CFile::Delete(CItem *item) {

}

void CFile::Delete(vector<CItem *> items) {

}

void CFile::Move(CItem *item, string dest) {

}

void CFile::Move(vector<CItem *>, string dest) {

}

void CFile::UpdateSize() {
    m_Size=filesystem::file_size(m_Path);
}

void CFile::SetDate(u_int year, u_int month, u_int day) {

}

void CFile::Deduplicate() {

}
