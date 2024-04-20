#include <./opencv.hpp>
#include <iostream>


int main() {
    
    cv::Mat img = cv::imread("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/free-nature-images.jpg");
    
    if (img.empty()) {
        std::cout << "Image is empty" << std::endl;
    } else {
        std::cout << "Image is not empty" << std::endl;
    }

   
    cv::Mat text_image = img.clone();
    cv::Mat line_image = img.clone();
    cv::Mat rectangle_image = img.clone();
    cv::Mat circle_image = img.clone();

   
    cv::putText(text_image, "Nature", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2, cv::LINE_AA);

    
    cv::line(line_image, cv::Point(0, 0), cv::Point(511, 511), cv::Scalar(255, 0, 0), 5);
    cv::rectangle(rectangle_image, cv::Point(384, 0), cv::Point(510, 128), cv::Scalar(0, 255, 0), 3);
    cv::circle(circle_image, cv::Point(447, 63), 63, cv::Scalar(0, 0, 255), -1);

   
    cv::imshow("Texted Image", text_image);
    cv::imshow("Line Image", line_image);
    cv::imshow("Rectangle Image", rectangle_image);
    cv::imshow("Circle Image", circle_image);

    cv::waitKey(0);  
    cv::destroyAllWindows();  

    
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/textedimage.jpg", text_image);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/line.jpg", line_image);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/rectangle.jpg", rectangle_image);
    cv::imwrite("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/circle.jpg", circle_image);

    return 0;
}

