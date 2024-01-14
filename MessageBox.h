/**
 * @file MessageBox.h
 * @brief Declaration of the MessageBox class and its methods.
 */

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
class MessageBox {
private:
    T* messages; /**< Array to store the messages. */
    int mySize; /**< Size of the message box. */
    int count; /**< Number of messages in the message box. */

public:
    /**
     * @brief Constructor for the MessageBox class.
     * @param numEntries The size of the message box (default: DEFAULT_SIZE).
     */
    MessageBox(int numEntries=DEFAULT_SIZE) : mySize(numEntries), count(0) {
        messages = new T[mySize];
        for (int i = 0; i < mySize; i++) messages[i] = T();
    }

    /**
     * @brief Destructor for the MessageBox class.
     */
    ~MessageBox() {
        delete[] messages;
    }

    /**
     * @brief Sends a message to a specific position in the message box.
     * @param index The position in the message box.
     * @param message The message to be sent.
     * @throw std::out_of_range If the index is out of bounds.
     * @throw std::runtime_error If the message box position is already full.
     */
    void send(int index, const T& message) {
        if (index < 0 || index >= mySize) {
            throw std::out_of_range("Index out of bounds");
        }

        if (messages[index] != T()) {
            throw std::runtime_error("Message box position is full");
        }

        messages[index] = message;
        count++;
    }

    /**
     * @brief Receives a message from a specific position in the message box.
     * @param index The position in the message box.
     * @return The received message.
     * @throw std::out_of_range If the index is out of bounds.
     * @throw std::runtime_error If the message box position is empty.
     */
    T receive(int index) {
        if (index < 0 || index >= mySize) {
            throw std::out_of_range("Index out of bounds");
        }

        if (messages[index] == T()) {
            throw std::runtime_error("Message box position is empty");
        }

        T message = messages[index];
        messages[index] = T();
        count--;

        return message;
    }

    /**
     * @brief Checks if the message box is empty.
     * @return True if the message box is empty, false otherwise.
     */
    bool empty() const {
        return count == 0;
    }

    /**
     * @brief Gets the size of the message box.
     * @return The size of the message box.
     */
    int getSize() const {
        return mySize;
    }

    /**
     * @brief Gets the number of messages in the message box.
     * @return The number of messages in the message box.
     */
    int getCount() const {
        return count;
    }

    /**
     * @brief Converts the message box to a string representation.
     * @return The string representation of the message box.
     */
    std::string toString() const {
        std::string result;
        int printed_count = 0;
        for (int i = 0; i < mySize; i++) {
            if (messages[i] != T()) {
                std::stringstream ss;
                ss << messages[i];
                printed_count++;
                if (printed_count == count) result += ss.str();
                else result += ss.str() + " ";
            }
        }
        return result;
    }

    /**
     * @brief Prints the message box.
     */
    void print() const {
        std::string result;
        result = toString();
        std::cout << result << std::endl;
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
std::ostream& operator<<(std::ostream& os, const MessageBox<T>& messageBox) {
    os << messageBox.toString();
    return os;
}
