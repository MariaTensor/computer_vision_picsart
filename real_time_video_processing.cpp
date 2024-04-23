#include <./opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) return -1;

    std::string effect = "Normal";

    while (true) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        if (effect == "Grayscale") cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
        else if (effect == "HSV") cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
        else if (effect == "LAB") cv::cvtColor(frame, frame, cv::COLOR_BGR2Lab);
        else if (effect == "Blur") cv::GaussianBlur(frame, frame, cv::Size(15, 15), 0);
        else if (effect == "Median Filter") cv::medianBlur(frame, 15, frame);
        else if (effect == "Flip Vertically") cv::flip(frame, frame, 0);
        else if (effect == "Flip Horizontally") cv::flip(frame, frame, 1);
        else if (effect == "Rotate") cv::rotate(frame, frame, cv::ROTATE_90_CLOCKWISE);
        else if (effect == "Draw Rectangle") cv::rectangle(frame, {50, 50}, {200, 200}, {255, 0, 0}, 2);

        cv::putText(frame, "Effect: " + effect, {10, 30}, cv::FONT_HERSHEY_SIMPLEX, 1, {0, 0, 255}, 2);

        cv::imshow("Webcam", frame);

        char key = cv::waitKey(1);
        if (key == 'q') break;
        else if (key == 'g') effect = "Grayscale";
        else if (key == 'h') effect = "HSV";
        else if (key == 'l') effect = "LAB";
        else if (key == 'b') effect = "Blur";
        else if (key == 'm') effect = "Median Filter";
        else if (key == 'v') effect = "Flip Vertically";
        else if (key == 'x') effect = "Flip Horizontally";
        else if (key == 'r') effect = "Rotate";
        else if (key == 'd') effect = "Draw Rectangle";
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}

