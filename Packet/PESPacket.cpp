#include "PESPacket.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

void PESPacket::parse (ofstream &out, vector<unsigned char> stream)
{
    int count = 0;
    int syncLoc = 0;    
    int payloadSize = 0;

    while( count < stream.size())
    {
        payloadSize = 1;
        if (stream[count] == 0x0 && stream[count+1] == 0x0 && stream[count+2] == 0x01)
        {
            if (stream[count+3] == 0xC0)
            {
                payloadSize = to_int((char*)(&stream[count+4]));
                syncLoc = count;

                while(syncLoc < count + payloadSize)
                {
                    if (stream[syncLoc] == 0xFF && (stream[syncLoc+1] & 0xF0) == 0xF0)
                    {
                        break;
                    }

                    syncLoc++;
                }

                payloadSize = payloadSize - (syncLoc - count - 6);
                out.write((char *)(&stream[syncLoc]), payloadSize);
            }
            else if (stream[count+3] == 0xE0)
            {
                payloadSize = to_int((char*)(&stream[count+4]));

                if (payloadSize == 0)
                {
                    int next = count+4;

                    while (next < stream.size() - 3)
                    {
                        
                        if (stream[next] == 0x0 && stream[next+1] == 0x0 && stream[next+2] == 0x01 && stream[next+3] == 0xE0)
                        {
                            break;
                        }
                        next++;
                        
                    }
                    payloadSize = next-count;
                }
                
                syncLoc = count+6;

                while(syncLoc < count + payloadSize)
                {
                    if (stream[syncLoc] == 0x00 && stream[syncLoc+1] == 0x00 && stream[syncLoc+2])
                    {
                        break;
                    }

                    syncLoc++;
                }

                payloadSize = payloadSize - (syncLoc - count);

                out.write((char *)(&stream[syncLoc]), payloadSize);
            }   
        }
        
        count++;
    }
}