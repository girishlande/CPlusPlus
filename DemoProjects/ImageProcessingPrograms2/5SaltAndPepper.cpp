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
    const char newImgName[] ="lena_gauss_saltpepper.bmp";

    ImageProcessing *myImage  = new ImageProcessing(imgName,
                                                    newImgName,
                                                    &imgHeight,
                                                    &imgWidth,
                                                    &imgBitDepth,
                                                    &imgHeader[0],
                                                    &imgColorTable[0],
                                                    &imgInBuffer[0],
                                                    &imgInBuffer[0]   // Note : The result is put back into the input buffer
                                                    );



     myImage->readImage();
     myImage->saltAndPepper(imgInBuffer,imgWidth,imgHeight,0.1);
     myImage->writeImage();


     cout<<"5. Salt and Paper Success !"<<endl;

    return 0;
}
