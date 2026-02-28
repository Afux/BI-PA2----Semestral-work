#include <filesystem>
#include "CManager.h"
#include <functional>
#include "fstream"
int main() {

    unsigned int Width=110;
    unsigned int Height=60;
    std::string Path="";

    std::ifstream file("My_config.txt");
    if (file.good()) {
        std::string line;
        while (std::getline(file, line)) {

            size_t equeals = line.find('=');
            if (equeals != std::string::npos) {
                std::string what = line.substr(0, equeals);
                std::string val = line.substr(equeals + 1);
                if (what == "path") {
                    Path=val;
                }
                else if (what == "width") {
                   Width=std::stoul(val);
                }
                else if (what == "height") {
                    Height=std::stoul(val);
                }
            }
        }
        file.close();
    }
    else{
        std::cout << "Cant open a file" << std::endl;
        return 0;
    }
    try{
        std::cout << Width << ";" << Height << ";" << Path<< std::endl;
         CManager man(CSize(Width, Height, 1, 1, Height), Path);
        man.Run();
    }
    catch (...){
        std::cout << "Bad config" << std::endl;
        return 0;
    }
    return 0;
}