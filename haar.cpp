 #include <iostream>
 #include "opencv.hpp"

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Can't open camera" << std::endl;
        return -1;
    }

    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load(cv::samples::findFile("haarcascade_frontalface_default.xml"))) {
        std::cerr << "Can't load cascade" << std::endl;
        return -1;
    }

    std::cout << "Camera On" << std::endl;

    while (true) {
        cv::Mat frame;
        if (!cap.read(frame)) {
            std::cerr << "Can't read frame" << std::endl;
            break;
        }

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.2, 5, 0, cv::Size(30, 30));

        for (const auto& face : faces) {
            cv::rectangle(frame, face, cv::Scalar(255, 53, 18), 2);
        }

        cv::imshow("Video Frame", frame);

        if (cv::waitKey(1) == 'q') {
            std::cout << "Camera Off" << std::endl;
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}


    
 
