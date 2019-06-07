#include "Packet.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

class PESPacket : public Packet
{
    public:
        void parse (ofstream &out, vector<unsigned char> stream);
    private:
        inline uint to_int(const char* p)
        { uint n=((unsigned char*)p)[0]; n<<=8; n+=((unsigned char*)p)[1]; return n; }
};