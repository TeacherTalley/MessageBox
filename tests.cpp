/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <student name>
* @course: Data Structures (CSCI 2320)
*
* @file tests.cpp
* @brief Student testing code outside of the required main.cpp.
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "MessageBox.h"

int main()
{
    MessageBox<std::string> stringMessageBox(7);
 
    // Expected exceptions
    try
    {
        std::cout << "Testing send: out of bounds exception." << std::endl;
        stringMessageBox.send(7, "Hello");
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Expected exception: "
                  << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "!!!Unexpected exception occurred: "
                  << e.what()
                  << std::endl;
    }

    // Expected exceptions
    try
    {
        std::cout << "Testing full message box location." << std::endl;
        stringMessageBox.send(0, "Hello");
        stringMessageBox.send(0, "Howdy");
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Expected exception: "
                  << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "!!!Unexpected exception occurred: "
                  << e.what()
                  << std::endl;
    }

    try
    {
        std::cout << "Testing empty: out of bounds exception." << std::endl;
        stringMessageBox.empty(7);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Expected exception: "
                  << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "!!!Unexpected exception occurred: "
                  << e.what()
                  << std::endl;
    }

    return 0;
}
