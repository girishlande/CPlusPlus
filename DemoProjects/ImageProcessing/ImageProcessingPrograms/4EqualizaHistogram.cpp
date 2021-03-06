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

    const char imgName[] ="../images/lena512.bmp";
    const char newImgName[] ="4lena_histogramequalized.bmp";

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
     myImage->equalizeHistogram(imgInBuffer,imgOutBuffer,imgHeight,imgWidth);
     myImage->writeImage();

     cout<<"4. Histogram equalization Success !"<<endl;
 
    return 0;
}
