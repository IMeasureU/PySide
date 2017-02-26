# PySide
This repository contains the CPython Qt bindings generated using the Shiboken generator. This fork has been modified to work with Lightning v3.0.0.

How to build for windows:
* Install QT version 4.8.7 for windows (http://download.qt-project.org/official_releases/qt/4.8/4.8.7/qt-opensource-windows-x86-vs2008-4.8.7.exe)
* Install CMake(http://www.cmake.org/cmake/resources/software.html). You may need to add CMake to your environment PATH.
* Install windows SDK v7.0 (http://www.microsoft.com/en-us/download/details.aspx?id=3138)
* Make sure Python pip and wheel is installed

* Download pyside v1.2.4 source code from PyPi (https://pypi.python.org/packages/source/P/PySide/PySide-1.2.4.tar.gz) and extract
* Replace the PySide-1.2.4\sources\pyside folder with this repo

* Switch to pyside folder
* run the following command "c:\Python27\python.exe setup.py bdist_wheel --qmake=c:\Qt\4.8.7\bin\qmake.exe", make sure the QT qmake location is correct

How to build for OSX:

* Install homebrew package manager with
"ruby -e "$(curl -fsSL https://raw.github.com/Homebrew/homebrew/go/install)"
* configure homebrew with command "brew doctor"
* Install CMake with "brew install CMake"
* Make sure XCode is installed 
* Make sure Python pip and wheel is installed

* Build QT v4.8.7:
** download QT source (https://download.qt.io/official_releases/qt/4.8/4.8.7/qt-everywhere-opensource-src-4.8.7.tar.gz)
** apply the patch to allow the build on El Capitan (https://github.com/Homebrew/formula-patches/blob/master/qt/el-capitan.patch)
** configure by running "./configure -no-webkit"  (as well as any other modules that is preventing the build and is not needed" 
** "make J4" (replace 4 by twice the number of cores you have)
** "sudo make install"

* Download pyside v1.2.4 source code from PyPi (https://pypi.python.org/packages/source/P/PySide/PySide-1.2.4.tar.gz) and extract
* Replace the PySide-1.2.4\sources\pyside folder with this repo

* Switch to pyside folder
* run the following command "python setup.py bdist_wheel --qmake=PATH_TO_QT\qmake.exe", make sure the QT qmake location is correct

