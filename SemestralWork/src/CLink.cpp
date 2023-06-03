
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


void CLink::Print() {
    cout<<"*"<<m_Name;
}

void CLink::Copy(std::vector< std::shared_ptr<CItem>> items, std::string to) {

}

void CLink::Copy(std::string to) {
    fs::copy_symlink(m_Path,to+"/"+m_Name);
}

void CLink::Delete() {
    fs::remove_all(m_Path);

}

void CLink::Delete(std::vector< std::shared_ptr<CItem>> items) {

}

void CLink::Move(string dest) {
    Copy(dest);
    Delete();
}

void CLink::Move(std::vector< std::shared_ptr<CItem>> items, string dest) {

}

void CLink::UpdateSize() {

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

void CLink::Open(std::vector<std::shared_ptr<CItem>> **item, CItem **inFold) {
    /*
    if(m_inFolder!=NULL){
        *inFold=m_inFolder;
    }
    else{
        *inFold=NULL;
    }
     */
}

void CLink::FindText(std::string FindThis,std::vector<CItem*> *Found){
    m_toFile->FindText(FindThis,Found);
}

void CLink::Deduplicate(CItem *DeduplicateMe) {

}

