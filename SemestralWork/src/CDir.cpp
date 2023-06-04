
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include "set"
#include "filesystem"
#include "iostream"
using directory_iterator = std::filesystem::directory_iterator;
namespace fs = std::filesystem;
using namespace std;

CDir::CDir( std::string path, unsigned int size,CItem* Parr,CItem* inFolder) : CItem(path, size,inFolder),m_parr(Parr) {
    m_DeleteMe=NULL;
    try {
        fs::path filePath(m_Path);
        fs::file_status fileStatus = fs::status(filePath);
        if (fs::status_known(fileStatus)) {

        }
        else {
           
        }

    }
    catch (const fs::filesystem_error& e) {
        cout<<"D"<<endl;
    }
/*
    if(Parr!=NULL){
       // shared_ptr<CItem> tmp = shared_ptr<CItem>(m_parr);

       // shared_ptr<CItem> tmp = shared_ptr<CItem>( new CItem(m_parr));
              //  auto tmp=m_parr->clone();



        m_items.emplace_back(m_parr->clone());
        m_currItems.emplace_back(m_parr->clone());

    }

    else{
      //  auto tmp= this->clone();
       // auto sd=make_shared<CDir*>(this);

      // shared_ptr<CItem> p2(this);
        m_items.emplace_back(std::make_shared<CDir>(*this));
        m_currItems.emplace_back(this->clone());
    }
*/
    if(fs::exists(path)) {
        for (const auto &dirEntry: filesystem::directory_iterator(m_Path,
                                                                  std::filesystem::directory_options::skip_permission_denied)) {
            string s = dirEntry.path();
            std::filesystem::file_time_type ftime = std::filesystem::last_write_time(s);




            if (dirEntry.is_symlink()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, this, this));
                tmp->UpdateSize();
                m_items[tmp->m_Path]=tmp;


            } else if (dirEntry.is_directory()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(s, 22, this, this));
                tmp->UpdateSize();
                m_items[tmp->m_Path]=tmp;




            } else if (dirEntry.is_regular_file()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(CFile(s, 2, this)));
                tmp->UpdateSize();
                m_items[tmp->m_Path]=tmp;



            }


        }
    }
    else{
         fs::create_directory(path);

    }
}


void CDir::Copy(std::map<std::string ,std::shared_ptr<CItem>> items, std::string to) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        it->second->Copy(to);
    }

}

void CDir::Copy(std::string to) {
    std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);
}

void CDir::Move(std::string dest) {
    Copy(dest);
    Delete();
}

void CDir::Delete(std::map<std::string ,std::shared_ptr<CItem>> items) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        it->second->Delete();
    }

}

void CDir::Delete() {
    fs::remove_all(m_Path);
    if(m_inFolder!=NULL){
        if(m_inFolder->m_items.count(m_Path))
             m_inFolder->m_items.erase(m_Path);
    }
}

void CDir::Move(std::map<std::string ,std::shared_ptr<CItem>> items, std::string dest) {

    for (auto it = items.begin(); it != items.end(); ++it) {
        it->second->Move(dest);
    }

}

void CDir::UpdateSize() {
    m_Size=0;
    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        m_Size+=it->second->m_Size;
    }

}

void CDir::SetDate(u_int year, u_int month, u_int day) {

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

void CDir::Open(std::map<std::string ,std::shared_ptr<CItem>> **items,CItem ** inFold) {
   /*
    if(m_parr== NULL){

       fs::path filePath(m_Path);
       CDir *temp = new CDir(CDir(filePath.parent_path(), 22, NULL, NULL));
       temp->UpdateSize();
       CItem *tmp = temp;
       m_parr= tmp;
       m_items[0]=m_parr;


   }
    */
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

CDir::CDir(const CDir &rhs): CItem(rhs.m_Path, rhs.m_Size,rhs.m_inFolder) {

}

void CDir::FindText(std::string FindThis,std::vector<CItem*> *Found) {

    for (auto & item : m_items) {
        item.second->FindText(FindThis,Found);
    }

}

void CDir::Deduplicate(CItem *DeduplicateMe) {

    for (auto it = m_items.begin(); it != m_items.end(); ++it) {
        if(it->second.get()!=DeduplicateMe)
            it->second->Deduplicate(DeduplicateMe);
    }

}

void CDir::ConCat(std::string To) {

}

void CDir::Refresh() {
    std::set<string > tmp;
    for (const auto &dirEntry: filesystem::directory_iterator(m_Path,
                                                              std::filesystem::directory_options::skip_permission_denied)) {
        string s = dirEntry.path();
        tmp.insert(s);
        if(!m_items.count(s)){
            if (dirEntry.is_symlink()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, this, this));
                m_items[tmp->m_Path]=tmp;

            } else if (dirEntry.is_directory()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(s, 22, this, this));
                m_items[tmp->m_Path]=tmp;

            } else if (dirEntry.is_regular_file()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(CFile(s, 2, this)));
                m_items[tmp->m_Path]=tmp;

            }
        }
    }
    for(auto it=m_items.begin();it!=m_items.end();it++){
        if(!tmp.count(it->first)){
            m_items.erase(it->first);
        }

    }
}






