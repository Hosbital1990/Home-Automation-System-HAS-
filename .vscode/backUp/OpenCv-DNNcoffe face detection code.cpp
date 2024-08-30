#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>  // For DNN module
#include <iostream>

int main() {
    // Load the pre-trained DNN face detection model
    // Change the paths to the appropriate model files
    std::string modelFile = "./deploy.prototxt";  // Model configuration file (Caffe)
    std::string weightFile = "./res10_300x300_ssd_iter_140000.caffemodel";  // Pre-trained weights (Caffe)

    // Create a DNN face detector
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(modelFile, weightFile);

    if (net.empty()) {
        std::cerr << "Error loading DNN model!" << std::endl;
        return -1;
    }

    // Load an image from file
    cv::Mat image = cv::imread("test.jpg");
    if (image.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    }

    // Prepare the image for the DNN
    cv::Mat blob;
    cv::dnn::blobFromImage(image, blob, 1.0, cv::Size(300, 300), cv::Scalar(104.0, 177.0, 123.0), false, false);

    // Set the blob as input to the network
    net.setInput(blob);

    // Perform the forward pass to get the detections
    cv::Mat detection = net.forward();

    // Get the number of detected faces
    cv::Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

    for (int i = 0; i < detectionMat.rows; i++) {
        float confidence = detectionMat.at<float>(i, 2);  // Confidence score

        if (confidence > 0.5) {  // Confidence threshold
            int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * image.cols);
            int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * image.rows);
            int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * image.cols);
            int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * image.rows);

            // Draw a rectangle around the detected face
            cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(255, 137, 0), 2);
        }
    }

    // Display the result
    cv::imshow("Detected Faces", image);
    cv::waitKey(0);

    return 0;
}