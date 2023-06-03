
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"

#include "filesystem"
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

            if (dirEntry.is_symlink()) {

                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(s, 22, this, this));
                m_items.emplace_back(tmp);
                m_currItems.emplace_back(tmp);

            } else if (dirEntry.is_directory()) {
             /*
                CDir *temp = new CDir(CDir(s, 22, this, this));
                temp->UpdateSize();
                CItem *tmp = temp;
                */
                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(s, 22, this, this));
                m_items.emplace_back(tmp);

                m_currItems.emplace_back(tmp);

            } else if (dirEntry.is_regular_file()) {
                /*
                CFile *temp = new CFile(CFile(s, 2, this));
                temp->UpdateSize();
                CItem *tmp = temp;
                */
                shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(CFile(s, 2, this)));
                m_items.emplace_back(tmp);
                m_currItems.emplace_back(tmp);


            }

            // std::cout << dirEntry << std::endl;

        }
    }
    else{
         fs::create_directory(path);
        //std::vector< std::shared_ptr<CItem>> *temp= FindDir(m_parr->m_Path);
       // temp->push_back(this);
    }
    //cout<<"-------------"<<endl;
}


void CDir::Copy(std::vector< std::shared_ptr<CItem>> items, std::string to) {
    for (auto & item : items) {
        item->Copy(to);
    }
}

void CDir::Copy(std::string to) {
   // std::vector< std::shared_ptr<CItem>> *temp= FindDir(to,&m_DeleteMe);
    std::filesystem::copy(m_Path, to, std::filesystem::copy_options::recursive);
   // temp->emplace_back(this);
}

void CDir::Move(std::string dest) {
    Copy(dest);
    Delete();
}

void CDir::Delete(std::vector< std::shared_ptr<CItem>> items) {
    for (auto & item : items) {
         item->Delete();
    }

}

void CDir::Delete() {
   // std::vector< std::shared_ptr<CItem>> *temp= FindDir(m_parr->m_Path,&m_DeleteMe);
    fs::remove_all(m_Path);
    /*
    if(m_parr!=NULL){
        for (size_t i = 0; i < temp->size(); ++i) {
            if( temp->at(i).get()== this){
                temp->erase( temp->begin()+i);
            }
        }
    }
     */
}

void CDir::Move(std::vector< std::shared_ptr<CItem>> items, std::string dest) {
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

void CDir::Open(std::vector<std::shared_ptr<CItem>> **items,CItem ** inFold) {
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



std::vector< std::shared_ptr<CItem>> *CDir::FindDir(const string &path,CItem **item) {
    vector<string > tempPaths= parseString(path,'/');
    std::vector< std::shared_ptr<CItem>> *curr=&this->m_items;
    for (size_t i = 0; i < curr->size(); ++i) {
        for (size_t j = 0; j < tempPaths.size(); ++j) {

            if(curr->at(i)->m_Name==tempPaths[j]){
                curr->at(i)->Open(&curr,item);
                tempPaths.erase(tempPaths.begin());
                i=0;
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
    for (int i = 0; i < m_items.size() ; ++i) {
        m_items[i]->FindText(FindThis,Found);
    }
}

void CDir::Deduplicate(CItem *DeduplicateMe) {
    for (int i = 0; i < m_items.size() ; ++i) {
        if(m_items[i].get()!=DeduplicateMe)
            m_items[i]->Deduplicate(DeduplicateMe);
    }
}






