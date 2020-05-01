#include "geometryphantomdetector.h"

GeometryPhantomDetector::GeometryPhantomDetector()
{

}

bool GeometryPhantomDetector::isType(Uint8* pixelData, size_t numpixels)
{
    size_t blackPixelCount;
    size_t whitePixelCount;
    getBlackWhitePixelCount(pixelData, numpixels, blackPixelCount, whitePixelCount);
    return (blackPixelCount < 2000);
}
