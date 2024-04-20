#include <./opencv.hpp>
#include <iostream>



int main() {
    
    cv::Mat img = cv::imread("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/free-nature-images.jpg");
    cv::Mat img_for_median = cv::imread("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/1 2I9jCD3ZuQd-SUhC21ra8Q.jpg");

    if (img.empty()) {
        std::cout << "Image is empty" << std::endl;
        return -1; 
    } else {
        std::cout << "Image is not empty" << std::endl;
    }

   
    cv::Mat rgb_img, hsv_img, lab_img, gray_img;
    cv::cvtColor(img, rgb_img, cv::COLOR_BGR2RGB);
    cv::cvtColor(img, hsv_img, cv::COLOR_BGR2HSV);
    cv::cvtColor(img, lab_img, cv::COLOR_BGR2LAB);
    cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);

    
    cv::Mat blur_img;
    cv::GaussianBlur(img, blur_img, cv::Size(5, 5), 0);

   
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
        -1, -1, -1,
        -1, 9, -1,
        -1, -1, -1);

    cv::Mat sharp_img;
    cv::filter2D(img, sharp_img, -1, kernel);

   
    cv::Mat median_img;
    cv::medianBlur(img_for_median, median_img, 3);

   
    cv::imshow("sharp", sharp_img);
    cv::imshow("rgb", rgb_img);
    cv::imshow("hsv", hsv_img);
    cv::imshow("lab", lab_img);
    cv::imshow("gray", gray_img);
    cv::imshow("blur", blur_img);
    cv::imshow("median", median_img);

    cv::waitKey(0);
    cv::destroyAllWindows();

    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/rgb.jpg", rgb_img);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/hsv.jpg", hsv_img);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/lab.jpg", lab_img);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/gray.jpg", gray_img);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/blur.jpg", blur_img);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/sharp.jpg", sharp_img);

    return 0;
}

