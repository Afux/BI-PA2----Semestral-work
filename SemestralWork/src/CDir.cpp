
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"

#include "filesystem"
using directory_iterator = std::filesystem::directory_iterator;
namespace fs = std::filesystem;
using namespace std;

CDir::CDir( std::string path, unsigned int size,CItem* Parr,CItem* inFolder) : CItem(path, size,inFolder),m_parr(Parr) {

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
    if(Parr!=NULL){

        m_items.emplace_back(m_parr);
        m_currItems.emplace_back(m_parr);
    }
    else{
        m_items.emplace_back(this);
        m_currItems.emplace_back(this);
    }
    if(fs::exists(path)) {
        for (const auto &dirEntry: filesystem::directory_iterator(m_Path,
                                                                  std::filesystem::directory_options::skip_permission_denied)) {
            //  cout<<dirEntry.path()<<endl;
            if (dirEntry.is_symlink()) {
                string s = dirEntry.path();
                CLink *temp = new CLink(CLink(s, 2, this, this));
                temp->UpdateSize();
                CItem *tmp = temp;
                m_items.emplace_back(tmp);
                m_currItems.emplace_back(tmp);

            } else if (dirEntry.is_directory()) {
                string s = dirEntry.path();
                CDir *temp = new CDir(CDir(s, 22, this, this));
                temp->UpdateSize();
                CItem *tmp = temp;

                m_items.emplace_back(tmp);

                m_currItems.emplace_back(tmp);

            } else if (dirEntry.is_regular_file()) {
                string s = dirEntry.path();
                CFile *temp = new CFile(CFile(s, 2, this));
                temp->UpdateSize();
                CItem *tmp = temp;
                m_items.emplace_back(tmp);
                m_currItems.emplace_back(tmp);


            }

            // std::cout << dirEntry << std::endl;

        }
    }
    else{
         fs::create_directory(path);
        //vector<CItem*> *temp= FindDir(m_parr->m_Path);
       // temp->push_back(this);
    }
    //cout<<"-------------"<<endl;
}


void CDir::Copy(std::vector<CItem*> items, std::string to) {
    for (auto & item : items) {
        item->Copy(to);
    }
}

void CDir::Copy(std::string to) {
    vector<CItem*> *temp= FindDir(to);
    std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);
    temp->emplace_back(this);
}

void CDir::Move(std::string dest) {
    Copy(dest);
    Delete();
}

void CDir::Delete(std::vector<CItem *> items) {
    for (auto & item : items) {
         item->Delete();
    }

}

void CDir::Delete() {
    vector<CItem*> *temp= FindDir(m_parr->m_Path);
    fs::remove_all(m_Path);
    if(m_parr!=NULL){
        for (size_t i = 0; i < temp->size(); ++i) {
            if( temp->at(i)== this){
                temp->erase( temp->begin()+i);
            }
        }
    }
}

void CDir::Move(std::vector<CItem *> items, std::string dest) {
    for (auto & item : items) {
        item->Move(dest);

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



std::vector<CItem *> *CDir::FindDir(const string &path) {
    vector<string > tempPaths= parseString(path,'/');
    std::vector<CItem*>*curr=&this->m_items;

    for (size_t i = 0; i < curr->size(); ++i) {
        for (size_t j = 0; j < tempPaths.size(); ++j) {

            if(curr->at(i)->m_Name==tempPaths[j]){

                curr->at(i)->Open(&curr);
                tempPaths.erase(tempPaths.begin());
                i=0;
                break;
            }
        }
    }
    return curr;
}

CItem *CDir::Clone() {
    CItem *tmp = ( new CDir(*this));
    return tmp;
}




