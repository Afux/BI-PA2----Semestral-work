
#include "CFile.h"
#include "filesystem"
#include <fstream>
#include "CLink.h"
namespace fs = std::filesystem;
using namespace std;

CFile::CFile(std::string path, unsigned int size,CItem *parr) : CItem(path, size,parr) {
    if(!fs::exists(path)) {
      if(IsReadable(m_inFolder->m_Path)&& IsWriteable(m_inFolder->m_Path))
        std::ofstream { path };
      else{
          throw logic_error("Bad Perms");
      }
    }

}

void CFile::Print() {
    cout<<m_Name;

}

void CFile::Copy(string to) {
    if(fs::exists(to)&&!fs::equivalent(m_Path,to)&&!fs::is_other(m_Path)&&!fs::is_other(to)){
        if(IsReadable(to)&& IsWriteable(to))
            std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);
        else{
            throw  logic_error("Bad perms");
        }
    }
    else{
        throw logic_error("Cannot Copy, check dest. directory");
    }
}

//Delete mb
void CFile::Copy(std::map<std::string ,std::shared_ptr<CItem>> items, string to) {}

void CFile::Delete() {
    if(fs::exists(m_Path)) {
        if (IsReadable(m_Path) && IsWriteable(m_Path)){
            try{
                fs::remove_all(m_Path);
            }
            catch (const fs::filesystem_error &e){
                throw logic_error(e.code().message());
            }
            if(m_inFolder!=NULL){
                m_inFolder->m_items.erase(m_Path);
            }
        }
        else{
            throw  logic_error("Bad perms");
        }
    }
    else{
        throw logic_error("Cannot delete, file doesnt exist");
    }

}

//Delete mb
void CFile::Delete(std::map<std::string ,std::shared_ptr<CItem>> items) {}

void CFile::Move(string dest) {
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
        throw logic_error(e.what());
    }
}

//Delete mb
void CFile::Move(std::map<std::string ,std::shared_ptr<CItem>> items, string dest) {}

void CFile::UpdateSize() {
    m_Size=filesystem::file_size(m_Path);
}

void CFile::SetDate(u_int year, u_int month, u_int day) {}

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

void CFile::Open(std::map<std::string ,std::shared_ptr<CItem>> **item,CItem ** inFold) {}

std::shared_ptr<CItem> CFile::clone() const {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(*this));
    return tmp;
}

void CFile:: FindText(std::string FindThis,std::vector<CItem*> *Found) {

    ifstream inFile(m_Path, ios::in);
    if (inFile.good()) {


       // inFile.open(m_Path);
        string temp;
        size_t pos;

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

void CFile::Deduplicate(CItem *DeduplicateMe) {
    if(identicalFiles(m_Path,DeduplicateMe->m_Path)){

       //TryCatch
        if(fs::exists(m_Path)) {
            if (IsReadable(m_Path) && IsWriteable(m_Path)){
                std::filesystem::remove_all(m_Path);
            }
        }
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(m_Path, 22, DeduplicateMe, m_inFolder));
        m_inFolder->m_items[m_Path]=tmp;

    }
}

bool CFile::identicalFiles(string file1, string file2) {
    bool flag = false;
    ifstream stream1(file1, ios::in | ios::binary);
    ifstream stream2(file2, ios::in | ios::binary);
    if (!stream1.good()) {
        return false;
    }
    if (!stream2.good()) {
        return false;
    }
    stream1.seekg(0, ios::end);
    stream2.seekg(0, ios::end);
    long int file_size1 = stream1.tellg();
    long int file_size2 = stream2.tellg();
    if (file_size1 != file_size2) {
        stream1.close();
        if (!stream1.good()) {
            return false;
        }
        stream2.close();
        if (!stream2.good()) {
            return false;
        }
        return false;
    }


    for (int i = 0; i < file_size1; i++) {
        stream1.seekg(i);
        unsigned char x;
        stream1.read((char *) &x, 1);
        stream2.seekg(i);
        unsigned char y;
        stream2.read((char *) &y, 1);
        if (x != y) {
            flag = true;
            break;
        }


    }

    stream1.close();
    if (!stream1.good()) {

        return false;
    }
    stream2.close();
    if (!stream2.good()) {
        return false;
    }
    if (!flag)
        return true;
    else
        return false;
}

void CFile::ConCat(std::string To) {
    ifstream stream1(m_Path, ios::in);
    fstream stream2(To, ios::out|ios::app);
    string temp;
    if(stream1.good()&&stream2.good()){
        while(getline(stream1, temp)){
            stream2<<temp;
            stream2<<endl;
        }
    }

    m_isSelected= false;
}


