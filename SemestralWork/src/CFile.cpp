
#include "CFile.h"
#include "filesystem"
#include <fstream>
namespace fs = std::filesystem;

CFile::CFile(std::string path, unsigned int size,CItem *parr) : CItem(path, size,parr) {
    if(!fs::exists(path)) {
        std::ofstream { path };
    }
}

void CFile::Print() {
    cout<<m_Name;

}

void CFile::Copy(string to) {
    std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);
}

void CFile::Copy(std::vector< std::shared_ptr<CItem>> items, string to) {}

void CFile::Delete() {
    std::filesystem::remove_all(m_Path);

}

void CFile::Delete(std::vector< std::shared_ptr<CItem>> items) {}

void CFile::Move(string dest) {
    Copy(dest);
    Delete();
}

void CFile::Move(std::vector< std::shared_ptr<CItem>> items, string dest) {}

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

void CFile::Open(std::vector< std::shared_ptr<CItem>> **item,CItem ** inFold) {
  /*
    if(m_inFolder!=NULL){
       *inFold=m_inFolder;
    }
    else{
        *inFold=NULL;
    }
    */
}

std::shared_ptr<CItem> CFile::clone() const {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(*this));
    return tmp;
}

void CFile:: FindText(std::string FindThis,std::vector<CItem*> *Found) {
    ifstream inFile;
    inFile.open(m_Path);
    string temp;
    size_t pos;
    if(inFile){
        while(inFile.good())
        {
            getline(inFile,temp);
            pos=temp.find(FindThis);
            if(pos!=string::npos)
            {
                Found->push_back(this);
                break;
            }
        }
    }
}


