
test_flags() {
    test_number=1
    echo " "
    echo "Flags: $flag:"
    for test_file in "../tests/1.txt" "../tests/2.txt" "../tests/3.txt" "../tests/examples.txt" "../tests/test.txt" "../tests/test2.txt"; do
        if [ -f "$test_file" ]; then
            ./s21_cat $flag $test_file > 1.txt
            cat $flag $test_file > 2.txt
            if ! cmp -s 1.txt 2.txt; then
                echo "Test $test_number: Fail"
            else
                echo "Test $test_number: Success"
            fi
            rm 1.txt 2.txt
        else
            echo "Test $test_number: File $test_file does not exist"
        fi
        test_number=$(( $test_number + 1 ))
    done
}

for flag in "-b" "-e" "-n" "-s" "-t" "-v"; do
    test_flags
done

echo " "
