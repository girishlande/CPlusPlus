#include "nophantomdetector.h"

NoPhantomDetector::NoPhantomDetector()
{

}


bool NoPhantomDetector::isType(Uint8* pixelData, size_t numpixels)
{
    size_t blackPixelCount;
    size_t whitePixelCount;
    getBlackWhitePixelCount(pixelData, numpixels, blackPixelCount, whitePixelCount);
    return (whitePixelCount < 100);
}
