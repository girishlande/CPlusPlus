#include "phantomdetector.h"
#include "geometryphantomdetector.h"
#include "resolutionphantomdetector.h"
#include "uniformityphantomdetector.h"
#include "nophantomdetector.h"

PhantomDetector::PhantomDetector()
{

}

PhantomDetector *PhantomDetector::getDetector(DetectorType type)
{
    switch (type) {
    case GeometryPhantom: return new GeometryPhantomDetector();
    case ResolutionPhantom: return new ResolutionPhantomDetector();
    case UniformityPhantom: return new UniformityPhantomDetector();
    case NoPhantom: return new NoPhantomDetector();
    }
    return nullptr;
}

PhantomDetector::~PhantomDetector()
{

}


void PhantomDetector::getBlackWhitePixelCount(Uint8* pixelData,
    size_t numPixels, size_t& blackPixelCount, size_t& whitePixelCount)
{
    blackPixelCount = 0;
    whitePixelCount = 0;
    if (pixelData != NULL) {
        for (size_t i = 0; i < numPixels; i++) {
            if ((int)pixelData[i] > 245) {
                whitePixelCount++;
            } else if ((int)pixelData[i] < 10) {
                blackPixelCount++;
            }
        }
    }
}