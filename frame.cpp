#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d.hpp"

using namespace cv;
using namespace std;

void detectFeatures(Mat &frame , Mat &grayFrame, vector<Point> &corners)
{   
    //parameters for circle
    int radius = 1;
    const int color = 255;
    int thickness = 1;
    int lineType = LINE_8;
    int shift = 0;

    goodFeaturesToTrack(grayFrame, corners, 2500, 0.01, 10);

    for (size_t idx=0; idx < corners.size(); idx++ )
    {
        circle(frame, corners.at(idx), radius, color, thickness, lineType, shift);
    }       
}