
#include "CItem.h"
#include "filesystem"
namespace fs = std::filesystem;

CItem::CItem(std::string path, unsigned int size,CItem *inFolder):m_Path(path),m_inFolder(inFolder) {
    m_Name=fs::path(m_Path).filename();
    m_Size=size;
   // m_Path=path;
   // std::filesystem::file_time_type ftime = std::filesystem::last_write_time(path);
  //  std::cout<<time_point_cast(ftime)<<std::endl
}


