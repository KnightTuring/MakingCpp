#!/bin/bash
#=============================================================================
#     FileName: generate_coverage_report.sh
#         Desc: I was bored of typing the same commands over and over again, hence this file.
#       Author: Abdul Wasay
#        Email: wasaya@acm.org
#     HomePage: https://knightturing.github.io/
#      Version: 1.0
#   LastChange: 2018-10-30 14:48:07
#      History:
#=============================================================================


# This script assumes that the executable has been created AND 
# has been run at least once.
# This is because .gcda files are created after the first run.


# First, create a directory for storing .gcov files
echo "----------------Creating directory for gcov files----------------"
mkdir ../gcov_files
# now change to that directory
echo "----------------Changing to directory for gcov files----------------"
cd ../gcov_files
# now run gcov on the necessary files
echo "----------------Running gcov on the necessary files----------------"
gcov ../src/Complex.cpp ../test/src/test_main.cpp
# after this all the needed .gcov files will be available in the gcov_files directory
# now use lcov to generate an aesthetically pleasing report
echo "----------------Changing to generator_script directory----------------"
cd ../generator_script
echo "----------------Running lcov on root of directory, generating .info file----------------"
lcov --capture --directory .. --output-file main_coverage.info
echo "----------------Generating HTML pages----------------"
genhtml --output-directory ../html_output main_coverage.info
