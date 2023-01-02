#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

using namespace std;
using namespace cv;
using namespace dnn;

string video_path = "../images/video.mp4";
string txt_path = "../file_text/object_detection_classes_coco.txt";
string graph = "../file_text/frozen_inference_graph.pb";
string ssd = "../file_text/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt";

int main()
{

    std::vector<std::string> class_names;
    ifstream ifs(string(txt_path).c_str());
    string line;
    while (getline(ifs, line))
    {
        class_names.push_back(line);
    }
    auto model = readNet(graph, ssd, "TensorFlow");
    VideoCapture cap(video_path);
    int frame_height = static_cast<int>(cap.get(3));
    int frame_width = static_cast<int>(cap.get(4));
    // VideoWriter out("video_result.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(frame_width, frame_height));
    VideoWriter output_video("../output_images/video_result.mp4",
                             cv::VideoWriter::fourcc('a', 'v', 'c', '1'),
                             30,
                             Size(frame_width, frame_height));
    while (cap.isOpened())
    {
        Mat img;
        bool isSuccess = cap.read(img);
        if (!isSuccess)
        {
            break;
        }

        int img_height = img.cols;
        int img_width = img.rows;
        Mat blob = blobFromImage(img, 1.0, Size(300, 300), Scalar(127.5, 127.5, 127.5),
                                 true, false);
        model.setInput(blob);
        Mat output = model.forward();
        Mat detection_mat(output.size[2], output.size[3], CV_32F, output.ptr<float>());
        for (int i = 0; i < detection_mat.rows; i++)
        {
            int class_id = detection_mat.at<float>(i, 1);
            float confidence = detection_mat.at<float>(i, 2);
            if (confidence > 0.4)
            {
                int box_x = static_cast<int>(detection_mat.at<float>(i, 3) * img.cols);
                int box_y = static_cast<int>(detection_mat.at<float>(i, 4) * img.rows);
                int box_width = static_cast<int>(detection_mat.at<float>(i, 5) * img.cols - box_x);
                int box_height = static_cast<int>(detection_mat.at<float>(i, 6) * img.rows - box_y);
                rectangle(img, Point(box_x, box_y), Point(box_x + box_width, box_y + box_height), Scalar(255, 255, 255), 2);
                putText(img, class_names[class_id - 1].c_str(), Point(box_x, box_y - 5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 1);
            }
        }

        imshow("img", img);
        output_video.write(img);
        int k = waitKey(10);
        if (k == 113)
        {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
    return 0;
}