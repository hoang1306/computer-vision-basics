#include <opencv2/opencv.hpp>
#include <iostream>


int main()
{
    std::string path = "../images/";
    cv::Mat bright = cv::imread(path + "cube1.png");
    cv::Mat dark = cv::imread(path + "cube2.png");

    cv::Mat bright_ycb;
    cv::cvtColor(bright, bright_ycb, cv::COLOR_BGR2YCrCb);
    cv::Mat dark_ycb;
    cv::cvtColor(dark, dark_ycb, cv::COLOR_BGR2YCrCb);
    imshow("bright ycb", bright_ycb);
    imshow("dark ycb", dark_ycb);
    cv::Mat bright_hsv;
    cv::Mat dark_hsv;
    cv::cvtColor(bright, bright_hsv, cv::COLOR_BGR2HSV);
    cv::cvtColor(dark, dark_hsv, cv::COLOR_BGR2HSV);
    imshow("bright hsv", bright_hsv);
    imshow("dark hsv", dark_hsv);
    cv::Mat bright_lab;
    cv::Mat dark_lab;
    cv::cvtColor(bright, bright_lab, cv::COLOR_BGR2Lab);
    cv::cvtColor(dark, dark_lab, cv::COLOR_BGR2Lab);
    imshow("bright lab", bright_lab);
    imshow("dark lab", dark_lab);
    cv::waitKey(0);

    return 0;
}