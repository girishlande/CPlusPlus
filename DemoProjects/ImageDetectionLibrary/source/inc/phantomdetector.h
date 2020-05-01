#ifndef PHANTOMDETECTOR_H
#define PHANTOMDETECTOR_H

#include <stdint.h>

enum DetectorType {
    GeometryPhantom,
    UniformityPhantom,
    ResolutionPhantom,
    NoPhantom
};

typedef uint8_t Uint8;

#include "detector_defines.h"
class DETECTOR_DLLEXPORT PhantomDetector {
public:
    PhantomDetector();

    virtual bool isType(Uint8* pixelData, size_t numpixels) = 0;
    static PhantomDetector* getDetector(DetectorType);

    virtual ~PhantomDetector();

protected:
    void getBlackWhitePixelCount(Uint8* pixelData,size_t numPixels, size_t& blackPixelCount, size_t& whitePixelCount);
};

#endif // PHANTOMDETECTOR_H
