#include <iostream>

#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"

#include "phantomdetector.h"

using namespace std;

int testPhantomType(string file,DetectorType type)
{
    string in_file = "../data/" + file;
    DcmFileFormat file_format;
    OFCondition status = file_format.loadFile(in_file.c_str());

    if (status.bad()) {
        string in_file1 = "../../data/" + file;
        OFCondition status = file_format.loadFile(in_file1.c_str());
        if (status.bad()) {

            string in_file2 = "data/" + file;
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
                    PhantomDetector* detector = PhantomDetector::getDetector(type);
                    if (detector->isType(pixelData, numPixels)) {
                        cout << file << " Passed ! Phatom detection is correct" << endl;
                    } else {
                        cout << file << " Failed ! Phatom detection is Incorrect" << endl;
                    }
                }
            }
        } else
            cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
    }
    delete image;
	return 0;
}

int main(int argc, const char* argv[])
{
    testPhantomType("G.dcm", GeometryPhantom);
    testPhantomType("U.dcm", UniformityPhantom);
    testPhantomType("R.dcm", ResolutionPhantom);

    return 0;
}