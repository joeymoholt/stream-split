#include "PacketFactory.hpp"

Packet* PacketFactory::create(string type)
{
    if (type.compare("pes") == 0)
    {
        return new PESPacket();
    }
    else
    {
        return NULL;
    }
}
