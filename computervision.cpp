#include <iostream>
#include "./opencv.hpp"



using namespace std;
using namespace cv;


int main(){

Mat img = imread("/home/maria/Pictures/Screenshots/Screenshot from 2023-09-28 19-25-57.png");

imshow("image", img); 
   
waitKey(0);  
                         
destroyAllWindows();


    return 0;
}


