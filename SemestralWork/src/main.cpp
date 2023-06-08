#include <filesystem>
#include "CManager.h"
#include <functional>
int main() {

    CManager man(CSize(100, 30, 1, 1, 30), "/home/afu/PA1/df");
    man.Run();
    return 0;
}