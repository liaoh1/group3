#ifndef GS_H
#define GS_H

// Define simulation parameters
extern const int width;                // Width of the grid
extern const int height;               // Height of the grid
extern double Du;                     // Diffusion rate of U
extern double Dv;                     // Diffusion rate of V
extern double F;                      // Feed rate
extern double k;                    // Kill rate
extern double threshold;
extern const double dt;               // Time step
extern const int numIterations;
extern const int outputInterval;      // Output every 1000 iterations

// Initialize grid and constants
extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);

#endif // GS_H