#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main()
{
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];

    const char imgName[] ="../images/lena512.bmp";
    const char newImgName[] ="8lena_binary.bmp";

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

     myImage->binarizeImage(imgInBuffer, imgOutBuffer, _512by512_IMG_SIZE, 125);
     myImage->writeImage();
     
     cout<<"8. Binary Change Success !"<<endl;

    return 0;
}
