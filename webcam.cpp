#include <iostream>
#include "./opencv.hpp"

using namespace std;
using namespace cv;


int main() {
    Mat frame;
    namedWindow("Video");
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "No video" << endl;
        return -1;
    }

    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        imshow("Video", frame);
        if (waitKey(25) == 27) break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}

