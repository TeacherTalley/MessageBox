#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "MessageBox.h"

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

        std::cout << "Testing toString() method and operator overloading." << std::endl;
        std::cout << "String MessageBox: " << stringMessageBox << std::endl;
        std::cout << "Int MessageBox: " << intMessageBox << std::endl;
        std::cout << "Float MessageBox: " << floatMessageBox << std::endl;

        std::cout << "Testing print() method." << std::endl;
        std::cout << "String MessageBox: ";
        stringMessageBox.print();
        std::cout << "Int MessageBox: ";
        intMessageBox.print();
        std::cout << "Float MessageBox: ";
        floatMessageBox.print();

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
