
#include "CItem.h"
#include "filesystem"
namespace fs = std::filesystem;

CItem::CItem(std::string path, unsigned int size,CItem *inFolder):m_Path(path),m_inFolder(inFolder) {
    m_Name=fs::path(m_Path).filename();
    m_isSelected= false;
   // m_Path=path;
   // std::filesystem::file_time_type ftime = std::filesystem::last_write_time(path);
  //  std::cout<<time_point_cast(ftime)<<std::endl
}

CItem::~CItem() {

}

void CItem::Select() {
    if(m_isSelected)
        m_isSelected= false;
    else
        m_isSelected= true;
}

bool CItem::IsReadable(const fs::path &p) {

    try {

        auto perms = fs::status(p).permissions();
        if ((perms & fs::perms::owner_read) != fs::perms::none && (perms & fs::perms::group_read) != fs::perms::none&&(fs::exists(p)))
        {
            return true;
        }
        return false;
    }
    catch (fs::filesystem_error &e){
        return false;
    }

}

bool CItem::IsWriteable(const std::filesystem::path &p) {
    try {

        auto perms = fs::status(p).permissions();
        if ((perms & fs::perms::owner_write) != fs::perms::none && (perms & fs::perms::group_write) != fs::perms::none&&(fs::exists(p)))
        {
            return true;
        }
        return false;

    }
        catch (fs::filesystem_error &e){
            return false;
        }
}





