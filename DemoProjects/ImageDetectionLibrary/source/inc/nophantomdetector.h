#ifndef NOPHANTOMDETECTOR_H
#define NOPHANTOMDETECTOR_H

#include "phantomdetector.h"
#include "detector_defines.h"
class DETECTOR_DLLEXPORT NoPhantomDetector : public PhantomDetector {
public:
    NoPhantomDetector();
    virtual bool isType(Uint8* pixelData, size_t numpixels);
};

#endif // NOPHANTOMDETECTOR_H
