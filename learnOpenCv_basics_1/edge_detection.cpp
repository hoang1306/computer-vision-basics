#include <iostream>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int main(){
    string img_path = "../images/tiger.jpg";
    Mat img = imread(img_path, 0);
    imshow("anh ho origin", img);
    Mat img_blur;
    GaussianBlur(img, img_blur, Size(3, 3), 0, 0);
    // imshow("anh ho dep", img_blur);
    Mat sobel_x, sobel_y, sobel_xy;
    Sobel(img_blur, sobel_x, CV_64F, 1, 0, 5);
    Sobel(img_blur, sobel_y, CV_64F, 0, 1, 5);
    Sobel(img_blur, sobel_xy, CV_64F, 1, 1, 5);

    imshow("sobel x", sobel_x);
    waitKey(0);
    imshow("sobel y", sobel_y);
    waitKey(0);
    imshow("sobel xy", sobel_xy);
    waitKey(0);
    Mat edges;
    Canny(img_blur, edges, 100, 200, 3, false);
    imshow("Canny edge detection", edges);
    waitKey(0);
    
    destroyAllWindows();
    
    waitKey(0);
    return 0;
}