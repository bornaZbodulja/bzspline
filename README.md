# Bzspline
Simple C++ library that implements Bezier and B Spline.

## How to build
* Make sure you have [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) library installed on your computer
* Clone the repository:
```
$ git clone https://github.com/bornaZbodulja/bzspline.git 
```
* Build the library:
```
$ mkdir build && cd build && cmake.. && make
```
* To also build unit tests use:
```
$ mkdir build && cd build && cmake cmake -DBUILD_TESTING=ON .. && make
```

## Improvements list
* Add visualizations
* Improve unit tests
* Add conan package manager
