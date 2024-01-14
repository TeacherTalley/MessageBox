#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "MessageBox.h"

// Include the MessageBox class here

TEST(MessageBoxTest, SendAndReceive) {
    // Test sending and receiving messages
    MessageBox<std::string> stringBox(5);
    stringBox.send(0, "Hello");
    stringBox.send(1, "World");
    stringBox.send(2, "!");
    EXPECT_EQ(stringBox.receive(0), "Hello");
    EXPECT_EQ(stringBox.receive(1), "World");
    EXPECT_EQ(stringBox.receive(2), "!");

    MessageBox<int> intBox(3);
    intBox.send(0, 10);
    intBox.send(1, 20);
    EXPECT_EQ(intBox.receive(0), 10);
    EXPECT_EQ(intBox.receive(1), 20);

    MessageBox<float> floatBox(4);
    floatBox.send(0, 3.14f);
    floatBox.send(1, 2.718f);
    floatBox.send(2, 1.618f);
    floatBox.send(3, 0.577f);
    EXPECT_EQ(floatBox.receive(0), 3.14f);
    EXPECT_EQ(floatBox.receive(1), 2.718f);
    EXPECT_EQ(floatBox.receive(2), 1.618f);
    EXPECT_EQ(floatBox.receive(3), 0.577f);
}

TEST(MessageBoxTest, OutOfRange) {
    // Test out of range index
    MessageBox<std::string> stringBox(2);
    EXPECT_THROW(stringBox.send(2, "Hello"), std::out_of_range);
    EXPECT_THROW(stringBox.receive(2), std::out_of_range);

    MessageBox<int> intBox(1);
    EXPECT_THROW(intBox.send(1, 10), std::out_of_range);
    EXPECT_THROW(intBox.receive(1), std::out_of_range);
}

TEST(MessageBoxTest, FullAndEmpty) {
    // Test full and empty message boxes
    MessageBox<std::string> stringBox(2);
    EXPECT_TRUE(stringBox.empty());
    stringBox.send(0, "Hello");
    EXPECT_FALSE(stringBox.empty());
    stringBox.send(1, "World");
    //EXPECT_TRUE(stringBox.full());
    stringBox.receive(0);
    //EXPECT_FALSE(stringBox.full());
    stringBox.receive(1);
    EXPECT_TRUE(stringBox.empty());

    MessageBox<int> intBox(1);
    EXPECT_TRUE(intBox.empty());
    intBox.send(0, 10);
    EXPECT_FALSE(intBox.empty());
    intBox.receive(0);
    EXPECT_TRUE(intBox.empty());
}

TEST(MessageBoxTest, CountAndSize) {
    // Test count and size of message box
    MessageBox<std::string> stringBox(3);
    EXPECT_EQ(stringBox.getSize(), 3);
    EXPECT_EQ(stringBox.getCount(), 0);
    stringBox.send(0, "Hello");
    EXPECT_EQ(stringBox.getCount(), 1);
    stringBox.send(1, "World");
    EXPECT_EQ(stringBox.getCount(), 2);
    stringBox.send(2, "!");
    EXPECT_EQ(stringBox.getCount(), 3);

    MessageBox<int> intBox(2);
    EXPECT_EQ(intBox.getSize(), 2);
    EXPECT_EQ(intBox.getCount(), 0);
    intBox.send(0, 10);
    EXPECT_EQ(intBox.getCount(), 1);
    intBox.send(1, 20);
    EXPECT_EQ(intBox.getCount(), 2);
}

TEST(MessageBoxTest, Print) {
    // Test printing the message box
    MessageBox<std::string> stringBox(3);
    stringBox.send(0, "Hello");
    stringBox.send(1, "World");
    stringBox.send(2, "!");
    testing::internal::CaptureStdout();
    stringBox.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello World !\n");

    MessageBox<int> intBox(2);
    intBox.send(0, 10);
    intBox.send(1, 20);
    testing::internal::CaptureStdout();
    intBox.print();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20\n");
}

/*
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/