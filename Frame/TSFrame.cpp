#include "TSFrame.hpp"

using namespace std;

int TSFrame::parse (ifstream &file)
{
    uint pid = 0;
    uint flags = 0;
    uint hdrLen = 0;
    uint payloadStart = 0;
    unsigned char buffer[188];

    if (file.is_open())
    {
        while (file.peek() != EOF)
        {
            if (file.peek() == 0x47)
            {
                file.read((char*)buffer, 188);
                pid = to_int((char*)&buffer[1]) & 0x1FFF;
                flags = buffer[3];
                hdrLen = buffer[4];

                if ((flags & 0x30) != 0x20)
                {
                    if (pid != 0x0)
                    {
                        if (flags & 0x20)
                        {
                            payloadStart = 1 + hdrLen + 4;
                        }
                        else
                        {
                            payloadStart = 4;
                        }

                        streamMap[pid].insert(streamMap[pid].end(), &buffer[payloadStart], &buffer[188]);
                    }
                }
            }
            else{
                file.ignore(1);
            }
        }
    }

    return 1;
}

vector<unsigned char> TSFrame::getStream(int pid)
{
    return streamMap[pid];
}
