
#ifndef SEMESTRALWORK_CSIZE_H
#define SEMESTRALWORK_CSIZE_H


class CSize {
public:
    CSize( unsigned int Width,  unsigned int Height,   int PosX,   int PosY);
    void SetHeight(const unsigned int &val);
    void SetWidth(const unsigned int &val);
    unsigned int GetHeight() const;
    unsigned intGetWidth() const;
    unsigned int m_Width;
    unsigned int m_Height;
    int  m_PosX;
    int m_PosY;
};


#endif //SEMESTRALWORK_CSIZE_H
