//
// Created by afu on 05.06.23.
//

#include "CManagerOPs.h"
#include "CSize.h"
#include "CItem.h"
#include "CDir.h"
#include "CFile.h"
#include "CLink.h"
#include "filesystem"
#include "regex"
#include "fstream"
using namespace std;
namespace fs = std::filesystem;
void CManagerOPs::Copy(CItem *item, const std::string &to) {
    if(fs::exists(to))
        item->Copy(to);

}

void CManagerOPs::Copy(const std::string &reg, const std::string &to,std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    std::map<std::string ,std::shared_ptr<CItem>> items;
    std::regex r(reg);
    if(!Items->empty()){
        CItem* item=Items->begin()->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if(regex_match( it->second->m_Name,r)&&it->second.get()!=item){
                items[it->second->m_Path]=it->second;
            }
        }
        for (auto i = items.begin(); i != items.end() ; ++i) {
            i->second->Copy(to);

        }
    }
}


void CManagerOPs::Delete(CItem *item) {
        item->Delete();
}

void CManagerOPs::Delete(std::string reg,std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    std::map<std::string ,std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()) {
        CItem* item=Items->begin()->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if(regex_match( it->second->m_Name,r)&&it->second.get()!=item){
                items[it->second->m_Path]=it->second;
            }
        }
        for (auto i = items.begin(); i != items.end() ; ++i) {
            i->second->Delete();
        }

    }
}

void CManagerOPs::Move(CItem *item, std::string dest) {
    item->Move(dest);

}

void CManagerOPs::Move(std::string reg, std::string dest,std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    std::map<std::string ,std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()) {
        CItem* item=Items->begin()->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if(regex_match( it->second->m_Name,r)&&it->second.get()!=item){
                items[it->second->m_Path]=it->second;
            }
        }
        for (auto i = items.begin(); i != items.end() ; ++i) {
            i->second->Move(dest);
        }

    }
    else{
    }
}


void CManagerOPs::CreateFolder(std::string name, CItem *CurrDir) {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(CurrDir->m_Path+"/"+name, 22, CurrDir));
    CurrDir->m_items.insert({ tmp->m_Path, tmp });
}

void CManagerOPs::CreateFile(std::string name, CItem *CurrDir) {

    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(CurrDir->m_Path+"/"+name, 22, CurrDir));
    CurrDir->m_items.insert({ tmp->m_Path, tmp });

}

void CManagerOPs::CreateLink(std::string name, CItem *to, CItem *CurrDir) {
    shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(CurrDir->m_Path+"/"+name, 22,to, CurrDir));
    CurrDir->m_items.insert({ tmp->m_Path, tmp });
}



void CManagerOPs::FindByText(const std::string &text, std::map<std::string ,std::shared_ptr<CItem>> *Items) {

    if(!Items->empty()) {
        auto itr=Items->begin();
        CItem *item = itr->second->m_inFolder;
        vector<CItem*> found;
        if(item!=NULL){
            item->FindText(text,&found);
            ofstream MyFile("/home/afu/PA1/df/TESTER/filename.txt");

            for (size_t i = 0; i <found.size() ; ++i) {
                MyFile<<found[i]->m_Path<<endl;
            }

            MyFile.close();
        }
    }
    else
        throw logic_error("Dir is empty");
}

void CManagerOPs::Deduplicate(CItem *item, std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    if(!Items->empty()) {
        auto itr=Items->begin();
        CItem *parent = itr->second->m_inFolder;
        parent->Deduplicate(item);
    }
    else
        throw logic_error("Nothing to deduplicate");
}

void CManagerOPs::ConcatFiles(std::map<std::string ,std::shared_ptr<CItem>> *Items, string to) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        CItem *item =itr->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
                it->second->ConCat(item->m_Path + "/" + to);
        }

    }
    else
        throw logic_error("Choose at least 2 files");
}