#!/bin/bash

falshivka="./s21_grep"
original="grep"

file_name='TEST-FILE'
file_format=".testing"

template='[0-9]'
test_file='./TEST-SUITE/TEST-FILE_001'
test_template='./TEST-SUITE/TEST-TEMPLATE'

suite_flag=(
    "-e $template -e $test_template $test_file"
    "-f $test_template -e $template $test_file"
    "-f $test_template s21_grep.c s21_grep.h"
    "-vf $test_template $test_file"
    "-cf $test_template $test_file"
    "-lf $test_template $test_file"
    "-nf $test_template $test_file"
    "-hf $test_template $test_file"
    "-h if $test_file s21_grep.h"
    "-ie $template $test_file"
    "-ve $template $test_file"
    "-ce $template $test_file"
    "-le $template $test_file"
    "-ne $template $test_file"
    "-he $template $test_file"
    "-se $template $test_file"
    "-oe $template $test_file"
    "-iv $template $test_file"
    "-ic $template $test_file"
    "-il $template $test_file"
    "-in $template $test_file"
    "-ih $template $test_file"
    "-is $template $test_file"
    "-io $template $test_file"
    "-vc $template $test_file"
    "-vl $template $test_file"
    "-vn $template $test_file"
    "-vh $template $test_file"
    "-vs $template $test_file"
    "-vo $template $test_file"
    "-cl $template $test_file"
    "-cn $template $test_file"
    "-ch $template $test_file"
    "-cs $template $test_file"
    "-co $template $test_file"
    "-ln $template $test_file"
    "-lh $template $test_file"
    "-ls $template $test_file"
    "-lo $template $test_file"
    "-nh $template $test_file"
    "-ns $template $test_file"
    "-no $template $test_file"
    "-hs $template $test_file"
    "-ho $template $test_file"
    "-l $template $test_file"
    "-v $template $test_file"
    "-c $template $test_file"
    "-n $template $test_file"
    "-o $template $test_file"
    "[0-9] $test_file"
    "-i RY $test_file"
)

file_comparison() {
    diff_output=$(diff -u "$1" "$2")
    if [ "$?" -ne 0 ]; then
        line=$(echo "$diff_output" | grep -n '^-' | head -n 1 | cut -d ':' -f 1)
        char=$(echo "$diff_output" | grep -n '^-' | head -n 1 | awk '{print length($0)}')
        echo "===============A==============="
        echo "$diff_output" | head -n "$line"
        echo "===============B==============="
        echo "$diff_output" | tail -n +$((line+1))
        echo "==============================="
        echo "Line: $line, char: $char"
        read -p "Press any key to continue:" -n1 -s
    else
        echo -e "\033[42m\033[1m YES \033[0m"
    fi
}

for index in "${!suite_flag[@]}"; do
    echo -n "Current TEST [$(($index + 1)) / ${#suite_flag[@]}] - ${suite_flag[$index]} - "
    eval "$falshivka ${suite_flag[$index]} > ${file_name}-0${file_format}"
    eval "$original ${suite_flag[$index]} > ${file_name}-1${file_format}"
    file_comparison "${file_name}-0${file_format}" "${file_name}-1${file_format}"
done

rm -rf *"${file_format}"
