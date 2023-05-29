
#include "CDir.h"
#include "CFile.h"
#include "filesystem"
using directory_iterator = std::filesystem::directory_iterator;
namespace fs = std::filesystem;
using namespace std;

CDir::CDir( std::string path, unsigned int size,CDir* Parr) : CItem(path, size),m_parr(Parr) {

    if(Parr!=NULL){
        m_items.emplace_back(m_parr);
        m_currItems.emplace_back(m_parr);
    }
    else{
        m_items.emplace_back(this);
        m_currItems.emplace_back(this);
    }


    for (const auto& dirEntry : filesystem::directory_iterator (path)){
       if(dirEntry.is_directory()){
             string s=dirEntry.path();
             CDir * temp = new CDir( CDir(s,22, this));
             temp->UpdateSize();
             CItem *tmp= temp;

             m_items.emplace_back(tmp);

             m_currItems.emplace_back(tmp);

       }
       else if(dirEntry.is_regular_file()){
           string s=dirEntry.path();
           CFile * temp = new CFile( CFile(s,2));
           temp->UpdateSize();
           CItem *tmp= temp;
           m_items.emplace_back(tmp);
           m_currItems.emplace_back(tmp);

       }
       else if(dirEntry.is_symlink()){
          // cout<<"Link"<<endl;
       }
       // std::cout << dirEntry << std::endl;

    }
    //cout<<"-------------"<<endl;
}


void CDir::Copy(std::vector<CItem*> items, std::string to) {

    for (auto & item : items) {
        std::filesystem::copy(item->m_Path, to, std::filesystem::copy_options::recursive);

    }

}

void CDir::Copy(std::string to) {
    std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);

}

void CDir::Move(std::string dest) {
    std::filesystem::copy(m_Path, dest, std::filesystem::copy_options::recursive);
    Delete();
}

void CDir::Delete(std::vector<CItem *> items) {
    for (auto & item : items) {
        fs::remove_all(item->m_Path);

    }
}

void CDir::Delete() {
    fs::remove_all(m_Path);
}

void CDir::Move(std::vector<CItem *> items, std::string dest) {
    for (auto & item : items) {
        std::filesystem::copy(item->m_Path, dest, std::filesystem::copy_options::recursive);
        fs::remove_all(item->m_Path);

    }

}

void CDir::UpdateSize() {
    m_Size=0;
    for (size_t i = 0; i <m_items.size() ; ++i) {
        m_Size+=m_items[i]->m_Size;
    }
}

void CDir::SetDate(u_int year, u_int month, u_int day) {

}

void CDir::Deduplicate() {

}

void CDir::Print() {
    cout<<"/"<<m_Name;

}

std::string CDir::RemoveDialog() {
    return std::string();
}

std::string CDir::CreateDialog(std::string NewName) {
    return std::string();
}

std::string CDir::RenameDialog(std::string NewName) {
    return std::string();
}

void CDir::Open(std::vector<CItem*> **items) {
    *items= &m_items;
}
