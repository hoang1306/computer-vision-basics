#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    std::string path = "../images/";
    cv::Mat bright = cv::imread(path + "cube1.png");
    cv::Mat dark = cv::imread(path + "cube2.png");

    cv::Mat bright_ycb;
    cv::cvtColor(bright, bright_ycb, cv::COLOR_BGR2YCrCb);
    cv::Mat dark_ycb;
    cv::cvtColor(dark, dark_ycb, cv::COLOR_BGR2YCrCb);

    cv::Mat bright_hsv;
    cv::Mat dark_hsv;
    cv::cvtColor(bright, bright_hsv, cv::COLOR_BGR2HSV);
    cv::cvtColor(dark, dark_hsv, cv::COLOR_BGR2HSV);

    cv::Mat bright_lab;
    cv::Mat dark_lab;
    cv::cvtColor(bright, bright_lab, cv::COLOR_BGR2Lab);
    cv::cvtColor(dark, dark_lab, cv::COLOR_BGR2Lab);

    cv::Vec3b bgr_pixel(20, 20, 20);
    cv::Mat3b bgr(bgr_pixel);
    cv::Mat3b hsv, ycb, lab;

    cv::cvtColor(bgr, ycb, cv::COLOR_BGR2YCrCb);
    cv::cvtColor(bgr, lab, cv::COLOR_BGR2Lab);
    cv::cvtColor(bgr, hsv, cv::COLOR_BGR2HSV);

    cv::Vec3b hsv_pixel(hsv.at<cv::Vec3b>(0, 0));
    cv::Vec3b lab_pixel(lab.at<cv::Vec3b>(0, 0));
    cv::Vec3b ycb_pixel(ycb.at<cv::Vec3b>(0, 0));

    // std::cout << hsv_pixel << std::endl;
    // std::cout << lab_pixel << std::endl;
    // std::cout << ycb_pixel << std::endl;
    // std::cout << bgr_pixel << std::endl;

    int thresh = 100;
    cv::Scalar min_bgr = cv::Scalar(bgr_pixel.val[0] - thresh, bgr_pixel.val[1] - thresh, bgr_pixel[2] - thresh);
    cv::Scalar max_bgr = cv::Scalar(bgr_pixel.val[0] + thresh, bgr_pixel.val[1] + thresh, bgr_pixel[2] + thresh);

    cv::Mat mask_bgr, result_bgr;
    cv::inRange(bright_hsv, min_bgr, max_bgr, mask_bgr);
    cv::bitwise_and(bright, bright, result_bgr, mask_bgr);

    cv::Scalar min_hsv = cv::Scalar(hsv_pixel.val[0] - thresh, hsv_pixel.val[1] - thresh, hsv_pixel[2] - thresh);
    cv::Scalar max_hsv = cv::Scalar(hsv_pixel.val[0] + thresh, hsv_pixel.val[1] + thresh, hsv_pixel[2] + thresh);

    cv::Mat mask_hsv, result_hsv;
    cv::inRange(bright_hsv, min_hsv, max_hsv, mask_hsv);
    cv::bitwise_and(bright_hsv, bright_hsv, result_hsv, mask_hsv);

    cv::Scalar min_ycb = cv::Scalar(ycb_pixel.val[0] - thresh, ycb_pixel.val[1] - thresh, ycb_pixel[2] - thresh);
    cv::Scalar max_ycb = cv::Scalar(ycb_pixel.val[0] + thresh, ycb_pixel.val[1] + thresh, ycb_pixel[2] + thresh);

    cv::Mat mask_ycb, result_ycb;
    cv::inRange(bright_ycb, min_ycb, max_ycb, mask_ycb);
    cv::bitwise_and(bright_ycb, bright_ycb, result_ycb, mask_ycb);

    cv::Scalar min_lab = cv::Scalar(lab_pixel.val[0] - thresh, lab_pixel.val[1] - thresh, lab_pixel[2] - thresh);
    cv::Scalar max_lab = cv::Scalar(lab_pixel.val[0] + thresh, lab_pixel.val[1] + thresh, lab_pixel[2] + thresh);

    cv::Mat mask_lab, result_lab;
    cv::inRange(bright_lab, min_lab, max_lab, mask_lab);
    cv::bitwise_and(bright_lab, bright_lab, result_lab, mask_lab);

    // std::cout << mask_bgr << std::endl;
    // std::cout << result_bgr << std::endl;

    imshow("result bgr", result_bgr);
    imshow("result ycb", result_ycb);
    imshow("result lab", result_lab);
    imshow("result hsv", result_hsv);
    cv::waitKey();

    return 0;
}