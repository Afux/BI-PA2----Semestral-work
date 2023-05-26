#include <string>
#include <iostream>
#include <filesystem>
#include "CManager.h"
#include "termios.h"
#include "vector"
#include <functional>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using directory_iterator = std::filesystem::directory_iterator;






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
    CManager man(CSize(100,30,1,1),"MAN",0);
    man.Run();
    /*
   moveto(1,5);
   system("clear");
   // std::cout << std::flush;
   for (const auto& dirEntry : filesystem::directory_iterator ("/home/afu/PA1/genDATA")){
       std::cout << dirEntry << std::endl;
      string s=dirEntry.path();
   }
   moveto(100,5);
   cout<<"HEHE"<<endl;
 for (const auto& dirEntry : filesystem::directory_iterator ("/home/afu/PA1/PT2"))
       std::cout << dirEntry << std::endl;

    moveto(1,30);
*/



}