#include <iostream>
#include "./opencv.hpp"

using namespace std;
using namespace cv;




int main() {
    cv::Mat img = cv::imread("/home/maria/Desktop/Picsart Academy /project_ds/"
                              "pythonProject1/picture-a-captivating-scene-of-a-tranquil-lake-at-sunset-ai-generative-photo.jpg");
    if (img.empty()) {
        std::cout << "Image is empty" << std::endl;
        return -1;
    }
    else {
        std::cout << "Image is not empty" << std::endl;
    }
    cv::Mat res;
    cv::resize(img, res, cv::Size(2 * img.cols, 2 * img.rows), 0, 0, cv::INTER_CUBIC);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/resized.jpg", res);
    cv::Mat flip;
    cv::flip(img, flip, 0);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/flipped.jpg", flip);

    cv::Mat flip1;
    cv::flip(img, flip1, 1);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/flipped1.jpg", flip1);

    cv::Rect crop_region(150, 80, 330 - 150, 280 - 80);
    cv::Mat cropped = img(crop_region);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/cropped.jpg", cropped);

    cv::Mat rotate;
    cv::rotate(img, rotate, cv::ROTATE_90_CLOCKWISE);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/rotated.jpg", rotate);

    cv::imshow("cropped", cropped);
    cv::imshow("flipped1", flip1);
    cv::imshow("flipped", flip);
    cv::imshow("image", res);
    cv::imshow("rotated", rotate);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
