#ifndef RESOLUTIONPHANTOMDETECTOR_H
#define RESOLUTIONPHANTOMDETECTOR_H

#include "phantomdetector.h"
#include "detector_defines.h"
class DETECTOR_DLLEXPORT ResolutionPhantomDetector : public PhantomDetector {
public:
    ResolutionPhantomDetector();
    virtual bool isType(Uint8* pixelData, size_t numpixels);
};

#endif // RESOLUTIONPHANTOMDETECTOR_H
