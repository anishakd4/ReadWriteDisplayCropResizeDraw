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
    inputImage = imread("../data/putin.jpg", IMREAD_COLOR);

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

    //Display Image
    //Create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("gray image", WINDOW_NORMAL);

    //Show images
    imshow("image", image);
    imshow("gray image", grayImage);

    //Write images to a file on disk
    imwrite("write_image.jpg", image);
    imwrite("write_gray_image.jpg", grayImage);

    Mat resizedUpImage, resizedDownImage;

    //Resizing down the image 0.3 times
    resize(inputImage, resizedDownImage, Size(), 0.3, 0.3, INTER_LINEAR); 

    //Resizing up the image 1.5 times
    resize(inputImage, resizedUpImage, Size(), 1.5, 1.5, INTER_LINEAR);

    //Create windows for resized up and resized down images
    namedWindow("resized up", WINDOW_NORMAL);
    namedWindow("resized down", WINDOW_NORMAL);

    //Display resized up and resizwd down images
    imshow("resized up", resizedUpImage);
    imshow("resized down", resizedDownImage);

    Mat croppedImage;

    croppedImage = inputImage(Range(0, 700), Range(500, 1000));

    //Create window for cropped image
    namedWindow("cropped image", WINDOW_NORMAL);

    //display cropped image
    imshow("cropped image", croppedImage);

    //Draw a circle over image
    Mat circleImage = inputImage.clone();
    circle(circleImage, Point(750, 300), 250, Scalar(0, 0, 255), 1, CV_AA);
    imwrite("circle_image.jpg", circleImage);
    //create window and show cirled image
    namedWindow("circle image", WINDOW_NORMAL);
    imshow("circle image", circleImage);

    //Draw an ellipse over image
    Mat ellipseImage = inputImage.clone();
    ellipse(ellipseImage, Point(750, 300), Size(200, 250), 45, 0, 360, Scalar(0, 0, 255), 1, 8);
    ellipse(ellipseImage, Point(750, 300), Size(200, 250), 135, 0, 360, Scalar(0, 0, 255), 1, 8);
    imwrite("ellipse_image.jpg", ellipseImage);
    //create window and show ellipse drawn image
    namedWindow("ellipse image", WINDOW_NORMAL);
    imshow("ellipse image", ellipseImage);

    //Draw a rectangle over image
    Mat rectangleImage = inputImage.clone();
    rectangle(rectangleImage, Point(750, 300), Point(1000, 600), Scalar(0, 0, 255), 1, 8);
    imwrite("rectangle_image.jpg", rectangleImage);
    //create window and show rectangle drawn image
    namedWindow("rectangle image", WINDOW_NORMAL);
    imshow("rectangle image", rectangleImage);

    //Draw text over image
    Mat textImage = inputImage.clone();
    putText(textImage, "Anish Vision", Point(750, 300), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);
    imwrite("text_image.jpg", textImage);
    //create window and show text drawn image
    namedWindow("text image", WINDOW_NORMAL);
    imshow("text image", textImage);

    //This will pause the program until you press any key in keyboard so that you can see the images
    waitKey(0);

    return 0;
}