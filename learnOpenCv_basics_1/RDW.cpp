#include <iostream>
#include <opencv2/opencv.hpp>


// step in writing this code
// 1. read an image
// 2. display the image
// 3. write an images


int main()
{
    // include path image
    std::string img_path = "../images/test.jpg";
    int Flags;
    std::cout << "Input flags: ";
    std::cin >> Flags;
    // 1. read an image
    // cv::imread(image_file_name, flags)
    // https://docs.opencv.org/4.x/d8/d6a/group__imgcodecs__flags.html#ga61d9b0126a3e57d9277ac48327799c80
    // several options for this Flags:
    //      cv2.IMREAD_UNCHANGED  or -1
    //      cv2.IMREAD_GRAYSCALE  or 0
    //      cv2.IMREAD_COLOR  or 1
    // note: opencv reads color image in BGR format
    cv::Mat img_grayscale = cv::imread(img_path, 0);
    cv::Mat img_color = cv::imread(img_path, 1);
    cv::Mat img_unchanged = cv::imread(img_path, -1);
    switch (Flags)
    {
        case 0:
            // check image grayscale is empty
            if (img_grayscale.empty())
            {
                std::cout << "no image" << std::endl;
            }
            // img not empty
            else
            {
                // 2. display the image
                imshow("grayscale image", img_grayscale);
                cv::waitKey(0);
                cv::destroyAllWindows();
                // 3. write an image
                imwrite("../output_images/grayscale.jpg", img_grayscale);
            }
            /* code */
            break;
        case 1:
            // check image image color is empty
            if (img_color.empty())
            {
                std::cout << "no image" << std::endl;
            }
            // img not empty
            else
            {
                // 2. display the image
                imshow("color image", img_color);
                cv::waitKey(0);
                cv::destroyAllWindows();
                // 3. write an image
                imwrite("../output_images/img_color.jpg", img_color);
            }
            break;
        case -1:
            // check image image unchanged is empty
            if (img_unchanged.empty())
            {
                std::cout << "no image" << std::endl;
            }
            // img not empty
            else
            {
                // 2. display the image
                imshow("unchanged image", img_unchanged);
                cv::waitKey(0);
                cv::destroyAllWindows();
                // 3. write an image
                imwrite("../output_images/img_unchanged.jpg", img_unchanged);
            }
            break;
        default:
            std::cout << "flags does not exist" << std::endl;
            break;
    }
    return 0;
}