# Build

# default benchmark build is debug

$ cd benchmark 

# or build with Release 

$ cmake . -DCMAKE_BUILD_TYPE=Release 

$ cmake .

$ cmake --build .

## Generate Report

reference: https://github.com/lakshayg/google_benchmark_plot

Linux:

Work for python 2 and python 3

# Package install:

$ sudo apt-get install python

$ sudo apt-get install python-pip

$ sudo python -m pip install wheel

$ sudo python -m pip install pandas

$ sudo python -m pip install matplotlib

$ sudo apt-get install python-tk

# Using:

$ ./g_benchmark --benchmark_format=csv > benchmark.csv

$ python plot.py -f benchmark.csv
