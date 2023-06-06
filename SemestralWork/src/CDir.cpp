
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include "set"
#include "filesystem"
#include "iostream"
using directory_iterator = std::filesystem::directory_iterator;
namespace fs = std::filesystem;
using namespace std;

//Vyjimka?.
CDir::CDir( std::string path, unsigned int size,CItem* inFolder) : CItem(path, size,inFolder) {
    m_DeleteMe=NULL;
    if(IsReadable(path)&&fs::exists(path)) {

        for (const auto &dirEntry: filesystem::directory_iterator(m_Path,std::filesystem::directory_options::skip_permission_denied)) {
            string s = dirEntry.path();
            if(IsReadable(s)){
                if (dirEntry.is_symlink()) {
                    if(m_items.count(fs::read_symlink(dirEntry))){
                        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, m_items.at(fs::read_symlink(dirEntry)).get(), this));
                        tmp->UpdateSize();
                        m_items[tmp->m_Path]=tmp;
                    }
                    else{
                        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, NULL, this));
                        tmp->UpdateSize();
                        m_items[tmp->m_Path]=tmp;
                    }

                } else if (dirEntry.is_directory()) {

                    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(s, 22, this));
                    tmp->UpdateSize();
                    m_items[tmp->m_Path]=tmp;

                } else if (dirEntry.is_regular_file()) {

                    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(CFile(s, 2, this)));
                    tmp->UpdateSize();
                    m_items[tmp->m_Path]=tmp;

                }
            }
        }
    }

    else{
        try{
            if(IsReadable(fs::path(path).parent_path())&&IsWriteable(fs::path(path).parent_path()))
            fs::create_directory(path);
        }
        catch (const fs::filesystem_error &e){
              throw logic_error(e.code().message());
        }

    }
}



void CDir::Copy(std::string to) {
   if(IsReadable(to)&& IsWriteable(to)&&fs::exists(to)&&!fs::equivalent(m_Path,to)&&!fs::is_other(m_Path)&&!fs::is_other(to)&&!fs::exists(to+"/"+m_Name)){

       try{
           fs::create_directory(to+"/"+m_Name);
           fs::copy(m_Path, to+"/"+m_Name, std::filesystem::copy_options::recursive);
       }
       catch (const fs::filesystem_error &e){
           throw logic_error(e.code().message());

       }
   }

}

void CDir::Move(std::string dest) {
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
       fs::remove_all(dest);
       throw logic_error(e.what());
   }
}

void CDir::Delete() {

    if (IsReadable(m_Path) && IsWriteable(m_Path)){
       try{
           fs::remove_all(m_Path);
       }
       catch (const fs::filesystem_error &e){
           throw logic_error(e.code().message());
       }
       if (m_inFolder != NULL) {
            if (m_inFolder->m_items.count(m_Path))
                m_inFolder->m_items.erase(m_Path);
       }
    }
    else{
        throw  logic_error("Cant delete directory");
    }

}

void CDir::UpdateSize() {
    m_Size=0;
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        m_Size+=it->second->m_Size;
    }

}

void CDir::SetDate(u_int year, u_int month, u_int day) {}

void CDir::Print() {
    cout<<"/"<<m_Name;

}

std::string CDir::RemoveDialog() {
    return "Dir "+m_Name+" will be removed";
}

std::string CDir::CreateDialog(std::string NewName) {
    return "Dir "+m_Name+" will be created";
}

std::string CDir::RenameDialog(std::string NewName) {
    return "Dir "+m_Name+" will be renamed to "+ NewName;
}

void CDir::Open(std::map<std::string ,std::shared_ptr<CItem>> **items,CItem ** inFold) {

    Refresh();
    *items= &m_items;
    if(m_inFolder!=NULL){
        *inFold=m_inFolder;
    }
    else{
        *inFold=NULL;
    }

}

std::vector<std::string> CDir::parseString(const string &input, char delimiter) {
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = input.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(input.substr(start, end - start));
        start = end + 1;
        end = input.find(delimiter, start);
    }


    tokens.push_back(input.substr(start));

    return tokens;
}
std::map<std::string ,std::shared_ptr<CItem>> *CDir::FindDir(const string &path,CItem **item) {
    vector<string > tempPaths= parseString(path,'/');
    std::map<std::string ,std::shared_ptr<CItem>> *curr=&this->m_items;
    for (auto it = curr->begin(); it != curr->end(); ++it) {

        for (size_t j = 0; j < tempPaths.size(); ++j) {

            if(it->second->m_Name==tempPaths[j]){
                it->second->Open(&curr,item);
                tempPaths.erase(tempPaths.begin());
                it=curr->begin();
                break;
            }
        }
    }

    return curr;
}

std::shared_ptr<CItem> CDir::clone() const {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(*this));
    return tmp;
}

CDir::CDir(const CDir &rhs): CItem(rhs.m_Path, rhs.m_Size,rhs.m_inFolder) {}

void CDir::FindText(std::string FindThis,std::vector<CItem*> *Found) {
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        it->second->FindText(FindThis,Found);
    }
}

void CDir::Deduplicate(CItem *DeduplicateMe) {

    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        if(it->second.get()!=DeduplicateMe)
            it->second->Deduplicate(DeduplicateMe);
    }
    Refresh();

}

//Mb Delete
void CDir::ConCat(std::string To) {}

void CDir::Refresh() {
    std::set<string > tmp;
    for (const auto &dirEntry: filesystem::directory_iterator(m_Path,
                                                              std::filesystem::directory_options::skip_permission_denied)) {
        string s = dirEntry.path();
        tmp.insert(s);
        if(IsReadable(s)&& !m_items.count(s)){
            if (dirEntry.is_symlink()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, this, this));
                m_items[tmp->m_Path]=tmp;

            } else if (dirEntry.is_directory()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(s, 22, this));
                m_items[tmp->m_Path]=tmp;

            } else if (dirEntry.is_regular_file()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(CFile(s, 2, this)));
                m_items[tmp->m_Path]=tmp;

            }
        }
    }

    for(auto it=m_items.begin();it!=m_items.end();it++){
        it->second->m_isSelected=false;
        if(!tmp.count(it->first)|| !IsReadable(it->first)){
            m_items.erase(it->first);
        }

    }
}