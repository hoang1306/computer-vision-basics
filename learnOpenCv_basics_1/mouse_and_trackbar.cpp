#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int max_scale_up = 100;
int scale_factor = 1;

string window_name = "resize image";
string trackbar_value = "scale";

string img_path = "../images/input_image-2.jpg";
Mat img = imread(img_path);
Point top_left_corner, bottom_right_corner;

void draw_rectangle(int action, int x, int y, int flags, void *user_data)
{
    if (action == EVENT_LBUTTONDOWN)
    {
        top_left_corner = Point(x, y);
    }
    else if (action == EVENT_LBUTTONUP)
    {
        bottom_right_corner = Point(x, y);
        rectangle(img, top_left_corner, bottom_right_corner, Scalar(0, 255, 0), 2, 8);
        imshow("Window", img);
    }
}
void scale_image(int, void *)
{
    double scale_factor_double = 1 + scale_factor / 100.0;
    Mat scaled_image;

    resize(img, scaled_image, Size(), scale_factor_double, scale_factor_double, INTER_LINEAR);
    imshow(window_name, scaled_image);
}
int main()
{
    int a;
    cout << "Mouse is the number key 1 and tracker is the number key 2" << endl;
    cout << "Input number: ";
    cin >> a;
    Mat temp = img.clone();
    int k = 0;

    switch (a)
    {
    case 1:
        namedWindow("Window");
        setMouseCallback("Window", draw_rectangle);
        while (k != 113)
        {
            // imshow("Window", img);
            k = waitKey(0);
            if (k == 99)
            {
                temp.copyTo(img);
            }
        }
        destroyAllWindows();
        break;
    case 2:
        namedWindow(window_name, WINDOW_AUTOSIZE);
        createTrackbar(trackbar_value, window_name, &scale_factor, max_scale_up, scale_image);
        scale_image(25, 0);
        imshow(window_name, img);
        waitKey(0);
        destroyAllWindows();
        break;
    default:
        cout << "error" << endl;
        break;
    }

    return 0;
}