#include <typeinfo>
#include <gtest/gtest.h>
#include "gs.h"

// Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.
TEST(TypeMatch, CheckTypeMatch) {
    EXPECT_EQ(typeid(F), typeid(u[0][0])) << "The types of F and u are not match";
    EXPECT_EQ(typeid(k), typeid(v[0][0])) << "The types of k and v are not match";
}

// Check that the variables u and v are the same size
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

// Check that the simulation produces the mathematically correct answer when u = 0 and v = 0
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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

