#include <iostream>
#include <opencv2/opencv.hpp>
// 1. rotation images
// 2. translation images


int main(){
    std::string image_path = "../images/rotation.png";
    cv::Mat img = cv::imread(image_path);
    // 1. rotation images
    cv::Point2f center((img.cols - 1)/2., (img.rows - 1)/2.);
    // std::cout << center << std::endl;
    cv::Mat rotation_matrix = cv::getRotationMatrix2D(center, 45, 1.0);
    // std::cout << rotation_matrix << std::endl;
    cv::Mat rotated_image;
    cv::warpAffine(img, rotated_image,rotation_matrix, img.size());
    // imshow("rotation images", rotated_image);
    // 2. translation images
    int height = img.cols;
    int width = img.rows;

    float tx = -float(width)/3;
    float ty = -float(height)/5;
    
    float warp_values[] = {1.0, 0.0, tx, 0.0, 1.0, ty};
    cv::Mat translation_img;
    cv::Mat translation_matrix = cv::Mat(2, 3, CV_32F, warp_values);
    cv::warpAffine(img, translation_img,translation_matrix, img.size());
    imshow("translation image", translation_img);
    cv::waitKey(0);
    return 0;
}