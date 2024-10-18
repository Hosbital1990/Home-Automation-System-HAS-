
/**
 * @file main.cpp
 * @author Hossein Bitalebi (hosseinbitalebi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <fstream>
#include <sstream>
#include <sqlite3.h>
#include "central_manager.h"

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include <QPushButton>
#include <QApplication>


bool return_value;

/**
 * @brief main() function
 * @author Hosbital
 * 
 */
int main(int argc, char *argv[]) {

 
    

try
{
    /* code */

    CentralManager centralManager("Hosbita", "*******", 891412313);
    centralManager.start_point();  /**<@param some case need to find! */

}
catch(const std::exception& e) 
{
    std::cerr << e.what() << '\n';
}

    try {
        // Keep the main thread running to let the sensor thread do its work
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get(); // Wait for user input to keep the program running
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

            return 0;
     
     }
