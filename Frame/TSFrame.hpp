#include "Frame.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>

class TSFrame : public Frame 
{
    public:
        int parse (ifstream &file);
        vector<unsigned char> getStream (int pid);
    private:
        inline uint to_int(const char* p)
        { uint n=((unsigned char*)p)[0]; n<<=8; n+=((unsigned char*)p)[1]; return n; }

        map<int, vector<unsigned char>> streamMap;

};