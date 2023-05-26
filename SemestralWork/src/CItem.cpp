
#include "CItem.h"
#include "filesystem"
namespace fs = std::filesystem;

CItem::CItem(std::string path, unsigned int size):m_Path(path) {
    m_Name=fs::path(m_Path).filename();
    m_Size=size;
    m_Path=path;

}


