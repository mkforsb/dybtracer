#ifndef HAVE_STLREADER_H
#define HAVE_STLREADER_H

#include "mesh.hpp"

class STLReader
{
public:
    STLReader();
    ~STLReader();
    Mesh* loadStl(string filename);
};

#endif
