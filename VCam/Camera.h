#pragma once

#include <olectl.h>



//LOAD FUNCTIONS
bool loadOverlays();
void setDimensions(int w, int h);


//INIT-CLOSE CAMERA
void openCamera();
void releaseCamera();

void drawImage(BYTE *pData, long length);