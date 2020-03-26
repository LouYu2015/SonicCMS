#!/bin/bash -e

cd $WORK

# setup extra python libs
NEWPY2PATH=$LOCAL/lib/python2.7/site-packages
mkdir -p $NEWPY2PATH
# need --ignore-installed or it tries to uninstall cvmfs packages
pip install --prefix $LOCAL --no-cache-dir --ignore-installed wheel setuptools grpcio-tools
export PYTHON27PATH=$NEWPY2PATH:$PYTHON27PATH

# to get cmake
export PATH=/cvmfs/sft.cern.ch/lcg/contrib/CMake/3.7.0/Linux-x86_64/bin/:${PATH}

# some really bad ways to get info out of scram
PYTHON_LIBDIR=$(scram tool info python | grep "LIBDIR=" | sed 's/LIBDIR=//')
PYTHON_INCLUDE=$(scram tool info python | grep "INCLUDE=" | sed 's/INCLUDE=//')
