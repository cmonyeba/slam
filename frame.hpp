#include "frame.cpp"

using namespace cv;
using namespace std;

void detectFeatures(Mat &frame , Mat &grayFrame, vector<Point> &corners);

struct keyFrame
{
    /* data */
    Mat capture;
    vector<Point> kps;
};

