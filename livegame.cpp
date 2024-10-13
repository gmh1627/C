#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For usleep

const int GRID_SIZE = 5;
const int STEPS = 300; // Number of steps to simulate
const int DELAY_MS = 500; // Delay in milliseconds

// Function to print the grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            std::cout << (grid[i][j] ? "O" : ".");
        }
        std::cout << std::endl;
    }
}

// Function to count the number of live neighbors
int countLiveNeighbors(const std::vector<std::vector<int>>& grid, int x, int y) {
    int liveNeighbors = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
                liveNeighbors += grid[nx][ny];
            }
        }
    }
    return liveNeighbors;
}

// Function to update the grid based on the rules of the game
void updateGrid(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> newGrid = grid;
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            if (grid[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[i][j] = 0; // Cell dies
                }
            } else {
                if (liveNeighbors == 3) {
                    newGrid[i][j] = 1; // Cell becomes alive
                }
            }
        }
    }
    grid = newGrid;
}

int main() {
    std::srand(std::time(0));

    // Initialize the grid with random states
    std::vector<std::vector<int>> grid(GRID_SIZE, std::vector<int>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }

    // Simulate the game for a number of steps
    for (int step = 0; step < STEPS; ++step) {
        std::cout << step + 1 << ":" << std::endl;
        printGrid(grid);
        updateGrid(grid);
        std::cout << std::endl;
        usleep(DELAY_MS * 1000); // Add delay in microseconds
    }

    return 0;
}