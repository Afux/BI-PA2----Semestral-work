
#include "CLink.h"
#include "filesystem"
namespace fs = std::filesystem;
using namespace std;

CLink::CLink(std::string path, unsigned int size,CItem* toFile,CItem *parr) : CItem(path, size,parr),m_toFile(toFile) {

    if(toFile!=NULL){

        if(IsReadable(toFile->m_Path)&& IsWriteable(toFile->m_Path)&&!fs::exists(path)) {
            if(fs::is_directory(toFile->m_Path))
                fs::create_directory_symlink(toFile->m_Path,path);
            else
                fs::create_symlink(toFile->m_Path,path);

        }
    }
}


void CLink::Print() {
    cout<<"*"<<m_Name;
}


void CLink::Copy(std::string to) {
    if(fs::exists(to)){
        if(IsReadable(to)&& IsWriteable(to))
            fs::copy_symlink(m_Path,to+"/"+m_Name);
    }
}

void CLink::Delete() {
    if(fs::exists(m_Path)) {
        if (IsReadable(m_Path) && IsWriteable(m_Path)){
            std::filesystem::remove_all(m_Path);
            if(m_inFolder!=NULL){
                m_inFolder->m_items.erase(m_Path);
            }
        }
    }


}



void CLink::Move(string dest) {
    Copy(dest);
    Delete();
}



void CLink::UpdateSize() {
    //m_Size=m_toFile->m_Size;
}

void CLink::SetDate(u_int year, u_int month, u_int day) {

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

std::shared_ptr<CItem> CLink::clone() const {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(*this));
    return tmp;
}

void CLink::Open(std::map<std::string ,std::shared_ptr<CItem>> **item, CItem **inFold) {
    if(m_toFile!=NULL){
      //  m_toFile->Open(item,inFold);
    }
}

void CLink::FindText(std::string FindThis,std::vector<CItem*> *Found){
    if(m_toFile!=NULL){
        m_toFile->FindText(FindThis,Found);
    }
}

void CLink::Deduplicate(CItem *DeduplicateMe) {}

void CLink::ConCat(std::string To) {
   if(m_toFile!=NULL){
       m_toFile->ConCat(To);
   }
}

