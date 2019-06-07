#include "Frame.hpp"
#include "TSFrame.hpp"
#include <string>

using namespace std;

class FrameFactory {
    public:
        static Frame* create(string type);
};
