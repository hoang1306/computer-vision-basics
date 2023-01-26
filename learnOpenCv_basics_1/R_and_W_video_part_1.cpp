#include <iostream>
#include <opencv2/opencv.hpp>


// 1. Create a video capture object
// 2. Obtain fps and frame count by get() method and print
// 3. reading a video
// 4. release video capture object


int main()
{
    // 1. create a video capture object
    // VideoCApture: https://docs.opencv.org/master/d4/d15/group__videoio__flags__base.html
    cv::VideoCapture vid_capture("../images/video.mp4");
    if (!vid_capture.isOpened())
    {
        std::cout << "error opening video stream or file" << std::endl;
    }
    else
    {
        // 2. Obtain fps and frame count by get() method and print
        int fps = vid_capture.get(5);
        std::cout << "Frame per second: " << fps << std::endl;
        int frame_count = vid_capture.get(7);
        std::cout << "frame count: " << frame_count << std::endl;
    }
    // 3. reading a video
    while (vid_capture.isOpened())
    {
        /* code */
        // init frame matrix
        cv::Mat frame;
        // init a boolean to check if frames are there or not
        bool isSuccess = vid_capture.read(frame);
        // it frames are present, show it
        if(isSuccess == true){
            cv::imshow("Frame", frame);
        }
        // it frame are not there, close it
        if(isSuccess ==false){
            std::cout << "video camera is disconnected" << std::endl;
            break;
        }
        int key = cv::waitKey(20);
        if (key == 'q'){
            std::cout << "q key is pressed by the user. stopping the video" << std::endl;
            break;
        }
    }
    // 4. release video capture object
    vid_capture.release();
    cv::destroyAllWindows();
    return 0;
}