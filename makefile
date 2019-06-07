CXX = g++
CXXFLAGS = -std=c++11 -Wall -g 

SRCS = main.cpp Frame/FrameFactory.cpp Frame/TSFrame.cpp Packet/PacketFactory.cpp Packet/PESPacket.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = Frame/Frame.hpp Frame/FrameFactory.hpp Frame/TSFrame.hpp Packet/Packet.hpp Packet/PacketFactory.hpp Packet/PESPacket.hpp

MAIN = stream_split

all: ${MAIN}

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *. *~.
