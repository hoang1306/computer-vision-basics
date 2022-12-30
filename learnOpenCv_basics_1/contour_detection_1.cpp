#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
int main(){
    string img_path = "../images/iphone.png";
    Mat img = imread(img_path);
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    Mat thresh;
    threshold(img_gray, thresh, 150, 255, THRESH_BINARY);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    Mat img_copy = img.clone();
    drawContours(img_copy, contours, -1, Scalar(0, 255, 0), 2);
    imshow("none approxmation", img_copy);
    waitKey(0);
    destroyAllWindows();
    Mat img_copy_1 = img_copy.clone();
    for (size_t i = 0; i < contours.size(); i++)
    {
        /* code */
        for (size_t j = 0; j < contours[i].size(); j++)
        {
            /* code */
            circle(img_copy_1, (contours[i][0], contours[i][1]), 2, Scalar(0, 255, 0), 2);
        }
    }
    imshow("chain approx simple point only", img_copy_1);
    waitKey(0);
    destroyAllWindows();    
    return 0;
}