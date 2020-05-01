#include "resolutionphantomdetector.h"

ResolutionPhantomDetector::ResolutionPhantomDetector()
{

}


bool ResolutionPhantomDetector::isType(Uint8* pixelData, size_t numpixels)
{
    size_t blackPixelCount;
    size_t whitePixelCount;
    getBlackWhitePixelCount(pixelData, numpixels, blackPixelCount, whitePixelCount);
    return (blackPixelCount > 10000 && blackPixelCount < 20000);
}
