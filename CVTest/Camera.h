#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

extern int centers[3][2];
extern float scalers[3][2];

//LOAD FUNCTIONS
bool loadOverlays();
void setDimensions(int w, int h);


//INIT-CLOSE CAMERA
void openCamera();
void releaseCamera();

void drawImage(cv::Mat &img,int filter_id);