#!/usr/bin/env python3
import subprocess
import os
from glob import glob
from pathlib import Path

# cd to test dir to find testcase files
abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)
actual_dir = "actual"
expect_dir = "expect"
exebin_dir = "../build/release/bin"


def run_external_routine(actual_file, exebin_file):
    with open(actual_file, "w") as f:
        subprocess.run([exebin_file], stdout=f)


def filter_lines(input):
    """
     remove out some lines, eg print of address
     <  as= assign_value<T, V>: <b*> t_=0x16af06c4f, <b> v_=true
     >  as= assign_value<T, V>: <b*> t_=0x16d7ceaaf, <b> v_=true
    """
    output = []
    for line in input:
        line = line.strip()
        if "T * t_=0x" in line:
            continue
        if line.startswith("time: "):
            continue
        if line.isspace():
            continue

        output.append(line)

    return output


def compare_output(actual_file, expect_file):
    # Compare the actual output with the expected output using pytest
    with open(actual_file, "r") as factual:
        with open(expect_file, "r") as fexpect:
            actual = factual.read().split("\n")
            expect = fexpect.read().split("\n")
            actual = filter_lines(actual)
            expect = filter_lines(expect)
            assert expect == actual


def test_compare():
    for infile in glob(f"{expect_dir}/*.log"):
        stem = Path(infile).stem
        actual_file = os.path.join(actual_dir, stem + ".log")
        expect_file = os.path.join(expect_dir, stem + ".log")
        exebin_file = os.path.join(exebin_dir, stem)
        print(f"{actual_file=} {expect_file=} {exebin_file=}")
        run_external_routine(actual_file, exebin_file)
        compare_output(actual_file, expect_file)
