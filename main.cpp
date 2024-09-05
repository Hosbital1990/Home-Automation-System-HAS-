

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

// Callback function for button
void button_callback(Fl_Widget* widget, void* data) {
    Fl_Box* box = (Fl_Box*)data;
    box->label("Button clicked!");
}

int main() {
    // Create a window
    Fl_Window* window = new Fl_Window(340, 180);

    // Create a button
    Fl_Button* button = new Fl_Button(120, 60, 100, 30, "Click me");
    Fl_Box* box = new Fl_Box(120, 100, 100, 30, "Hello FLTK");

    // Set button callback
    button->callback(button_callback, (void*)box);

    // End window and show it
    window->end();
    window->show();

    return Fl::run();
}



// /**
//  * @file main.cpp
//  * @author Hossein Bitalebi (hosseinbitalebi@gmail.com)
//  * @brief 
//  * @version 0.1
//  * @date 2024-09-03
//  * 
//  * @copyright Copyright (c) 2024
//  * 
//  */
// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>
// #include <future>
// #include <vector>
// #include <fstream>
// #include <sstream>
// #include <sqlite3.h>
// #include "central_manager.h"

// #include <opencv2/opencv.hpp>
// #include <opencv2/objdetect.hpp>
// #include <opencv2/imgproc.hpp>
// #include <opencv2/highgui.hpp>
// #include <iostream>



// bool return_value;

// /**
//  * @brief main() function
//  * @author Hosbital
//  * 
//  */
// int main() {

// try
// {
//     /* code */

//     CentralManager centralManager("Hosbita", "*******", 891412313);
//     centralManager.start_point();  /**<@param some case need to find! */

// }
// catch(const std::exception& e) 
// {
//     std::cerr << e.what() << '\n';
// }

//     try {
//         // Keep the main thread running to let the sensor thread do its work
//         std::cout << "Press Enter to exit..." << std::endl;
//         std::cin.get(); // Wait for user input to keep the program running
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }
