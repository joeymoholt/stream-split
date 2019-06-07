#include "Packet.hpp"
#include "PESPacket.hpp"
#include <string>

using namespace std;

class PacketFactory {
    public:
        static Packet* create(string type);
};
