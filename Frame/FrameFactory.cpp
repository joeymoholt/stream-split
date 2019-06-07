#include "FrameFactory.hpp"

Frame* FrameFactory::create(string type)
{
    if (type.compare("ts") == 0)
    {
        return new TSFrame();
    }
    else
    {
        return NULL;
    }
}
