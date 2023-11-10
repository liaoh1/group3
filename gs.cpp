#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <typeinfo>
#include <gtest/gtest.h>

// Define simulation parameters
const int width = 256;                // Width of the grid
const int height = 256;               // Height of the grid
double Du = 0.14;                     // Diffusion rate of U
double Dv = 0.07;                     // Diffusion rate of V
double F = 0.03;                      // Feed rate
double k = 0.0648;                    // Kill rate
double threshold = 0.1;
const double dt = 0.06;               // Time step
const int numIterations = 10000;
const int outputInterval =  100;      // Output every 1000 iterations

// Initialize grid and constants
std::vector<std::vector<double>> u(width, std::vector<double>(height, 1.0));
std::vector<std::vector<double>> v(width, std::vector<double>(height, 0.0));

// initialization function
void init() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 1.0;
            if (x >= 100 && x <= 200 && y >= 100 && y <= 150){
              v[x][y] = (std::rand() % 100 - 0) / 100.0;  // Random ~ U[0.0,1.0)
            }else{
              v[x][y] = 0.0;
            }
        }
    }
}

// Function to write the u array to a VTK file
void writeVTKFile(int iteration) {
    std::stringstream ss;
    ss << "output_" << iteration << ".vtk";

    std::ofstream vtkFile(ss.str());
    vtkFile << "# vtk DataFile Version 3.0\n";
    vtkFile << "Gray-Scott Simulation Output\n";
    vtkFile << "ASCII\n";
    vtkFile << "DATASET STRUCTURED_POINTS\n";
    vtkFile << "DIMENSIONS " << width << " " << height << " 1\n";
    vtkFile << "SPACING 1.0 1.0 1.0\n";
    vtkFile << "ORIGIN 0 0 0\n";
    vtkFile << "POINT_DATA " << width * height << "\n";
    vtkFile << "SCALARS u double\n";
    vtkFile << "LOOKUP_TABLE default\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            vtkFile << v[x][y] << " ";
        }
        vtkFile << "\n";
    }

    vtkFile.close();
}


// Function to perform one time step of the simulation
void simulateStep() {

    std::vector<std::vector<double>> nextU = u;
    std::vector<std::vector<double>> nextV = v;

    double laplaceU = 0.0, laplaceV = 0.0, dU = 0.0, dV = 0.0;
    double a, b;
    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            
            a = u[x][y];
            b = v[x][y];
            
            laplaceU = (u[x + 1][y] + u[x - 1][y] + u[x][y + 1] + u[x][y - 1] - 4 * a);
            laplaceV = (v[x + 1][y] + v[x - 1][y] + v[x][y + 1] + v[x][y - 1] - 4 * b);
            
            dU = Du * laplaceU - a * b * b + F * (1.0 - a);
            dV = Dv * laplaceV + a * b * b - (F + k) * b;
            
            nextU[x][y] = a + dt * dU;
            nextV[x][y] = b + dt * dV;
        }
    }

    u = nextU;
    v = nextV;
}

// Function to count elements above a threshold in a 2D vector
double countElementsAboveThreshold(double threshold) {
    int count = 0;
    for (const auto& row : v) {
        for (const double& element : row) {
            if (element > threshold) {
                count++;
            }
        }
    }
    return (double)(count)/(width*height);
}

TEST(TypeMatch, CheckTypeMatch) {
    // Check that the type of F and k matches the element type of u and v
    EXPECT_EQ(typeid(F), typeid(u[0][0])) << "The types of F and u are not match";
    EXPECT_EQ(typeid(k), typeid(v[0][0])) << "The types of k and v are not match";
}

TEST(GridSizeTest, SameSize) {
    bool rows = (u.size(), v.size());

    // If the number of rows is the same, check each row's size is right.
    if(rows)
    {
        for (size_t i = 0; i < u.size(); ++i) {
            EXPECT_EQ(u[i].size(), v[i].size()) << "the row" << i << "doesn't match";
        }
    }
}

TEST(SimulationTest, HandlesZeroInput) {
    const int width = 256;
    const int height = 256;
    const double dt = 0.06;
    std::vector<std::vector<double>> u, v;

    u = std::vector<std::vector<double>>(width, std::vector<double>(height, 0.0));
    v = std::vector<std::vector<double>>(width, std::vector<double>(height, 0.0));

    // Run the simulateStep
    simulateStep();

    // Check that u and v are still zero after simulateStep function called
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            EXPECT_DOUBLE_EQ(0.0, u[i][j]) << "u[" << i << "][" << j << "] is not zero.";
            EXPECT_DOUBLE_EQ(0.0, v[i][j]) << "v[" << i << "][" << j << "] is not zero.";
        }
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    // if (argc != 5){
    //     std::cout << "Usage: " << argv[0] << " <Du> <Dv> <F> <k> <threshold>" << std::endl;
    // }
    // else{
    //   Du = std::stod(argv[1]);
    //   Dv = std::stod(argv[2]);
    //   F = std::stod(argv[3]);
    //   k = std::stod(argv[4]);
    //   threshold = std::stod(argv[5]);
    // }
       
    // init();
    // std::cout << "Simulation initiated." << std::endl;

    // // Main simulation loop
    // for (int iteration = 0; iteration < numIterations; ++iteration) {
    //     simulateStep();
        
    //     // Periodically write to VTK file
    //     if (iteration % outputInterval == 0) {
    //         writeVTKFile(iteration);
    //     }
    // }

    // count the amount of pixels above threshold at end.
    // double n = countElementsAboveThreshold(threshold);
    // std::cout << "Simulation completed: P(v > threshold) = " << n << std::endl;
    return RUN_ALL_TESTS();
    // return 0;
}

// g++ -std=c++14 gs.cpp -I/Users/haichenliao/Desktop/unitTest/group3/googletest/mybuild/include -L/Users/haichenliao/Desktop/unitTest/group3/googletest/mybuild/lib -lgtest -lgtest_main -pthread -o us

