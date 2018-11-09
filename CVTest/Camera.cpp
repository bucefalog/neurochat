
#include "Camera.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <algorithm>
#include <windows.h>

using namespace std;
using namespace cv;

int centers[3][2] = { {-20,200},{30,-40},{20,-80} };
float scalers[3][2] = { {1.5,1},{.7,.55},{1,.6} };

namespace {

	//FILES
	String cascadePath = "C:\\resources\\haarcascades\\";
	String face_cascade_name = cascadePath + "haarcascade_frontalface_alt.xml";
	String eyes_cascade_name = cascadePath + "haarcascade_eye_tree_eyeglasses.xml";
	//String cascadePath = "D:\\opencv\\build\\share\\OpenCV\\haarcascades\\";


	//CAMERA
	cv::VideoCapture *webcam = 0;
	Mat originalFrame;				//frame to store current original image
	int width=640, height=480;		//size of image (user defined)

	//CLASSIFIERS
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;


	//OVERLAYS
	#define NUM_FILTERS 3
	Mat overlays[NUM_FILTERS], masks[NUM_FILTERS];
	


	//ERROR INFO
	bool loadedResourcePath = false;

	//SHARED MEMORY
	#define SHARED_MEM_SIZE 4

	//FACE DETECTED
	Rect facePosition(-1, -1, -1, -1);

}


//LOAD FUNCTIONS
void splitRGBA(Mat& image, Mat& rgb, Mat& mask) {

	cvtColor(image, rgb, COLOR_RGBA2RGB);

	std::vector<Mat> channels(4);
	split(image, channels);
	threshold(channels[3], mask, 1, 255, 0);

}

bool loadOverlays() {


	if (!face_cascade.load(face_cascade_name)) {
		return false;
	}
	if (!eyes_cascade.load(eyes_cascade_name)) {
		return false;
	};

	//std::string filterFile = "C:\\filters\\filter_";
	std::string filterFile = "C:\\resources\\filters\\filter_";
	for (int i = 0; i < NUM_FILTERS; i++) {

		std::string file = filterFile + std::to_string(i) + ".png";
		Mat image = imread(file, IMREAD_UNCHANGED);
		resize(image, image, Size(200, 100));
		splitRGBA(image, overlays[i], masks[i]);

	}

	return true;

}

void setDimensions(int w, int h) {
	width = w;
	height = h < 0 ? -h : h;
}




// OPEN CLOSE CAMERA
void openCamera() {
	webcam = new VideoCapture(2);
}

void releaseCamera() {
	webcam->release();
	delete webcam;
	destroyWindow("webcam");
}



//CAMERA OPERATIONS
void newFrame() {
	Mat f;
	webcam->read(f);
	resize(f, originalFrame, Size(width, height));
}

void getFrameCopy(Mat &img) {
	originalFrame.copyTo(img);
}



//SHARED MEMORY FUNCTIONS


int getFilterID() {
	int filterId = -1;

	//open shared memory
	HANDLE hMapFile = hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,   // read/write access
		FALSE,                 // do not inherit the name
		TEXT("bciSharedMem"));               // name of mapping object

	//check if success
	if (hMapFile != NULL)
	{

		//map file
		LPCTSTR pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
			FILE_MAP_ALL_ACCESS,  // read/write permission
			0,
			0,
			SHARED_MEM_SIZE);

		//check if success
		if (pBuf != NULL)
		{
			//read memory
			CopyMemory(&filterId, (PVOID)pBuf, sizeof(int));

			//unmap file
			UnmapViewOfFile(pBuf);

		}
		//close file
		CloseHandle(hMapFile);
	}

	//return filter id read, -1 otherwise
	return filterId;
}




//FACE DETECTION
void getFacePosition(Rect &f) {
	f = facePosition;
}

void setFacePosition(Rect &f) {
	facePosition = f;
}

void findFace() {

	//GET CURRENT FRAME TO BE PROCESSED
	Mat cameraFrame;
	getFrameCopy(cameraFrame); 


	Mat frame_gray;
	cvtColor(cameraFrame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));


	//SET DETECTION

	//setFacePosition(faces.size() == 0 ? Rect(-1, -1, -1, 1) : faces[0]);
	facePosition = faces.size() == 0 ? Rect(-1, -1, -1, 1) : faces[0];

}



void overlayImage(cv::Mat &background, cv::Mat &foreground, cv::Mat &mask, cv::Mat &output, Rect location)
{
	//int x0, xf, y0, yf;
	int x = max(location.x,0);
	int y = max(location.y,0);
	int w = min(background.cols, location.x + foreground.cols) - x;
	int h = min(background.rows, location.y + foreground.rows) - y;

	if ( h<= 0 || w <=0) return;

	Rect backgroundRect(x, y, w, h);
	Rect foregroundRect(max(0, -location.x), max(0, -location.y), w,h);

	foreground(foregroundRect).copyTo(background(backgroundRect), mask(foregroundRect));



	//background.copyTo(output);
	//// start at the row indicated by location, or at row 0 if location.y is negative.
	//for (int y = std::max(location.y, 0); y < background.rows; ++y)
	//{
	//	int fY = y - location.y; // because of the translation
	//							 // we are done of we have processed all rows of the foreground image.
	//	if (fY >= foreground.rows) break;
	//	// start at the column indicated by location, 
	//	// or at column 0 if location.x is negative.
	//	for (int x = std::max(location.x, 0); x < background.cols; ++x)
	//	{
	//		int fX = x - location.x; // because of the translation. we are done with this row if the column is outside of the foreground image.
	//		if (fX >= foreground.cols)
	//			break;
	//		// determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
	//		double opacity = ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3]) / 255.;

	//		// and now combine the background and foreground pixel, using the opacity,  but only if opacity > 0.
	//		for (int c = 0; opacity > 0 && c < output.channels(); ++c)
	//		{
	//			unsigned char foregroundPx = foreground.data[fY * foreground.step + fX * foreground.channels() + c];
	//			unsigned char backgroundPx = background.data[y * background.step + x * background.channels() + c];
	//			output.data[y*output.step + output.channels()*x + c] = backgroundPx * (1. - opacity) + foregroundPx * opacity;
	//		}
	//	}
	//}


}


void applyOverlay(Mat &dst, int filterID) {

	if (filterID == -1) {
		putText(dst, "Cant read filterID", cvPoint(15, 75), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200, 200, 250), 1, CV_AA);
		return;
	}

	//Get postion of face detection
	Rect facePosition;
	getFacePosition(facePosition);

	if (facePosition.width == -1) {
		putText(dst, "Face not detected", cvPoint(50, 100),FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(200, 200, 250), 1, CV_AA);
	}
	else {

		//Get image to overlay
		Mat overlay = overlays[filterID];
		Mat mask = masks[filterID];


		Point center(facePosition.x + facePosition.width*0.5, facePosition.y + facePosition.height*0.5);
		ellipse(dst, center, Size(facePosition.width*0.5, facePosition.height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

		Mat imageCopy;
		Mat resizedMask;
		resize(overlay, imageCopy, Size(facePosition.width*scalers[filterID][0], facePosition.height*scalers[filterID][1]));
		resize(mask, resizedMask, Size(facePosition.width*scalers[filterID][0], facePosition.height*scalers[filterID][1]));
		facePosition.x += centers[filterID][0];
		facePosition.y += centers[filterID][1];
		overlayImage(dst, imageCopy, resizedMask, dst, facePosition);

	}

}









void drawImage(Mat &img,int filter_id) {

	newFrame();
	findFace();  //maybe move this to a separate thread

	//Mat cameraFrame;
	getFrameCopy(img);

	applyOverlay(img, filter_id);



	//flip(img, img, -1);



}
