/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: Michelle Talley
* @course: Data Structures (CSCI 2320)
*
* @file main.cpp
* @brief Driver program for MessageBox demonstration program.
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
    MessageBox<int> intMessageBox(7);
    MessageBox<float> floatMessageBox(7);

    try
    {
        std::cout << std::endl
                  << "Testing send() method." << std::endl;
        stringMessageBox.send(0, "Hello");
        stringMessageBox.send(1, "World");
        stringMessageBox.send(2, "Goodbye");
        stringMessageBox.send(3, "Cruel");
        stringMessageBox.send(6, "World");

        intMessageBox.send(0, 1);
        intMessageBox.send(1, 2);
        intMessageBox.send(2, 0);
        intMessageBox.send(3, 4);
        intMessageBox.send(5, 5);

        floatMessageBox.send(0, 1.1);
        floatMessageBox.send(1, 2.2);
        floatMessageBox.send(2, 0.0);
        floatMessageBox.send(3, 4.4);
        floatMessageBox.send(6, 5.5);

        std::cout << std::endl
                  << "Testing toString() method and operator overloading."
                  << std::endl;
        std::cout << "String MessageBox: " << stringMessageBox << std::endl;
        std::cout << "Int MessageBox: " << intMessageBox << std::endl;
        std::cout << "Float MessageBox: " << floatMessageBox << std::endl;

        std::cout << std::endl
                  << "Testing print() method." << std::endl;
        std::cout << "String MessageBox: ";
        stringMessageBox.print();
        stringMessageBox.print_verbose();

        std::cout << "Int MessageBox: ";
        intMessageBox.print();
        intMessageBox.print_verbose();
        std::cout << "Float MessageBox: ";
        floatMessageBox.print();
        floatMessageBox.print_verbose();

        std::cout << std::endl
                  << "Testing message count and empty methods."
                  << std::endl;
        std::cout << "String MessageBox count: "
                  << stringMessageBox.getCount() << std::endl;
        std::cout << "Int MessageBox count: "
                  << intMessageBox.getCount() << std::endl;
        std::cout << "Float MessageBox count: "
                  << floatMessageBox.getCount() << std::endl;

        std::cout << "String MessageBox is empty: "
                  << (stringMessageBox.empty() ? "true" : "false")
                  << std::endl;
        std::cout << "Int MessageBox is empty: "
                  << (intMessageBox.empty() ? "true" : "false")
                  << std::endl;
        std::cout << "Float MessageBox is empty: "
                  << (floatMessageBox.empty() ? "true" : "false")
                  << std::endl;

        std::cout << "String MessageBox position 5 is empty: "
                  << (stringMessageBox.empty(5) ? "true" : "false")
                  << std::endl;
        std::cout << "Int MessageBox position 5 is empty: "
                  << (intMessageBox.empty(5) ? "true" : "false")
                  << std::endl;
        std::cout << "Float MessageBox position 5 is empty: "
                  << (floatMessageBox.empty(5) ? "true" : "false")
                  << std::endl;

        std::cout << std::endl
                  << "Testing receive() method." << std::endl;
        std::cout << "Received message from String MessageBox: "
                  << stringMessageBox.receive(2) << std::endl;
        std::cout << "Received message from Int MessageBox: "
                  << intMessageBox.receive(3) << std::endl;
        std::cout << "Received message from Float MessageBox: "
                  << floatMessageBox.receive(3) << std::endl;

        std::cout << "String MessageBox: "
                  << stringMessageBox
                  << std::endl;
        std::cout << "Int MessageBox: "
                  << intMessageBox
                  << std::endl;
        std::cout << "Float MessageBox: "
                  << floatMessageBox
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception occurred: " 
                  << e.what() 
                  << std::endl;
    }

    // Expected exceptions
    try
    {
        std::cout << "Testing send: out of bounds exception." << std::endl;
        stringMessageBox.send(7, "Hello"); 
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Expected exception: " 
                  << e.what() << std::endl;
    }    
    catch (const std::exception& e)
    {
        std::cout << "!!!Unexpected exception occurred: " 
                  << e.what() 
                  << std::endl;
    }

    // Expected exceptions
    try
    {
        std::cout << "Testing full message box location." << std::endl;
        stringMessageBox.send(0, "Howdy");      
    }
    catch(const std::runtime_error& e)
    {
        std::cout << "Expected exception: " 
                  << e.what() << std::endl;
    }    
    catch (const std::exception& e)
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
    catch(const std::out_of_range& e)
    {
        std::cout << "Expected exception: " 
                  << e.what() << std::endl;
    }    
    catch (const std::exception& e)
    {
        std::cout << "!!!Unexpected exception occurred: " 
                  << e.what() 
                  << std::endl;
    }

    return 0;
}
