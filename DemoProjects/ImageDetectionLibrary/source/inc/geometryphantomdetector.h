#ifndef GEOMETRYPHANTOMDETECTOR_H
#define GEOMETRYPHANTOMDETECTOR_H

#include "phantomdetector.h"
#include "detector_defines.h"
class DETECTOR_DLLEXPORT GeometryPhantomDetector : public PhantomDetector {
public:
    GeometryPhantomDetector();
    virtual bool isType(Uint8* pixelData, size_t numpixels);
};

#endif // GEOMETRYPHANTOMDETECTOR_H
