

#include "CAbsWidnow.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include "regex"
void CAbsWidnow::clear() {
    system("clear");
    //std::cout << "\033[3J";

}

void CAbsWidnow::moveto(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";

}

CAbsWidnow::CAbsWidnow(CSize size, unsigned int Selected, std::string Name, CAbsWidnow* Scene): m_Size(size),m_Selected(Selected),m_Name(Name),m_Scene(Scene){}

void CAbsWidnow::Copy(CItem *item, std::string to) {
    item->Copy(to);
}

void CAbsWidnow::Copy(std::string reg,std::string to,std::vector< std::shared_ptr<CItem>> *Items) {
    std::vector< std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()){
        CItem* item=Items->at(0)->m_inFolder;

        for (auto & m_Item : *Items) {
            if(regex_match( m_Item->m_Name,r)&&m_Item.get()!=item){
                items.push_back(m_Item);
            }
        }
        item->Copy(items,to);
    }

}


void CAbsWidnow::Delete(CItem *item) {
    item->Delete();
}

void CAbsWidnow::Delete(std::string reg,std::vector< std::shared_ptr<CItem>> *Items) {
    std::vector< std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()) {
        CItem *item = Items->at(0)->m_inFolder;
        for (auto &m_Item: *Items) {
            if (regex_match(m_Item->m_Name, r) && m_Item.get() != item) {
                items.push_back(m_Item);
            }
        }
        item->Delete(items);
    }
}

void CAbsWidnow::Move(CItem *item, std::string dest) {
    item->Move(dest);

}

void CAbsWidnow::Move(std::string reg, std::string dest,std::vector< std::shared_ptr<CItem>> *Items) {
    std::vector< std::shared_ptr<CItem>> items;
    regex r(reg);
    if(!Items->empty()) {
        CItem *item = Items->at(0)->m_inFolder;
        for (size_t i = 0; i < Items->size() ; ++i) {
            if (regex_match(Items->at(i)->m_Name, r) && Items->at(i).get() != item) {
                items.push_back(Items->at(i));
                //Items->erase(Items->begin()+i);
            }
        }
        item->Move(items, dest);


    }
    else{
    }
}

void CAbsWidnow::Refresh() {
        clear();
        Print();

}


void CAbsWidnow::CreateFolder(std::string name, std::vector< std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {
        CItem *item = Items->at(1)->m_inFolder;
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CDir(item->m_Path+"/"+name, 22, item, item));
        Items->emplace_back(tmp);

    }
}

void CAbsWidnow::CreateFile(std::string name, std::vector< std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {

        CItem *item = Items->at(1)->m_inFolder;
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CFile(item->m_Path+"/"+name, 22, item));
        Items->emplace_back(tmp);
    }
}

void CAbsWidnow::CreateLink(std::string name, CItem *to, std::vector< std::shared_ptr<CItem>> *Items) {
    if(Items->size()>1) {

        CItem *item = Items->at(1)->m_inFolder;
        shared_ptr<CItem> tmp = shared_ptr<CItem>( new CLink(item->m_Path+"/"+name, 22,to, item));
        Items->emplace_back(tmp);
    }
}

CAbsWidnow::~CAbsWidnow() {

}

