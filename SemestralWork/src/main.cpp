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
using namespace std;
namespace fs=filesystem;





int main() {
    /*

    win.ReadKey();
     */
     //
     //
    //cout<<sd->size()<<endl;
    //uf.m_items
    /*
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
     CManager man(CSize(100,30,1,1,30),"MAN",0);
    man.Run();
   // CDir uf("/home/afu/PA1",2,NULL);

  // cout<<fs::is_other("/home/afu/PA1/df/TESTER/Korytnik-FileManager.zip")<<endl;
   // cout<<fs::exists("/home/afu/PA1/df/TESTER/DelFold/genDATA")<<endl;



    return 0;
}