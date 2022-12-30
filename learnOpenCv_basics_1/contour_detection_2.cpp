#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    string img_path = "../images/custom_colors.jpg";
    Mat img = imread(img_path);
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    Mat thresh;
    threshold(img_gray, thresh, 150, 255, THRESH_BINARY);
    // imshow("img gray", img_gray);
    // imshow("img thresh", thresh);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    // findContours(thresh, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
    findContours(thresh, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_NONE);
    // findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    // findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    Mat img_copy = img.clone();
    drawContours(img_copy, contours, -1, Scalar(0, 255, 0), 2);
    imshow("RETR_CCOMP", img_copy);
    // imshow("RETR_TREE", img_copy);
    // imshow("simple approximation", img_copy);
    // imshow("RETR_EXTERNAL", img_copy);


    waitKey(0);
    destroyAllWindows();

    return 0;
}