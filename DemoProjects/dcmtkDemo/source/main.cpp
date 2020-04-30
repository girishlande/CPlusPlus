#include <iostream>

#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"

using namespace std;

int main(int argc, const char* argv[])
{
    string in_file {"../data/1.2.840.114561.100100.20200422.132008.1.1.1.dcm" };

    DcmFileFormat file_format;
    OFCondition status = file_format.loadFile(in_file.c_str());

    if (status.bad()) {
        string in_file1 { "../../data/1.2.840.114561.100100.20200422.132008.1.1.1.dcm" };
        OFCondition status = file_format.loadFile(in_file1.c_str());
        if (status.bad()) {
            cerr << "Problem openning file:" << in_file << endl;
            return 1;
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

    cout << "Program finish." << endl;

    return 0;
}