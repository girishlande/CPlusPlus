#include <iostream>

#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"

using namespace std;

void DetectPixels(Uint8* pixelData, size_t numpixels)
{
    if (pixelData != NULL) {
        size_t white_cnt = 0;
        size_t black_cnt = 0;
        for (size_t i = 0; i < numpixels; i++) {
            if ((int)pixelData[i] > 245) {
                white_cnt++;
            } else if ((int)pixelData[i] < 10) {
                black_cnt++;
            }
        }
        cout << "White pixels:" << white_cnt << endl;
        cout << "Black pixels:" << black_cnt << endl;
    }
}

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

    DcmDataset* dataset = file_format.getDataset();

    OFString patient_name;

    OFCondition condition;
    condition = dataset->findAndGetOFStringArray(DCM_PatientName, patient_name);

    if (condition.good()) {
        cout << "Patient name is: " << patient_name << endl;
    } else {
        cerr << "Could not get patient name" << endl;
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
                    DetectPixels(pixelData, numPixels);
                }
            }
        } else
            cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
    }
    delete image;

    cout << "Program finish." << endl;

    return 0;
}