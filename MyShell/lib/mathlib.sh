#!/bin/bash


APPDIR=`dirname $0`
MOD_DIR=`cd $APPDIR/..; pwd`

tag=$(date "+%Y%m%d%H%M%S")


function getAverage()
{
    if [ $# -eq 0 ];
    then
        echo "-1"
        exit 1
    fi

    for i in $* ;
    do
        let "avg += $i"
    done
    let "avg /= $#"
    avg=$[avg+1]
    echo "$avg"
}

function posNumber()
{
    if [ $# -eq 1 ];
    then
        echo "-1"
        exit 1
    fi

    avg=$1
    shift

    posnum=0
    for i in $* ;
    do
        t=$[i-avg]
        if [ $t -gt 0 ];
        then
            let "posnum += $t"
        fi
    done
    echo "$posnum"

}

function getVariance()
{
    if [ $# -eq 0 ];
    then
        echo "-1"
        exit 1
    fi

    for i in $*;
    do
        let "square += $i*$i"
    done

    square_avg=$(echo square | awk -v n=$# -v sum=$square '{print sum/n}')
    echo "$square_avg"
}

function doVariance()
{
    average=$1
    shift

    cursor=0
    for i in $*;
    do
        array[$cursor]=$[i-$average]
        shift
        cursor=$[cursor+1]
    done

    variance=$(getVariance ${array[@]})
    echo "$variance"
}
