# stream-split

Program designed to take in a TS stream and output audio and video in separate files. 

Compile:
make all

Run: 
./stream_split <filename>
ex. ./stream_split elephants.ts

Input frame currently supported:
MPEG-TS

Input packet currently supported:
MPEG-PES

Design:
The design is largely based around the Factory Pattern.  This would allow for the Frame or Packet to change without having to rearchitect the driver. 

Things I'd add if this were production:
- Robust error handling
- No numbers in code, ex. use FRAME_SIZE instead of 188
- A automatic means of getting frame and packet type for the Factory create.  Move on from the strings ex. "ts".
- Comments, much more comments
- Refactor the PESParser.cpp file.  There's duplicate code for video and audio that can be merged in some way.
