
#include "CLink.h"
#include "CFile.h"
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
    try{
        fs::copy_symlink(m_Path,to+"/"+m_Name);
    }
    catch (const fs::filesystem_error &e){
        throw logic_error(e.code().message());
    }

}

void CLink::Delete() {
    try{
        fs::remove_all(m_Path);
    }
    catch (const fs::filesystem_error &e){
        throw logic_error(e.code().message());
    }
    if(m_inFolder!=NULL&&m_inFolder->m_items.count(m_Path)){
        m_inFolder->m_items.erase(m_Path);
    }
}



void CLink::Move(string dest) {
    try{
        Copy(dest);
    }
    catch (const logic_error &e){
        throw logic_error(e.what());
    }
    try {
        Delete();
    }
    catch (const logic_error &e){
        fs::remove_all(dest+"/"+m_Name);
        throw logic_error(e.what());
    }
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



void CLink::Open(std::map<std::string ,std::shared_ptr<CItem>> **item, CItem **inFold) {
    if(m_toFile!=NULL){
       // m_toFile->Open(item,inFold);
    }
}

void CLink::FindText(std::string FindThis,std::vector<CItem*> *Found){
    if(m_toFile!=NULL){
        //m_toFile->FindText(FindThis,Found);
    }
}

void CLink::Deduplicate(CItem *DeduplicateMe) {}

void CLink::ConCat(std::string To) {
   if(m_toFile!=NULL){
     //  m_toFile->ConCat(To);
   }
}

