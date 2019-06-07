# stream-split

Program designed to take in a TS stream and output audio and video in separate files. 

Input frame currently supported:
MPEG-TS

Input packet currently supported:
PES

Design:
The design is largely based around the Factory Pattern.  This would allow for the Frame or Packet to change without having to rearchitect the driver. 

Things I'd add if this were production:
- Robust error handling
- No numbers in code, ex. use FRAME_SIZE instead of 188
- Comments, much more comments
- Refactor the PESParser.cpp file.  There's duplicate code for video and audio that can be merged in some way.
