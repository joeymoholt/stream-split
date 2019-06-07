#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

class Frame 
{
    public:
        virtual int parse (ifstream &file) = 0;
        virtual vector<unsigned char> getStream(int pid) = 0;
        virtual ~Frame() = default;
};

#endif