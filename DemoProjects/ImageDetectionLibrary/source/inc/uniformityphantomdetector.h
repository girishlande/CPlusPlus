#ifndef UNIFORMITYPHANTOMDETECTOR_H
#define UNIFORMITYPHANTOMDETECTOR_H

#include "phantomdetector.h"
#include "detector_defines.h"
class DETECTOR_DLLEXPORT UniformityPhantomDetector : public PhantomDetector {
public:
    UniformityPhantomDetector();
    virtual bool isType(Uint8* pixelData, size_t numpixels);
};

#endif // UNIFORMITYPHANTOMDETECTOR_H
