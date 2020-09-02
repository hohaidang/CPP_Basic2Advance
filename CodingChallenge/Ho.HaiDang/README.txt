## Contents
 1. [Introduction](#1-introduction)
 2. [Environment](#2-environment)
 3. [Build](#3-Build)
 4. [Usage](#4-usage)
 5. [Others](#5-others)


## 1. Introduction
This program used to get a largest elements sub-array in an input .txt file using heap data structure. There are 2 program:
1. FilterID.cpp this program using heap data structure self-implemented
2. FilterID_uselib.cpp this program using PriorityQueue is implemented on STL library. It's also using the idea of heap data structure.

Note:
- Assume the data input is only within int (32-bit) range -2,147,483,648 to 2,147,483,647
- Assume the data input format is absolutely correct 
<unique record identifier><white_space><numeric value>

## 2.Environment

1. Linux:
	Ubuntu Linux 16.04
	g++ version 9.3.0

2. Window:
	Window 10
	MinGW g++ version 9.2.0


## 3. Build

1. Linux:

	$g++ FilterID.cpp -o FilterID

	or

	$g++ FilterID_uselib.cpp -o FilterID_uselib

2. Windows:
	
	C:\MinGW\bin\g++ FilterID.cpp -o FilterID

	or

	C:\MinGW\bin\g++ FilterID_uselib.cpp -o FilterID_uselib

## 4.Usage
Using command line to run the programs:
Format: <Program Name> <File Input Path> <Number of Output>

1. Linux:

	$./FilterID test.txt 3

	or

	$./FilterID_uselib test.txt 3

2. Windows:

	FilterID.exe test.txt 3

	or

	FilterID_uselib.exe test.txt 3

## 5. Others
- I provide GenTestFile.cpp program to generate extremely large file input data.
- I provide document of testing. Please check TestResult.xls file for more details.