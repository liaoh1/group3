# group3
This teamwork documentation is created for developing a given software, from cloning an existing repositoty of gray-scott-simulator to implementing a testing framework. This also involves collaboraively building system and continuous integration of this code repository.


# Clone Repository
https://github.com/scicomp-durham/gray-scott-sim

# Testing FrameWork

https://github.com/google/googletest/blob/main/googletest/README.md

#### Install 
```````git clone https://github.com/google/googletest.git -b v1.14.0  <br>
cd googletest        # Main directory of the cloned repository. <br>
mkdir build          # Create a directory to hold the build output. <br>
cd build <br>
cmake ..             # Generate native build scripts for GoogleTest.` <br>
cmake -Dgtest_build_tests=on -DCMAKE_INSTALL_PREFIX=. ..
make; make install
```````



#### Configure

```find / -name "gtest.h" 2>/dev/null ```

#### Compile the object file 
under group 3 working directory 

```
g++ -std=c++14 gs.cpp -I/Users/...../group3/googletest/build/include -L//Users/..../group3/googletest/build/lib -lgtest -lgtest_main -pthread -o us
```

#### Run the Test
```
./us```
#### To Do
(0.0) Inside Main Function
```::testing::InitGoogleTest(&argc,argv);
return RUN_ALL_TESTS();```
    

(0.1) Check that the type of the model parameters (F , k) matches that of the element type
of the u and v vectors.

`code`

(0.2) Check that the variables u and v are the same size. (0.3) Check that the simulation produces the mathematically correct answer when u = 0 and
v = 0.

`code`

(0.3) Check that the simulation produces the mathematically correct answer when u = 0 and
v = 0.

`code`



# Create a build system for the software 

#### To Do

Clear build instructions in a correct, concise format.



# Implement continuous integration (CI) for your repository.




