#!/bin/bash

set -e

echo "Compiling..."
g++ ptA15_soln.cpp -o test
g++ ptA15_soln_alt.cpp -o test_alt
echo "Compiled successfully"

echo "Testing ptA15_soln..."
echo "a.txt b.txt" | ./test > test1.txt
diff test1.txt test1_ref.txt
echo "a.txt c.txt" | ./test > test2.txt
diff test2.txt test2_ref.txt
echo "c.txt c.txt" | ./test > test3.txt
diff test3.txt test3_ref.txt
echo "a.txt a.txt" | ./test > test4.txt
diff test4.txt test4_ref.txt
echo "b.txt b.txt" | ./test > test5.txt
diff test5.txt test5_ref.txt
echo "ptA15_soln passed all tests"

echo "Testing ptA15_soln_alt..."
echo "a.txt b.txt" | ./test_alt > test1.txt
diff test1.txt test1_ref.txt
echo "a.txt c.txt" | ./test_alt > test2.txt
diff test2.txt test2_ref.txt
echo "c.txt c.txt" | ./test_alt > test3.txt
diff test3.txt test3_ref.txt
echo "a.txt a.txt" | ./test_alt > test4.txt
diff test4.txt test4_ref.txt
echo "b.txt b.txt" | ./test_alt > test5.txt
diff test5.txt test5_ref.txt
echo "ptA15_soln_alt passed all tests"