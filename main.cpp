#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>


template<typename T>
class MessageBox {
private:
    T* messages;
    int mySize;
    int count;

public:
    MessageBox(int numEntries) : mySize(numEntries), count(0) {
        messages = new T[mySize];
    }

    ~MessageBox() {
        delete[] messages;
    }

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

    bool empty() const {
        return count == 0;
    }

    int getSize() const {
        return mySize;
    }

    int getCount() const {
        return count;
    }

    void print() const {
        for (int i = 0; i < mySize; i++) {
            std::cout << messages[i] << " ";
        }
        std::cout << std::endl;
    }

    std::string toString() const {
        std::string result;
        for (int i = 0; i < mySize; i++) {
            std::stringstream ss;
            ss << messages[i];
            result += ss.str() + " ";
        }
        return result;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const MessageBox<T>& messageBox) {
    os << messageBox.toString();
    return os;
}

int main() {
    MessageBox<std::string> stringMessageBox(5);
    MessageBox<int> intMessageBox(5);
    MessageBox<float> floatMessageBox(5);

    try {
        stringMessageBox.send(0, "Hello");
        stringMessageBox.send(1, "World");
        stringMessageBox.send(2, "Goodbye");
        stringMessageBox.send(3, "Cruel");
        stringMessageBox.send(4, "World");

        intMessageBox.send(0, 1);
        intMessageBox.send(1, 2);
        intMessageBox.send(2, 3);
        intMessageBox.send(3, 4);
        intMessageBox.send(4, 5);

        floatMessageBox.send(0, 1.1f);
        floatMessageBox.send(1, 2.2f);
        floatMessageBox.send(2, 3.3f);
        floatMessageBox.send(3, 4.4f);
        floatMessageBox.send(4, 5.5f);

        std::cout << "String MessageBox: " << stringMessageBox << std::endl;
        std::cout << "Int MessageBox: " << intMessageBox << std::endl;
        std::cout << "Float MessageBox: " << floatMessageBox << std::endl;

        std::cout << "String MessageBox size: " << stringMessageBox.getCount() << std::endl;
        std::cout << "Int MessageBox size: " << intMessageBox.getCount() << std::endl;
        std::cout << "Float MessageBox size: " << floatMessageBox.getCount() << std::endl;

        std::cout << "String MessageBox is empty: " << (stringMessageBox.empty() ? "true" : "false") << std::endl;
        std::cout << "Int MessageBox is empty: " << (intMessageBox.empty() ? "true" : "false") << std::endl;
        std::cout << "Float MessageBox is empty: " << (floatMessageBox.empty() ? "true" : "false") << std::endl;

        std::cout << "Received message from String MessageBox: " << stringMessageBox.receive(2) << std::endl;
        std::cout << "Received message from Int MessageBox: " << intMessageBox.receive(3) << std::endl;
        std::cout << "Received message from Float MessageBox: " << floatMessageBox.receive(4) << std::endl;

        std::cout << "String MessageBox: " << stringMessageBox << std::endl;
        std::cout << "Int MessageBox: " << intMessageBox << std::endl;
        std::cout << "Float MessageBox: " << floatMessageBox << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
