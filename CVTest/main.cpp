//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/objdetect.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
#include "Camera.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

//
///** Global variables */
//String resources = "..\\resources\\";
//String face_cascade_name = resources +"haarcascades\\haarcascade_frontalface_alt.xml";
//String eyes_cascade_name = resources +"haarcascades\\haarcascade_eye_tree_eyeglasses.xml";
//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
//string window_name = "Capture - Face detection";
//RNG rng(12345);
//
//
//
//void splitRGBA(Mat& image,Mat& rgb, Mat& mask) {
//
//	cvtColor(image, rgb, COLOR_RGBA2RGB);
//
//	vector<Mat> channels(4);
//	split(image, channels);
//	threshold(channels[3], mask, 1, 255, 0);
//
//}
//
//
///** @function detectAndDisplay */
//void detectAndDisplay(Mat& frame )
//{
//	std::vector<Rect> faces;
//	Mat frame_gray;
//
//	cvtColor(frame, frame_gray, CV_BGR2GRAY);
//	equalizeHist(frame_gray, frame_gray);
//
//	//-- Detect faces
//	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
//	int num_faces = faces.size();
//	if (num_faces > 1) num_faces = 1;
//	for (size_t i = 0; i < num_faces; i++)
//	{
//		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
//		ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
//
//		Mat faceROI = frame_gray(faces[i]);
//		std::vector<Rect> eyes;
//
//		//-- In each face, detect eyes
//		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
//		int numEyes = eyes.size();
//		if (numEyes > 2) numEyes = 2;
//
//		for (size_t j = 0; j < numEyes; j++)
//		{
//			Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
//			int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
//			circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
//		}
//	}
//}
//
//
//
//
int main() {
//	if (!stream1.isOpened()) { //check if video device has been initialised
//		cout << "cannot open camera";
//	}


//	Mat image,rgb,alphaMask;
//	image = imread(resources +"filters\\filter_1.png", IMREAD_UNCHANGED);
//	resize(image, image, Size(50, 50));
//	splitRGBA(image, rgb, alphaMask);

//	system("pause");

	loadOverlays();
	setDimensions(640, 480);


	//INIT-CLOSE CAMERA
	openCamera();

	int filter_id = 0;

	while (true) {
		Mat cameraFrame;
		drawImage(cameraFrame, filter_id);
		imshow("cam", cameraFrame);
		int key = waitKey(30);
		if (key == 'q') break;

		if (key != 255) printf("key: %d\n", key);
		if (key == 'w') filter_id = (filter_id + 1) % 3;
		if (key == 's') filter_id = (filter_id + 2) % 3;

		if (key == 'u') { scalers[filter_id][0] -= 0.1;  printf("s: %f , %f \n", scalers[filter_id][0],scalers[filter_id][1]); };
		if (key == 'i') {scalers[filter_id][0] -= 0.01;  printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};
		if (key == 'o') {scalers[filter_id][0] += 0.01;  printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};
		if (key == 'p') {scalers[filter_id][0] += 0.1;   printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};

		if (key == 'h') {scalers[filter_id][1] -= 0.1;  printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};
		if (key == 'j') {scalers[filter_id][1] -= 0.01; printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};
		if (key == 'k') {scalers[filter_id][1] += 0.01; printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};
		if (key == 'l') {scalers[filter_id][1] += 0.1;  printf("s: %f , %f \n", scalers[filter_id][0], scalers[filter_id][1]);};


//		if (stream1.read(cameraFrame)) {
//			detectAndDisplay(cameraFrame);
//
//			rgb.copyTo(cameraFrame(Rect(100, 170, 50, 50)), alphaMask);
//			
//			//flip(cameraFrame, cameraFrame, 0);
//
//		}
	}
//	destroyWindow("cam");
//	stream1.release();
//	//while (true);
	releaseCamera();
	return 0;
}