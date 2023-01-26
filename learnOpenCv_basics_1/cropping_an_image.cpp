#include <opencv2/opencv.hpp>
#include <iostream>


void dividing_an_image(cv::Mat img)
{
    int img_height = img.size().height;
    int img_width = img.size().width;
    cv::Mat image_copy = img.clone();
    int height = 74, width = 104;
    int x1 = 0, y1 = 0;
    for (size_t y = 0; y < img_height; y += height)
    {
        for (size_t x = 0; x < img_width; x += width)
        {
            if ((img_height - y) < height || (img_width - x) < width)
            {
                break;
            }
            y1 = y + height;
            x1 = x + width;
            std::string a = std::to_string(x);
            std::string b = std::to_string(y);
            if (x1 >= img_width && y1 >= img_height)
            {
                x = img_width - 1;
                y = img_height - 1;
                x1 = img_width - 1;
                y1 = img_height - 1;

                cv::Mat tiles = image_copy(cv::Range(y, img_height), cv::Range(x, img_width));
                cv::imwrite("../output_images/" + a + "_" + b + ".jpg", tiles);
                cv::rectangle(img, cv::Point(x, y), cv::Point(x1, y1), cv::Scalar(0, 255, 0), 1);
            }
            else if (y1 >= img_height)
            {
                y = img_height - 1;
                y1 = img_height - 1;
                cv::Mat tiles = image_copy(cv::Range(y, img_height), cv::Range(x, x + width));
                imwrite("../output_images/" + a + "_" + b + ".jpg", tiles);
                cv::rectangle(img, cv::Point(x, y), cv::Point(x1, y1), cv::Scalar(0, 255, 0), 1);
            }
            else if (x1 >= img_width)
            {
                x = img_width - 1;
                x1 = img_width - 1;
                cv::Mat tiles = image_copy(cv::Range(y, y + height), cv::Range(x, img_width));
                imwrite("../output_images/" + a + '_' + b + ".jpg", tiles);
                rectangle(img, cv::Point(x, y), cv::Point(x1, y1), cv::Scalar(0, 255, 0), 1);
            }
            else
            {
                cv::Mat tiles = image_copy(cv::Range(y, y + height), cv::Range(y, y + width));
                imwrite("../output_images/" + a + "_" + b + ".jpg", tiles);
                cv::rectangle(img, cv::Point(x, y), cv::Point(x1, y1), cv::Scalar(0, 255, 0), 1);
            }
        }
    }
}
int main()
{
    std::string img_path = "../images/test.jpg";
    // cv::Mat image = cv::imread(img_path);
    cv::Mat img = cv::imread(img_path);

    // std::cout << typeid(image.size().height).name()
    //           << std::endl 
    //           << image.size().width 
    //           << std::endl;
    // std::cout << image.size().height << std::endl
    //           << image.size().width << std::endl;

    // cv::Mat crop_image = image(cv::Range(300, 500), cv::Range(200, 600));
    // imshow("cropping an image", crop_image);
    dividing_an_image(img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}