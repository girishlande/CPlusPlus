#include <iostream>

#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include "lodepng.h"
#include <vector>

using namespace std;

void DisplayImageDetails(DicomImage* image)
{
    cout << "width:" << image->getWidth() << endl;
    cout << "Height:" << image->getHeight() << endl;
    cout << "depth:" << image->getDepth() << endl;
    cout << "Number of frames:" << image->getNumberOfFrames() << endl;
    cout << "Frame count:" << image->getFrameCount() << endl;
}

int main(int argc, const char* argv[])
{
    string in_file { "../data/G.dcm" };

    DcmFileFormat file_format;
    OFCondition status = file_format.loadFile(in_file.c_str());

    if (status.bad()) {
        string in_file1 { "../../data/G.dcm" };
        OFCondition status = file_format.loadFile(in_file1.c_str());
        if (status.bad()) {

            string in_file2 { "data/G.dcm" };
            OFCondition status = file_format.loadFile(in_file2.c_str());
            if (status.bad()) {
                cerr << "Problem openning file:" << in_file2 << endl;
                return 1;
            } else {
                in_file = in_file2;
            }
        } else {
            in_file = in_file1;
        }
    }

    DicomImage* image = new DicomImage(in_file.c_str());
    if (image != NULL) {
        if (image->getStatus() == EIS_Normal) {
            if (image->isMonochrome()) {
                image->setMinMaxWindow();
                Uint8* pixelData = (Uint8*)(image->getOutputData(8 /* bits */));
                if (pixelData) {
                    EP_Interpretation epi = image->getPhotometricInterpretation();
                    const DiPixel* dmp = image->getInterData();
                    size_t numPixels = dmp->getCount();
                    cout << "Pixels:" << dmp->getCount() << endl;
                    DisplayImageDetails(image);

                    std::vector<std::uint8_t> PngBuffer(dmp->getCount());
                    for (size_t i = 0; i < dmp->getCount();i++) {
                            PngBuffer[i] = pixelData[i]; 
                    }
                    std::vector<std::uint8_t> ImageBuffer;
                    lodepng::encode(ImageBuffer, PngBuffer, image->getWidth(), image->getHeight());
                    lodepng::save_file(ImageBuffer, "SomeImage.png");

                    //generate some image
                    if (false) {
                        unsigned width = 512, height = 512;
                        std::vector<unsigned char> PngBuffer;
                        PngBuffer.resize(width * height * 4);
                        for (unsigned y = 0; y < height; y++)
                            for (unsigned x = 0; x < width; x++) {
                                PngBuffer[4 * width * y + 4 * x + 0] = 255 * !(x & y);
                                PngBuffer[4 * width * y + 4 * x + 1] = x ^ y;
                                PngBuffer[4 * width * y + 4 * x + 2] = x | y;
                                PngBuffer[4 * width * y + 4 * x + 3] = 255;
                            }
                        std::vector<std::uint8_t> ImageBuffer;
                        lodepng::encode(ImageBuffer, PngBuffer, width, height);
                        lodepng::save_file(ImageBuffer, "SomeImage.png");
                    }

                    
                }
            }
        } else
            cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
    }
    delete image;

    cout << "Program finish." << endl;

    return 0;
}