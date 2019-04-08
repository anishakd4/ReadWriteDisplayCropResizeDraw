#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;

int main(){
    Mat inputImage;

    //Read image using opencv
    inputImage = imread("../assets/putin.jpg", IMREAD_COLOR);

    //Check if the image exists
    if(inputImage.empty()){
        cout<<"image doesn't exist"<<endl;
        return -1;
    }

    //Create a copy of input image to work on so that we can finally have input image to compare the results to
    Mat image = inputImage.clone();

    Mat grayImage;
    //convert color image to gray
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    Mat resizedUpImage, resizedDownImage;

    //Resizing down the image 0.3 times
    resize(image, resizedDownImage, Size(), 0.3, 0.3, INTER_LINEAR); 

    //Resizing up the image 1.5 times
    resize(image, resizedUpImage, Size(), 1.5, 1.5, INTER_LINEAR);

    //Cropping image
    Mat croppedImage;
    croppedImage = inputImage(Range(0, 700), Range(500, 1000));

    //Draw line over image
    Mat lineImage = image.clone();
    line(lineImage, Point(750, 300), Point(1000, 500), Scalar(0, 0, 255), 5, CV_AA);

    //Draw a circle over image
    Mat circleImage = image.clone();
    circle(circleImage, Point(750, 300), 250, Scalar(0, 0, 255), 5, CV_AA);

    //Draw an ellipse over image
    Mat ellipseImage = image.clone();
    ellipse(ellipseImage, Point(750, 300), Size(200, 250), 45, 0, 360, Scalar(0, 0, 255), 5, 8);
    ellipse(ellipseImage, Point(750, 300), Size(200, 250), 135, 0, 360, Scalar(0, 0, 255), 5, 8);

    //Draw a rectangle over image
    Mat rectangleImage = image.clone();
    rectangle(rectangleImage, Point(750, 300), Point(1000, 600), Scalar(0, 0, 255), 5, 8);

    //Draw text over image
    Mat textImage = image.clone();
    putText(textImage, "Anish Vision", Point(750, 300), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 5);
    
    //Create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("gray image", WINDOW_NORMAL);
    namedWindow("resized up", WINDOW_NORMAL);
    namedWindow("resized down", WINDOW_NORMAL);
    namedWindow("cropped image", WINDOW_NORMAL);
    namedWindow("line image", WINDOW_NORMAL);
    namedWindow("circle image", WINDOW_NORMAL);
    namedWindow("ellipse image", WINDOW_NORMAL);
    namedWindow("rectangle image", WINDOW_NORMAL);
    namedWindow("text image", WINDOW_NORMAL);

    //Show images
    imshow("image", image);
    imshow("gray image", grayImage);
    imshow("resized up", resizedUpImage);
    imshow("resized down", resizedDownImage);
    imshow("cropped image", croppedImage);
    imshow("line image", lineImage);
    imshow("circle image", circleImage);
    imshow("ellipse image", ellipseImage);
    imshow("rectangle image", rectangleImage);
    imshow("text image", textImage);

    //Write images to a file on disk
    imwrite("gray_image.jpg", grayImage);
    imwrite("resized_up.jpg", resizedUpImage);
    imwrite("resized_down.jpg", resizedDownImage);
    imwrite("line_image.jpg", lineImage);
    imwrite("circle_image.jpg", circleImage);
    imwrite("ellipse_image.jpg", ellipseImage);
    imwrite("rectangle_image.jpg", rectangleImage);
    imwrite("text_image.jpg", textImage);

    //This will pause the program until you press any key in keyboard so that you can see the images
    waitKey(0);

    return 0;
}