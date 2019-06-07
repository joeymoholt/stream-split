#include "Frame/Frame.hpp"
#include "Frame/FrameFactory.hpp"
#include "Packet/Packet.hpp"
#include "Packet/PacketFactory.hpp"
#include <string>
#include <vector>

using namespace std;

int main ( int argc, char *argv[] )
{
    if ( argc != 2 )
    {
        cout<<"usage: "<< argv[0] <<" <filename>\n";
        return 1;
    }

    ifstream file (argv[1], ios::in|ios::binary|ios::ate);
    ofstream outVideo ("out.mp4", ios::out|ios::binary);
    ofstream outAudio ("out.aac", ios::out|ios::binary);

    if (file.is_open())
    {
        file.seekg (0, ios::beg);

        Frame * frame = FrameFactory::create("ts");
        frame->parse(file);
        Packet * packet = PacketFactory::create("pes");

        packet->parse(outVideo, frame->getStream(0x21));
        packet->parse(outAudio, frame->getStream(0x22));
    }

    file.close();
    outVideo.close();
    outAudio.close();
    
    return 0;
}