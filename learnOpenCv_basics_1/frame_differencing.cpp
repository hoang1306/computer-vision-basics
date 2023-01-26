#include <iostream>
#include <random>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;


int compute_median(vector<int> elements)
{
    nth_element(elements.begin(), elements.begin() + elements.size() / 2, elements.end());
    return elements[elements.size() / 2];
}
Mat compute_median(vector<Mat> vec)
{
    Mat median_img(vec[0].rows, vec[0].cols, CV_8UC3, Scalar(0, 0, 0));
    for (size_t row = 0; row < vec[0].rows; row++)
    {
        /* code */
        for (size_t col = 0; col < vec[0].cols; col++)
        {
            vector<int> elements_B;
            vector<int> elements_G;
            vector<int> elements_R;
            for (size_t img_number = 0; img_number < vec.size(); img_number++)
            {
                /* code */
                int B = vec[img_number].at<Vec3b>(row, col)[0];
                int G = vec[img_number].at<Vec3b>(row, col)[1];
                int R = vec[img_number].at<Vec3b>(row, col)[2];
                elements_B.push_back(B);
                elements_G.push_back(G);
                elements_R.push_back(R);
            }
            median_img.at<Vec3b>(row, col)[0] = compute_median(elements_B);
            median_img.at<Vec3b>(row, col)[1] = compute_median(elements_G);
            median_img.at<Vec3b>(row, col)[2] = compute_median(elements_R);
        }
    }
    return median_img;
}
int main(int argc, char const *argv[])
{
    string video_path = "../images/video.mp4";
    string video_file;
    if (argc > 1)
    {
        video_file = argv[1];
    }
    else
    {
        video_file = video_path;
    }
    VideoCapture cap(video_file);
    if (!cap.isOpened())
    {
        cerr << "Error opening video file\n";
    }
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, cap.get(CAP_PROP_FRAME_COUNT));

    vector<Mat> frames;
    Mat frame;
    for (size_t i = 0; i < 25; i++)
    {
        /* code */
        int fid = distribution(generator);
        cap.set(CAP_PROP_POS_FRAMES, fid);
        Mat frame;

        cap >> frame;
        if (frame.empty())
        {
            continue;
        }
        frames.push_back(frame);
    }
    Mat median_frame = compute_median(frames);
    cap.set(CAP_PROP_POS_FRAMES, 0);
    Mat gray_median_frame;
    cvtColor(median_frame, gray_median_frame, COLOR_BGR2GRAY);
    while (1)
    {
        /* code */
        cap >> frame;
        if (frame.empty())
        {
            break;
        }
        cvtColor(frame, frame, COLOR_BGR2GRAY);
        Mat dframe;
        absdiff(frame, gray_median_frame, dframe);
        threshold(dframe, dframe, 30, 255, THRESH_BINARY);
        imshow("frame", dframe);
        waitKey(0);
    }

    cap.release();

    return 0;
}