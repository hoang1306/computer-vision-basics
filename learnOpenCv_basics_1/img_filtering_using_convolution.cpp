#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

// https://en.wikipedia.org/wiki/Kernel_(image_processing)
// Define kernels

// #define identity mat3(0, 0, 0, 0, 1, 0, 0, 0, 0)
// #define edge0 mat3(1, 0, -1, 0, 0, 0, -1, 0, 1)
// #define edge1 mat3(0, 1, 0, 1, -4, 1, 0, 1, 0)
// #define edge2 mat3(-1, -1, -1, -1, 8, -1, -1, -1, -1)
// #define sharpen mat3(0, -1, 0, -1, 5, -1, 0, -1, 0)
// #define box_blur mat3(1, 1, 1, 1, 1, 1, 1, 1, 1) * 0.1111
// #define gaussian_blur mat3(1, 2, 1, 2, 4, 2, 1, 2, 1) * 0.0625
// #define emboss mat3(-2, -1, 0, -1, 1, 1, 0, 1, 2)
int main()
{
    std::string img_path = "../images/wood.jpg";
    Mat img = imread(img_path); 
    if (img.empty()){
        cout << "no images" << endl;
    }
    Mat kernel_1 = (Mat_<double>(3, 3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);
    // cout << kernel_1 << endl;
    Mat identity;
    filter2D(img, identity, -1, kernel_1, Point(-1, -1), 0, 4);
    imshow("Original", img);
    // imshow("Identity", identity);

    Mat kernel_2 = Mat::ones(5, 5, CV_64F);

    kernel_2 = kernel_2/25;
    Mat new_img;
    filter2D(img, new_img, -1, kernel_2, Point(-1, -1), 0, 4);
    // imshow("kernal blur", new_img);

    Mat img_blur;
    blur(img, img_blur, Size(5, 5));
    // imshow("blurred", img_blur);

    Mat gaussian_blur;
    GaussianBlur(img, gaussian_blur, Size(5, 5), 0, 0);
    // imshow("gaussian blur", gaussian_blur);

    Mat median_blurred;
    medianBlur(img, median_blurred, (5, 5));
    // imshow("median blurred", median_blurred);

    Mat sharp_img;
    Mat kernel_3 = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(img, sharp_img, -1, kernel_3, Point(-1, -1), 0, BORDER_DEFAULT);
    // imshow("Sharpenned", sharp_img);

    Mat bilatera_filter;
    bilateralFilter(img, bilatera_filter, 9, 75, 85);
    imshow("bilatera filter", bilatera_filter);
    waitKey(0);
    destroyAllWindows();
    return 0;
}