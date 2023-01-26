#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>


using namespace std;
using namespace cv;
using namespace dnn;


int main(int argc, char const *argv[])
{
    /* code */
    string txt_path = "../file_text/classification_classes_ILSVRC2012.txt";
    string densenet_121_prototxt = "../file_text/DenseNet_121.prototxt";
    string densenet_121_caffemodel = "../file_text/DenseNet_121.caffemodel";
    string img_path = "../images/tiger.jpg";

    vector<string> class_names;
    ifstream ifs((txt_path).c_str());
    string line;
    while (getline(ifs, line))
    {
        class_names.push_back(line);
    }
    // for (int i = 0; i < class_names.size(); i++)
    // {
    //     cout << class_names[i] << endl;
    // }
    auto model = readNet(densenet_121_prototxt, densenet_121_caffemodel, "Caffe");
    Mat img = imread(img_path);
    Mat blob = blobFromImage(img, 0.01, Size(224, 224), Scalar(104, 117, 123));
    model.setInput(blob);
    Mat outputs = model.forward();
    Point class_point;
    double final_prob;
    minMaxLoc(outputs.reshape(1, 1), 0, &final_prob, 0, &class_point);
    int label_id = class_point.x;
    string out_text = format("%s, %.3f", (class_names[label_id].c_str()), final_prob);
    putText(img, out_text, Point(25, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
    imshow("image", img);
    waitKey(0);
    // destroyAllWindows();
    return 0;
}
