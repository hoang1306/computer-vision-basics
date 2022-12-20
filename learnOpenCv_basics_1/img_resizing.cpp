#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    int down_width = 300;
    int down_height = 200;
    cv::Mat resize_down;
    // image path
    std::string img_path = "../images/test.jpg";
    cv::Mat img = cv::imread(img_path);

    // reading image
    // Height: 682
    // Widgth: 1024
    // Get original height and width
    // soulution 1
    // std::cout << "Height: " << img.rows << std::endl;
    // std::cout << "Widgth: " << img.cols << std::endl;
    // solution 2
    // std::cout << "Height: " << img.size().height << std::endl;
    // std::cout << "Widgth: " << img.size().width << std::endl;
    // down size
    resize(img, resize_down, cv::Size(down_width, down_height), cv::INTER_LINEAR);
    // imshow("image resize down", resize_down);

    int up_width = 600;
    int up_height = 400;
    cv::Mat resize_up;
    resize(img, resize_up, cv::Size(up_width, up_height), cv::INTER_LINEAR);
    // imshow("image resize up", resize_up);

    double scale_up = 1.2;

    double scale_down = 0.6;
    cv::Mat scale_f_down, scale_f_up;

    resize(img, scale_f_down, cv::Size(), scale_down, scale_down, cv::INTER_LINEAR);
    resize(img, scale_f_up, cv::Size(), scale_up, scale_up, cv::INTER_LINEAR);

    // imshow("scale down", scale_f_down);
    // imshow("scale up", scale_f_up);
    std::cout << "Height: " << scale_f_down.size().height << std::endl;
    std::cout << "Widgth: " << scale_f_down.size().width << std::endl;
    std::cout << "Height: " << scale_f_up.rows << std::endl;
    std::cout << "Widgth: " << scale_f_up.cols << std::endl;

    cv::Mat res_inter_linear, res_inter_nearest, res_inter_area;
    
    resize(img, res_inter_linear, cv::Size(), scale_down, scale_down, cv::INTER_LINEAR);
    resize(img, res_inter_nearest, cv::Size(), scale_down, scale_down, cv::INTER_NEAREST);
    resize(img, res_inter_area, cv::Size(), scale_down, scale_down, cv::INTER_AREA);

    imshow("res_inter_linear", res_inter_linear);
    imshow("res_inter_nearest", res_inter_nearest);
    imshow("res_inter_area", res_inter_area);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}