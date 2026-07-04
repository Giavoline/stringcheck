#!/bin/sh

PROGRAM=./stringcheck

pass=0
fail=0

run_test() {
    expected_status="$1"
    expected_output="$2"
    shift 2

    output=$($PROGRAM "$@" 2>&1)
    status=$?

    if [ "$status" -eq "$expected_status" ] &&
       [ "$output" = "$expected_output" ]; then
        echo "PASS: $*"
        pass=$((pass + 1))
    else
        echo "FAIL: $*"
        echo "  Expected status: $expected_status"
        echo "  Actual status:   $status"
        echo "  Expected output: $expected_output"
        echo "  Actual output:   $output"
        fail=$((fail + 1))
    fi
}

run_test 0 "MATCH" "hello" "hello"
run_test 0 "MATCH" "   hello" "hello"
run_test 0 "MATCH" "hello    world" "hello world"
run_test 0 "MATCH" "hello		world" "hello world"
run_test 1 "DIFFERENT" "hello world" "hello there"
run_test 0 "MATCH" "citta'" "città"
run_test 0 "MATCH" "perche'" "perché"
run_test 0 "MATCH" "e\`" "è"
run_test 0 "MATCH" "universita'" "università"
run_test 0 "MATCH" "cio'" "ciò"
run_test 0 "MATCH" "pero'" "però"

usage=$(./stringcheck 2>&1)
status=$?

if [ "$status" -eq 2 ]; then
    echo "PASS: usage"
    pass=$((pass + 1))
else
    echo "FAIL: usage"
    fail=$((fail + 1))
fi

echo
echo "$pass tests passed"
echo "$fail tests failed"

[ "$fail" -eq 0 ]

