#include <string>
#include <iostream>
#include <filesystem>
#include "CManager.h"
#include "termios.h"
#include "vector"
#include "CDir.h"
#include <functional>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using directory_iterator = std::filesystem::recursive_directory_iterator;






int main() {
    /*
    CWindow win(CSize(100,30,1,1),0,"WIND");
    win.TESTING.push_back("/CZ");
    win.TESTING.push_back("/DFS");
    win.TESTING.push_back("dsdsds-e");
    win.TESTING.push_back("ddd");
    win.TESTING.push_back("gggg");

    win.ReadKey();
     */
     //
     //
    //cout<<sd->size()<<endl;
    //uf.m_items
    /*
  CDir uf("/home/afu/PA1",2,NULL,NULL);
   cout<< uf.IsReadable("/home/afu/PA1/df/TESTER")<<endl;
    for (auto it = uf.m_items.begin(); it !=uf.m_items.end() ; ++it) {
        cout<<it->second->m_Name<<endl;
    }

    cout<<"------"<<endl;
    for (auto i = uf.m_items.begin(); i !=uf.m_items.end() ; ++i) {
        cout<<i->second->m_Path<<endl;
    }
    CDir se("/home/afu/PA1/df/TESTER/DEL",2,NULL,NULL);
    cout<<se.m_Path<<endl;
     */
   CManager man(CSize(100,30,1,1),"MAN",0);
    man.Run();

/*

      std::map<std::string ,std::shared_ptr<CItem>>   *m_Items;
      m_Items=uf.FindDir("/home/afu/PA1/df");
      for (int i = 0; i < m_Items->size() ; ++i) {
         m_Items->at(i)->Print();
         cout<<endl;
      }
      */
  // uf.Print();
    /*
         for (const auto& dirEntry : filesystem::recursive_directory_iterator ("/home/afu/PA1/df")){
           std::cout << dirEntry << std::endl;
           //string s=dirEntry.path();
       }

       cout<<"Hello"<<endl;
      moveto(1,5);
      system("clear");
      // std::cout << std::flush;

      moveto(100,5);
      cout<<"HEHE"<<endl;
    for (const auto& dirEntry : filesystem::directory_iterator ("/home/afu/PA1/PT2"))
          std::cout << dirEntry << std::endl;

       moveto(1,30);
   */


    return 0;
}