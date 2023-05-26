
#include "CDir.h"
#include "CFile.h"

#include "filesystem"
using directory_iterator = std::filesystem::directory_iterator;
using namespace std;
CDir::CDir( std::string path, unsigned int size,CDir * parr) : CItem(path, size),m_parr(parr) {

    for (const auto& dirEntry : filesystem::directory_iterator (path)){
       if(dirEntry.is_directory()){
             string s=dirEntry.path();
             CDir * temp = new CDir( CDir(s,2,this));
             CItem *tmp= temp;
             m_items.emplace_back(tmp);
       }
       else if(dirEntry.is_regular_file()){
           string s=dirEntry.path();
           CFile * temp = new CFile( CFile(s,2));
           CItem *tmp= temp;
           m_items.emplace_back(tmp);
       }
       else if(dirEntry.is_symlink()){
           cout<<"Link"<<endl;
       }
       // std::cout << dirEntry << std::endl;

    }
    cout<<"-------------"<<endl;
}

void CDir::Copy(CItem *item) {

}

void CDir::Copy(std::vector<CItem *>) {

}

void CDir::Move(CItem *item, std::string dest) {

}

void CDir::Delete(std::vector<CItem *> items) {

}

void CDir::Delete(CItem *item) {

}

void CDir::Move(std::vector<CItem *>, std::string dest) {

}

unsigned int CDir::GetSize() {
    return 0;
}

void CDir::SetDate(u_int year, u_int month, u_int day) {

}

void CDir::Deduplicate() {

}

void CDir::Print() {
    cout<<"/"<<m_Name<<endl;
    for (int i = 0; i < m_items.size() ; ++i) {
        m_items[i]->Print();
    }
}
