#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
    // Load the pre-trained Haar Cascade XML classifier
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("./haarcascade_frontalface_default.xml")) {
        std::cerr << "Error loading face cascade file!" << std::endl;
        return -1;
    }

    // Load an image from file
    cv::Mat image = cv::imread("test.jpg");
    if (image.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    }

    // Convert the image to grayscale
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

    // Detect faces in the image
    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(image, faces, 1.1, 3, 0, cv::Size());
    // Draw rectangles around detected faces
    for (size_t i = 0; i < faces.size(); i++) {
        cv::rectangle(image, faces[i], cv::Scalar(255, 137, 0), 2);
    }

    // Display the result
    cv::imshow("Detected Faces", image);
    cv::waitKey(0);

    return 0;
}