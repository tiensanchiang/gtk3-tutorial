#!/usr/bin/env bash

function usage(){
    echo "Usage: ./build.sh m|b [options..]"
}

if [ $# -le 0 ] ; then
    usage
    exit 1
fi

command="$1"
shift

if [ $command == "m" ]; then
    cmake -H. -Btarget -G "MSYS Makefiles" $*
elif [ $command == "mu" ]; then
    cmake -H. -Btarget -G "Unix Makefiles" $*
elif [ $command == "b" ]; then
    cmake --build ./target $*
else
    usage
    exit 1
fi


