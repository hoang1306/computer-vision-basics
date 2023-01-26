#include <iostream>
#include <opencv2/opencv.hpp>


// Reading an Image Sequence
// 1. create a video capture object
// 2. obtain frame size information using get() method
// 3. init video write object
// 4. save video
// 5. release the objects


int main()
{
    // 1. create a video capture object
    // VideoCApture: https://docs.opencv.org/master/d4/d15/group__videoio__flags__base.html
    // find image
    // cv::VideoCapture vid_capture("../images/video%02d.jpg");
    // camera or webcam
    cv::VideoCapture vid_capture(0);
    // 2. obtain frame size information using get() method
    int frame_width = static_cast<int>(vid_capture.get(3));
    int frame_height = static_cast<int>(vid_capture.get(4));
    cv::Size frame_size(frame_width, frame_height);
    int frames_per_second = 24;
    // 3. init video write object
    cv::VideoWriter output("../output_images/out_put.mp4",
                           cv::VideoWriter::fourcc('a', 'v', 'c', '1'),
                           frames_per_second,
                           frame_size);
    // 4. save video
    while (vid_capture.isOpened())
    {
        /* code */
        cv::Mat frame;
        // init a boolean to check if frames are there or not
        bool isSuccess = vid_capture.read(frame);
        // if frames are not there, close it
        if (isSuccess == false)
        {
            std::cout << "stream disconnected" << std::endl;
            break;
        }
        // it frame are present
        if (isSuccess == true)
        {
            // display frames
            output.write(frame);
            // display frames
            imshow("Frame", frame);
            // wait for 20 ms between successive frames and break
            // the loop if key q is pressed
            int key = cv::waitKey(20);
            if (key == 'q')
            {
                std::cout << "key q key is pressed by the user. stopping the video" << std::endl;
                break;
            }
        }
    }
    // 5. release the objects
    vid_capture.release();
    output.release();
    return 0;
}