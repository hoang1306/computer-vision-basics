#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main(int argc, char** argv){
    string img_path = "../images/sohocthuantuy.jpg"; 
    Mat src = imread(img_path, IMREAD_GRAYSCALE);

    Mat dst;
    threshold(src, dst, 0, 255, THRESH_BINARY);
    imshow("thresh example", dst);

    threshold(src, dst, 0, 128, THRESH_BINARY);
    imshow("thresh binary maxval", dst);

    threshold(src, dst, 127, 255, THRESH_BINARY);
    imshow("thresh binary", dst);

    threshold(src, dst, 127, 255, THRESH_BINARY_INV);
    imshow("thresh binary inv", dst);

    threshold(src, dst, 127, 255, THRESH_TRUNC);
    imshow("thresh truct", dst);

    threshold(src, dst, 127, 255, THRESH_TOZERO);
    imshow("thresh to zero", dst);

        threshold(src, dst, 127, 255, THRESH_TOZERO_INV);
    imshow("thresh to zero int", dst);
    waitKey(0);
    destroyAllWindows();
    return 0;
}