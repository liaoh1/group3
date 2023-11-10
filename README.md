# About the project 
The project is designed to build a project  simulating a Gray-Scott reaction-diffusion system and output the results to VTK files for visualization, plus, the project has three test funtions which are:
(0.1) Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.
(0.2) Check that the variables u and v are the same size.
(0.3) Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.


# The conditions that need to be satisfied
## GoogleTest
we already have GoogleTest in our repository, but in case there is something wrong and the clients don't have 
GoogleTest, here is the steps:
1. ```````git clone https://github.com/google/googletest.git -b v1.14.0  <br>
2. cd googletest        # Main directory of the cloned repository. <br>
3. cd build <br>
4. cmake -Dgtest_build_tests=on -DCMAKE_INSTALL_PREFIX=. ..
5. make; install make
```````

# Testing FrameWork

https://github.com/google/googletest/blob/main/googletest/README.md

#### Install 
```````git clone https://github.com/google/googletest.git -b v1.14.0  <br>
cd googletest        # Main directory of the cloned repository. <br>
mkdir build          # Create a directory to hold the build output. <br>
cd build <br>
cmake ..             # Generate native build scripts for GoogleTest.` <br>
cmake -Dgtest_build_tests=on -DCMAKE_INSTALL_PREFIX=. ..
make; install make
```````
## CMake
To run this project, you should have CMake in your local computer; in case you don't have one, here is 
the line that could help you:<br>
https://cgold.readthedocs.io/en/latest/first-step/installation.html

# How To Run
## You should have 5 files or directory at first:<br>
1. CMakeLists.txt
2. README.md
3. build(directory)
4. googletest
5. gs.cpp
## Go to build directory
1. cd build
2. cmake ..
3. make
4. ./us
## Clean up
git clean -d -f -x(this will remove all the files cmake produced)
## The expected result
You should see this if everything goes correctlt:
[==========] Running 3 tests from 3 test suites.<br>
[----------] Global test environment set-up.<br>
[----------] 1 test from TypeMatch<br>
[ RUN      ] TypeMatch.CheckTypeMatch<br>
[       OK ] TypeMatch.CheckTypeMatch (0 ms)<br>
[----------] 1 test from TypeMatch (0 ms total)<br>

[----------] 1 test from GridSizeTest<br>
[ RUN      ] GridSizeTest.SameSize<br>
[       OK ] GridSizeTest.SameSize (0 ms)<br>
[----------] 1 test from GridSizeTest (0 ms total)<br>

[----------] 1 test from SimulationTest<br>
[ RUN      ] SimulationTest.HandlesZeroInput<br>
[       OK ] SimulationTest.HandlesZeroInput (18 ms)<br>
[----------] 1 test from SimulationTest (18 ms total)<br>

[----------] Global test environment tear-down<br>
[==========] 3 tests from 3 test suites ran. (18 ms total)<br>
[  PASSED  ] 3 tests.<br>

# Participations:
1. Amber | Yi-Hua Chang @Amberisfree
2. Ziteng Xu @fnhp54
3. Yucheng Niu @cattle12
4. Jiangyue Liu @moonbro1999
5. Haichen Liao @liaoh1

# How to contact:
Here is the email that you can contact: liaohaichen9@gamil.com 
