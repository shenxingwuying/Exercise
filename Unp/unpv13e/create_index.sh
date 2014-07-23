#!/bin/bash
find . -name "*.[c|h|S|s]" -o -name "*.cpp" -o -name "*.cc" -o -name "*.java"> cscope.files
/usr/local/bin/cscope -k -b -q
/usr/local/bin/ctags -R *
