#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main()
{
    float imgHiSt[NO_OF_GRAYLEVELS];

    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];

    const char imgName[] ="../images/girlface.bmp";
    const char newImgName[] ="girlface_neg.bmp";

    ImageProcessing *myImage  = new ImageProcessing(imgName,
                                                    newImgName,
                                                    &imgHeight,
                                                    &imgWidth,
                                                    &imgBitDepth,
                                                    &imgHeader[0],
                                                    &imgColorTable[0],
                                                    &imgInBuffer[0],
                                                    &imgOutBuffer[0]
                                                    );

     myImage->readImage();
     myImage->getImageNegative(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);

     myImage->writeImage();

     cout<<"6. Image negative creation Success !"<<endl;

    return 0;
}
