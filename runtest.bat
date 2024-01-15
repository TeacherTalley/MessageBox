echo "######################## START: TEST RESULTS #########################"
echo
echo "--- Checking code format (cpplint) ---"
cpplint --filter=-legal/copyright,-whitespace/braces,-runtime/explicit,-whitespace/newline,-whitespace/end_of_line *.cpp *.h
echo
echo "--- Building program ---"
cmake -S . -B build
cmake --build build
cd build
echo
echo "--- Checking main output (diff) ---"
./main > test_main_output.txt
diff ../main_output.txt test_main_output.txt
echo
echo "--- Unit testing (googletest) ---"
ctest
cd ..
echo "######################## END:   TEST RESULTS #########################"
