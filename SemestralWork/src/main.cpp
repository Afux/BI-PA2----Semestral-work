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

     CManager man(CSize(100,30,1,1,30),"/home/afu/PA1/df");
     man.Run();
   // CDir uf("/home/afu/PA1",2,NULL);

    return 0;
}