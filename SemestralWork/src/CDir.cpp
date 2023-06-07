
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include "set"
#include "filesystem"
#include "iostream"
using directory_iterator = std::filesystem::directory_iterator;
namespace fs = std::filesystem;
using namespace std;

CDir::CDir( std::string path, unsigned int size,CItem* inFolder) : CItem(path, size,inFolder) {
    if(IsReadable(fs::path(path).parent_path())&&IsWriteable(fs::path(path).parent_path())&&!fs::exists(path)) {
        try{
            fs::create_directory(path);
        }
        catch (const fs::filesystem_error &e){
            throw logic_error(e.code().message());
        }
    }
}

void CDir::Copy(std::string to) {

       try{
           if(IsWriteable(to))
              fs::create_directory(to+"/"+m_Name);
       }
       catch (const fs::filesystem_error &e){
           throw logic_error(e.code().message());
       }
       try{
           fs::copy(m_Path, to+"/"+m_Name, std::filesystem::copy_options::recursive);
       }
       catch (const fs::filesystem_error &e){
           fs::remove_all(to+"/"+m_Name);
           throw logic_error(e.code().message());

       }
}


void CDir::Delete() {
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
        fs::remove_all(dest+"/"+m_Name);
        throw logic_error(e.what());
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


void CDir::Open(std::map<std::string ,std::shared_ptr<CItem>> **items,CItem ** inFold) {
    FillItems();
    Refresh();
    *items= &m_items;
    *inFold= this;

}

std::shared_ptr<CItem> CDir::clone() const {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(*this));
    return tmp;
}

CDir::CDir(const CDir &rhs): CItem(rhs.m_Path, rhs.m_Size,rhs.m_inFolder) {}

void CDir::FindText(std::string FindThis,std::vector<CItem*> *Found) {
       if(m_items.empty()){
           FillItems();
       }
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        it->second->FindText(FindThis,Found);
    }
}

void CDir::Deduplicate(CItem *DeduplicateMe) {
    if(m_items.empty()){
        FillItems();
    }
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
    if(IsReadable(m_Path)&&fs::exists(m_Path)){
        for (const auto &dirEntry: filesystem::directory_iterator(m_Path,
                                                                  std::filesystem::directory_options::skip_permission_denied)) {
            string s = dirEntry.path();
            tmp.insert(s);
            if(IsReadable(s)&& !m_items.count(s)){
                if (dirEntry.is_symlink()) {

                    shared_ptr<CItem> temp = shared_ptr<CItem>( new CLink(s, 22, NULL, this));
                    m_items[temp->m_Path]=temp;

                } else if (dirEntry.is_directory()) {

                    shared_ptr<CItem> temp = shared_ptr<CItem>( new CDir(s, 22, this));
                    m_items[temp->m_Path]=temp;

                } else if (dirEntry.is_regular_file()) {

                    shared_ptr<CItem> temp = shared_ptr<CItem>( new CFile(CFile(s, 2, this)));
                    m_items[temp->m_Path]=temp;

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

}

void CDir::FillItems() {
    if(m_items.empty()&&IsReadable(m_Path)){
        for (const auto &dirEntry: filesystem::directory_iterator(m_Path,std::filesystem::directory_options::skip_permission_denied)) {
            string s = dirEntry.path();
            if(!m_items.count(s)){


                if(IsReadable(s)){
                    if (dirEntry.is_symlink()) {
                            shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, NULL, this));
                            tmp->UpdateSize();
                            m_items[tmp->m_Path]=tmp;

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
    }

}

std::string CDir::RenameDialog(std::string NewName) {
    return std::string();
}
