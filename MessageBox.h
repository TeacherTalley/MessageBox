
const int DEFAULT_SIZE = 10;
// MessageBox class
template<typename T>
class MessageBox {
private:
    T* messages;
    int mySize;
    int count;

public:
    MessageBox(int numEntries=DEFAULT_SIZE) : mySize(numEntries), count(0) {
        messages = new T[mySize];
        for (int i = 0; i < mySize; i++) messages[i] = T();
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

    void print() const {
        std::string result;
        result = toString();
        std::cout << result << std::endl;
    }

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const MessageBox<T>& messageBox) {
    os << messageBox.toString();
    return os;
}
