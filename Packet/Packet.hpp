#ifndef PACKET_H
#define PACKET_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

class Packet 
{
    public:
        virtual void parse (ofstream &out, vector<unsigned char> stream) = 0;
        virtual ~Packet() = default;
};

#endif