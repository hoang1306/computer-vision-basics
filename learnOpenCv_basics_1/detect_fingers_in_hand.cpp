#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace std;
using namespace cv;


Mat src, src_gray;
int min_thresh = 120;
int max_thresh = 255;
RNG rng(12345);

void thresh_callback(int, void *)
{
    Mat src_copy = src.clone();
    Mat thresh_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // detect edges using threshold
    threshold(src_gray, thresh_output, min_thresh, max_thresh, THRESH_BINARY);
    // find contours
    findContours(thresh_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    // find the convex hull object for each contour
    vector<vector<Point>> hull(contours.size());
    for (size_t i = 0; i < contours.size(); i++)
    {
        /* code */
        convexHull(Mat(contours[i]), hull[i], false);
    }
    Mat drawing = Mat::zeros(thresh_output.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
        drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
    }
    /// Show in a window
    namedWindow("Hull demo", WINDOW_AUTOSIZE);
    imshow("Hull demo", drawing);
}

int main(int argc, char const *argv[])
{
    /* code */
    src = imread("../images/bantay.jpg");
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    blur(src_gray, src_gray, Size(3, 3));

    namedWindow("source", WINDOW_AUTOSIZE);
    createTrackbar("thresh: ", "source", &min_thresh, max_thresh, thresh_callback);
    thresh_callback(0, 0);
    waitKey(0);

    return 0;
}
