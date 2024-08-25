#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <std_msgs/String.h>

using namespace cv;
using namespace std;

Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
Mat frame1, frame2, frame3;         // 相機 Mat
Mat Hsv, Blur, GB;                  // RGB2HSV Mat, 濾波 Mat
Mat ing;                            // 藍色區域 Mat

int h1 = 100, h2 = 130;             // 初始化最小與最大選取藍色範圍
int s1 = 90, s2 = 255;
int v1 = 60, v2 = 255;

char Find[] = "I found the blue thing."; // 修正字串初始化

vector<vector<Point>> contours;      // 初始化向量
vector<Vec4i> hierarchy;

void on_Trackbar(int, void*) {}

int main(int argc, char** argv) {
    ros::init(argc, argv, "videocheck");
    ros::NodeHandle nh;
    ros::Rate loop_rate(10);

    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Error opening video stream" << endl;
        return -1;
    }

    namedWindow(" ", WINDOW_AUTOSIZE); // 使用 OpenCV 的 namedWindow

    createTrackbar("min_hue", " ", &h1, 255, on_Trackbar);
    createTrackbar("min_saturation", " ", &s1, 255, on_Trackbar);
    createTrackbar("min_value", " ", &v1, 255, on_Trackbar);
    createTrackbar("max_hue", " ", &h2, 255, on_Trackbar);
    createTrackbar("max_saturation", " ", &s2, 255, on_Trackbar);
    createTrackbar("max_value", " ", &v2, 255, on_Trackbar);

    while (ros::ok()) {
        cap >> frame1;
        if (frame1.empty()) break;

        morphologyEx(frame1, frame2, MORPH_OPEN, element); // 使用 OpenCV 的 MORPH_OPEN
        morphologyEx(frame2, frame3, MORPH_CLOSE, element); // 使用 OpenCV 的 MORPH_CLOSE

        GaussianBlur(frame3, GB, Size(15, 15), 0); // 修正 GaussianBlur 參數
        cvtColor(GB, Hsv, COLOR_BGR2HSV); // 使用 OpenCV 的 COLOR_BGR2HSV

        inRange(Hsv, Scalar(h1, s1, v1), Scalar(h2, s2, v2), ing);

        findContours(ing, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE); // 使用 OpenCV 的 RETR_EXTERNAL 和 CHAIN_APPROX_NONE

        for (size_t i = 0; i < contours.size(); i++) {
            if (contourArea(contours[i]) > 500) {
                putText(frame1, Find, Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
            }
        }

        imshow(" ", frame1);

        if (waitKey(100) == 27) break; // ESC 鍵退出

        loop_rate.sleep();
    }

    cap.release();
    destroyAllWindows();

    return 0;
}