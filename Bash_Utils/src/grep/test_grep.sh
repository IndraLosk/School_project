run_tests_flags() { 
    local flag=$1 
    local pattern=$2 
    local test_number=1 
    echo " " 
    echo "Flags: $flag" 
 
    for test_file in "../tests/1.txt" "../tests/2.txt" "../tests/3.txt" "../tests/examples.txt" "../tests/test2.txt" "../tests/test.txt"; do 
        
            ./s21_grep $flag $pattern "$test_file" > 1.txt
            grep $flag $pattern "$test_file" > 2.txt 
 
            if ! cmp -s 1.txt 2.txt; then 
                echo -e "Test $test_number: \033[0;31mFail\033[0m" 
            else 
                echo -e "Test $test_number: \033[0;32mSuccess\033[0m" 
            fi 

            rm 1.txt 2.txt
 
        test_number=$((test_number + 1)) 
    done 
} 

for flag in "-e" "-i" "-v" "-c" "-l" "-n" "-h" "-s" "-o" "-ie" "-ve" "-se" "-oe" "-iv" "-vi" "-ic" "-ci" "-il" "-li" "-in" "-ni" "-ih" "-hi" "-is" "-si" "-io" "-oi" "-vc" "-cv" "-vl" "-lv" "-vn" "-nv" "-vh" "-hv" "-vs" "-sv" "-vo" "-ov" "-cl" "-lc" "-cn" "-nc" "-ch" "-hc" "-cs" "-sc" "-co" "-oc" "-ln" "-nl" "-lh" "-hl" "-ls" "-sl" "-lo" "-ol" "-nh" "-hn" "-ns" "-sn" "-no" "-on" "-hs" "-sh" "-ho" "-oh" "-so" "-os"; do 
    run_tests_flags "$flag" "ff" "../tests/patterns.txt"
done 

for flag_f in "-f" "-ef" "-fe" "-if" "-fi" "-vf" "-fv" "-cf" "-fc" "-lf" "-fl" "-nf" "-fn" "-hf" "-fh" "-sf" "-fs" "-of" "-fo"; do 
    run_tests_flags "$flag_f" "../tests/patterns.txt" 
done 

for flag_e in "-ei" "-ev" "-ec" "-el" "-en" "-eh" "-es" "-eo"; do 
    run_tests_flags "$flag_e" "" "../tests/patterns.txt"
done 
 
echo " "