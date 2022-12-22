#include <iostream>
#include <opencv2/opencv.hpp>


int main(){
    std::string img_path = "../images/sample.jpg";
    cv::Mat img = cv::imread(img_path);
    cv::Mat img_line = img.clone();
    // imshow("origin images", img);
    // cv::waitKey();
    if(img.empty()){
        std::cout << "Could not read image" << std::endl;
    }
    cv::Point point_a(20, 80), point_b(220, 80);
    cv::line(img_line, point_a, point_b, cv::Scalar(255, 255, 0), 3, 8, 0);
    // imshow("Image line", img_line);
    cv::Mat circle_image = img.clone();
    cv::Point circle_center(415, 190);
    int radius = 100;
    cv::circle(circle_image, circle_center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
    // imshow("cirle image", circle_image);

    cv::Mat filled_circle_image = img.clone();
    cv:circle(filled_circle_image, circle_center, radius, cv::Scalar(255, 0, 0), -1, 3, 0);
    // imshow("filled circle image", filled_circle_image);
    cv::Mat rect_img = img.clone();
    cv::Point star_point(300, 115);
    cv::Point end_point(475, 225);
    cv::rectangle(rect_img, star_point, end_point, cv::Scalar(0, 0, 255), 3, 8, 0);
    // imshow("rectangle image", rect_img);

    cv::Mat image_ellipse = img.clone();
    cv::Point ellipse_center(415, 190);
    cv::Point axis1(100, 50);
    cv::Point axis2(125, 50);
    cv::ellipse(image_ellipse, ellipse_center, axis1, 0, 0, 360, cv::Scalar(255, 0, 0), 3, 8, 0);
    cv::ellipse(image_ellipse, ellipse_center, axis2, 90, 0, 360, cv::Scalar(255, 255, 0), 3, 8, 0);
    // imshow("ellipse on image", image_ellipse);

    cv::Mat half_ellipse = img.clone();
    cv::ellipse(half_ellipse, ellipse_center, axis1, 0, 180, 360, cv::Scalar(225, 225, 225), 3, 8, 0);
    cv::ellipse(half_ellipse, ellipse_center, axis1, 0, 0, 180, cv::Scalar(225, 225, 225), -1, 8, 0);
    // imshow("half ellipse on images", half_ellipse);

    cv::Mat image_text = img.clone();
    std::string text= "thit cho ngon vcl, ko an thi phi cuoc doi";
    cv::Point point(50, 350);
    cv::putText(image_text, text, point, cv::FONT_HERSHEY_COMPLEX, 1.5, cv::Scalar(250, 250, 1));
    imshow("Text on image", image_text);

    cv::waitKey();

    return 0;
}