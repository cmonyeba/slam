#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d.hpp"
#include "frame.hpp"
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int, char* argv[])
{
    // cout << argv[1];
    VideoCapture cap(argv[1]); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

   
    namedWindow("viewer", 1);
    for(;;)
    {
        Mat frame; //initialize frame matrix
        Mat grayFrame; //initialize gray frame matrix 
        vector<Point> corners; //vector of point types

        // struct keyFrame f1;

        cap >> frame; // get a new frame from camera
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY); //Convert frame to gray-scale
        resize(frame, frame,Size(),0.50,0.50); //resize frame
        resize(grayFrame, grayFrame,Size(),0.50,0.50); //resize frame

        
        detectFeatures(frame, grayFrame, corners); //detect corners and annotates frame
        
        keyFrame f {frame, corners}; //aggregate initialization of keyframe
       

        imshow("viewer", f.capture);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}