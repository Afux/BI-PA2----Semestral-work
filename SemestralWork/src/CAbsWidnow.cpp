

#include "CAbsWidnow.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "regex"
#include <fstream>
void CAbsWidnow::clear() {
    system("clear");
}

void CAbsWidnow::moveto(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";

}

CAbsWidnow::CAbsWidnow(CSize size, unsigned int Selected, std::string Name, CAbsWidnow* Scene): m_Size(size),m_Selected(Selected),m_Name(Name),m_Scene(Scene){}

void CAbsWidnow::Copy(CItem *item, std::string to) {
    item->Copy(to);
}

void CAbsWidnow::Copy(std::string reg,std::string to,std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    std::map<std::string ,std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()){
        CItem* item=Items->begin()->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if(regex_match( it->second->m_Name,r)&&it->second.get()!=item){
                items[it->second->m_Path]=it->second;
            }
        }

        item->Copy(items,to);
    }

}


void CAbsWidnow::Delete(CItem *item) {
    item->Delete();

}

void CAbsWidnow::Delete(std::string reg,std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    std::map<std::string ,std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()) {
        CItem* item=Items->begin()->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if(regex_match( it->second->m_Name,r)&&it->second.get()!=item){
                items[it->second->m_Path]=it->second;
            }
        }

        item->Delete(items);
        if(iter!=Items->begin())
            iter--;
    }
}

void CAbsWidnow::Move(CItem *item, std::string dest) {
    item->Move(dest);

}

void CAbsWidnow::Move(std::string reg, std::string dest,std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    std::map<std::string ,std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()) {
        CItem* item=Items->begin()->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if(regex_match( it->second->m_Name,r)&&it->second.get()!=item){
                items[it->second->m_Path]=it->second;
            }
        }
        item->Move(items, dest);
        if(iter!=Items->begin())
            iter--;
    }
    else{
    }
}

void CAbsWidnow::Refresh() {
        clear();
        Print();

}


void CAbsWidnow::CreateFolder(std::string name, std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        itr++;

        CItem *item = itr->second->m_inFolder;
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(item->m_Path+"/"+name, 22, item, item));
        Items->insert({ tmp->m_Path, tmp });
        // Items->emplace_back(tmp);

    }
}

void CAbsWidnow::CreateFile(std::string name, std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        itr++;
        CItem *item = itr->second->m_inFolder;
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(item->m_Path+"/"+name, 22, item));
        Items->insert({ tmp->m_Path, tmp });
    }
}

void CAbsWidnow::CreateLink(std::string name, CItem *to, std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        itr++;
        CItem *item = itr->second->m_inFolder;
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(item->m_Path+"/"+name, 22,to, item));
        Items->insert({ tmp->m_Path, tmp });
    }
}

CAbsWidnow::~CAbsWidnow() {

}

void CAbsWidnow::FindByText(std::string text, std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        itr++;
        CItem *item = itr->second->m_inFolder;
        vector<CItem*> found;
        item->FindText(text,&found);

        ofstream MyFile("/home/afu/PA1/df/TESTER/filename.txt");

        for (int i = 0; i <found.size() ; ++i) {
            MyFile<<found[i]->m_Path<<endl;
        }

        // Close the file
        MyFile.close();
    }
}

void CAbsWidnow::Deduplicate(CItem *item, std::map<std::string ,std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        itr++;

        CItem *parent = itr->second->m_inFolder;
        parent->Deduplicate(item);

    }
}

void CAbsWidnow::ConcatFiles(std::map<std::string ,std::shared_ptr<CItem>> *Items, string to) {
    if(Items->size()>1) {
        auto itr=Items->begin();
        itr++;
        CItem *item =itr->second->m_inFolder;
        for (auto it = Items->begin(); it !=Items->end() ; ++it) {
            if (it->second->m_isSelected)
               it->second->ConCat(item->m_Path + "/" + to);
        }

    }
}

