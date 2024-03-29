#!/usr/bin/env bash
# Use `wsl -d Debian` to run on windows. Use `wsl -l` to see what you can run.

# echo all of the student*_in.txt file paths in the directory tree.
find_tests() {
    local curr_pwd="$1";
    for test_path in "$curr_pwd"/*; do
        if [[ "$test_path" == */student*_in.txt ]]; then
            echo "$test_path";
        fi;
        if [[ "$test_path" != */. ]] && [[ -d "$test_path" ]]; then
            find_tests "$test_path";
        fi;
    done;
}

run_test() {
    local test_path="$2";
    # Trimming empty lines does not work, and unifying CRLF new lines to LF.
    local actual_out=$(cat "$test_path" | "$1" | sed 's/\r$//' | sed -e '/./,$!d' -e :a -e '/^\n*$/{$d;N;ba' -e '}')

    local out_path=$( echo "$test_path" | sed -e 's/_in\.txt$/_out1\.txt/g' );
    # Override out files.
    #echo "$actual_out" > $out_path;
    if [[ ! -f "$out_path" ]]; then
        # Add missing out files.
        #echo "$actual_out" > $out_path;
        >&2 echo -e "Could not run tests - out for test file \"$test_path\" -\n\"$out_path\" not found.";
        return 2;
    fi;
    # Trimming empty lines does not work, and unifying CRLF new lines to LF.
    local test_out=$(cat "$out_path" | sed 's/\r$//' | sed -e '/./,$!d' -e :a -e '/^\n*$/{$d;N;ba' -e '}');

    if [[ "$actual_out" != "$test_out" ]]; then
        >&2 echo -e "Test \"$test_path\" - FAILED."
        >&2 echo -e "Expected:\n$test_out";
        >&2 echo -e "\nActual:\n$actual_out";
        >&2 echo -e "\nDiff:\n$( diff <(echo "$test_out") <(echo "$actual_out") )";
        return 1;
    fi;
    echo "Test \"$test_path\" - PASSED."
}

compile_c_file() {
    local c_file_path="${1:-"./main.c"}";
    local c_file_dirname="$(dirname $c_file_path)";
    local c_file_name="$(basename -- $c_file_path)";
    local c_file_out_name="${c_file_name%.*}"
    mkdir -p "$c_file_dirname/.out/";
    /usr/bin/gcc -fdiagnostics-color=always -std=c99 -g "$c_file_path" -o "$c_file_dirname/.out/$c_file_out_name" -lm;
    echo "$c_file_dirname/.out/$c_file_out_name";
}

# iterate over the test input paths in the tree and print the matching out files
# Get the path of the .c file and the path of the tests directory.
main() {
    if [[ "$1" == "" ]]; then
        >&2 echo "Could not run tests - exec file parameter missing.";
        return 1;
    fi;
    if [[ ! -f "$1" ]]; then
        >&2 echo "Could not run tests - exec file \"$1\" is not a file.";
        return 1;
    fi;
    local executable=$(compile_c_file "$1");

    local test_count=0;
    local success_count=0;
    for test_path in $(find_tests "${2:-$(pwd)}"); do
        test_count=$(($test_count+1));
        run_test "$executable" "$test_path" && success_count=$(($success_count+1));
        echo;
    done;

    echo "$success_count out of $test_count passed.";
}

main "$@";
return $?;
