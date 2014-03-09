#!/bin/bash

set -e
set -o pipefail

APP_DIR=`dirname $0`
MOD_DIR=`cd $APP_DIR/..; pwd`

BIN=$MOD_DIR/bin
CONF=$MOD_DIR/conf
COMMON=$MOD_DIR/common

#source $CONF/conf.sh


make clean
make


NUMBER=1200000

#time ./P1 $NUMBER > /dev/null
time ./P2 $NUMBER > /dev/null
time ./P3 $NUMBER > /dev/null
time ./P4 $NUMBER > /dev/null
time ./P5 $NUMBER > /dev/null
