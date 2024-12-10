#ifndef MESSAGEBOX_H_
#define MESSAGEBOX_H_

/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <student name>
* @course: Data Structures (CSCI 2320)
*
* @file MessageBox.h
* @brief Declaration of the MessageBox class and its methods.
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>

/**
 * @class MessageBox
 * @brief A class that represents a message box with a fixed size.
 * @tparam T The type of messages stored in the message box.
 */

/**
 * @brief Default size of the message box.
 */
const int DEFAULT_SIZE = 10;

template<typename T>
class MessageBox 
{
 private:
    T* messages; /* Array to store the messages. */
    int mySize; /* Size of the message box. */
    int count; /* Number of messages in the message box. */
    bool *emptyBox; /* Flag indicating if box currently holds a message. */

 public:
    /**
     * @brief Constructor for the MessageBox class.
     * @param numEntries The size of the message box (default: DEFAULT_SIZE).
     */
    MessageBox(int numEntries = DEFAULT_SIZE) 
    {
        mySize = numEntries;
        count = 0;
        messages = new T[mySize];
        emptyBox = new bool[mySize];
        for (int i = 0; i < mySize; i++) {
            messages[i] = T();
            emptyBox[i] = true;
        }
    }

    /**
     * @brief Destructor for the MessageBox class.
     */
    ~MessageBox() 
    {
        delete[] messages;
        delete[] emptyBox;
    }

    /**
     * @brief Sends a message to a specific position in the message box.
     * @param index The position in the message box.
     * @param message The message to be sent.
     * @throw std::out_of_range If the index is out of bounds.
     * @throw std::runtime_error If the message box position is already full.
     */
    void send(int index, const T& message) 
    {
        if (index < 0 || index >= mySize) 
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (full(index)) 
        {
            throw std::runtime_error("Message box position is full");
        }

        messages[index] = message;
        emptyBox[index] = false;
        count++;
    }

    /**
     * @brief Receives a message from a specific position in the message box.
     * @param index The position in the message box.
     * @return The received message.
     * @throw std::out_of_range If the index is out of bounds.
     * @throw std::runtime_error If the message box position is empty.
     */
    T receive(int index) 
    {
        if (index < 0 || index >= mySize) 
        {
            throw std::out_of_range("Index out of bounds");
        }

        if (empty(index)) 
        {
            throw std::runtime_error("Message box position is empty");
        }

        T message = messages[index];
        messages[index] = T();
        emptyBox[index] = true;
        count--;

        return message;
    }

    /**
     * @brief Checks if the entire message box is empty.
     * @return True if the entire message box is empty, false otherwise.
     */
    bool empty() const
    {
        return count == 0;
    }

    /**
     * @brief Checks if a specific message box is empty.
     * @param index The position in the message box.
     * @return True if a specific message box is empty, false otherwise.
     * @throw std::out_of_range If the index is out of bounds.
     */
    bool empty(int index) const
    {
        if (index < 0 || index >= mySize)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return emptyBox[index] == true;
    }

    /**
     * @brief Checks if the entire message box is full.
     * @return True if the entire message box is full, false otherwise.
     */
    bool full() const
    {
        return count == mySize;
    }

    /**
     * @brief Checks if a specific message box is empty.
     * @param index The position in the message box.
     * @return True if a specific message box is full, false otherwise.
     * @throw std::out_of_range If the index is out of bounds.
     */
    bool full(int index) const
    {
        return !empty(index);
    }

    /**
     * @brief Gets the size of the message box.
     * @return The size of the message box.
     */
    int getSize() const 
    {
        return mySize;
    }

    /**
     * @brief Gets the number of messages in the message box.
     * @return The number of messages in the message box.
     */
    int getCount() const 
    {
        return count;
    }

    /**
     * @brief Converts the message box to a string representation.
     * @return The string representation of the message box.
     */
    std::string toString() const 
    {
        std::string result;
        int printed_count = 0;
        for (int i = 0; i < mySize; i++) {
            if (!empty(i)) {
                std::stringstream ss;
                ss << messages[i];
                printed_count++;
                if (printed_count == count)
                    result += ss.str();
                else
                    result += ss.str() + " ";
            }
        }
        return result;
    }

    /**
     * @brief Prints the message box.
     */
    void print() const
    {
        std::string result;
        result = toString();
        std::cout << result << std::endl;
    }

    /**
     * @brief Prints all message boxes, including empty slots.
     */
    void print_verbose() const
    {
        std::string result;
        int printed_count = 0;
        for (int i = 0; i < mySize; i++)
        {
            if (empty(i))
            {
                result = "<empty>";
            }
            else
            {
                std::stringstream ss;
                ss << messages[i];
                result = ss.str();
            }
            std::cout << i << ":" << result << ":" << std::endl;
        }
    }
};

/**
 * @brief Overload of the output stream operator for the MessageBox class.
 * @tparam T The type of messages stored in the message box.
 * @param os The output stream.
 * @param messageBox The message box to be printed.
 * @return The output stream.
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const MessageBox<T>& messageBox) 
{
    os << messageBox.toString();
    return os;
}
#endif  // MESSAGEBOX_H_
