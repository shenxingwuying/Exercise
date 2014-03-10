#!/bin/bash

set -e
set -o pipefail

APP_DIR=`dirname $0`
MOD_DIR=`cd $APP_DIR/..; pwd`

BIN=$MOD_DIR/bin
CONF=$MOD_DIR/conf
COMMON=$MOD_DIR/common

make clean
make

NUMBER=1200000
