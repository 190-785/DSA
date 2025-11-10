#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip> // For debugging
#include <map>

using namespace std;

/**
 * @struct Slide
 * @brief Represents a single diagonal slide in the 2D grid.
 *
 * Stores the start and end coordinates, the slope (m), and the y-intercept (b)
 * for the line equation y = mx + b.
 */
struct Slide {
    int x1, y1, x2, y2;
    int m; // Slope (will be 1 or -1)
    int b; // y-intercept (y = mx + b => b = y - mx)
    int minX, maxX, minY, maxY;

    /**
     * @brief Calculates the slide's line equation parameters (m and b).
     */
    void calculateEquation() {
        // Handle vertical line case to avoid division by zero, though 45-degree
        // slides shouldn't be vertical.
        if (x2 == x1) {
            m = 0; // Should not happen based on 45-degree constraint
            b = 0;
        } else {
            m = (y2 - y1) / (x2 - x1);
            b = y1 - m * x1;
        }
        minX = min(x1, x2);
        maxX = max(x1, x2);
        minY = min(y1, y2);
        maxY = max(y1, y2);
    }

    /**
     * @brief Checks if a given x-coordinate is within the slide's segment.
     * @param x The x-coordinate to check.
     * @return true if x is on the slide segment, false otherwise.
     */
    bool isXOnSlide(int x) const {
        return (x >= minX && x <= maxX);
    }

    /**
     * @brief Checks if a given (x, y) point is on the slide's segment.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return true if the point is on the slide segment, false otherwise.
     */
    bool isPointOnSlide(int x, int y) const {
        // Check if x is in range and if the point satisfies the line equation
        return isXOnSlide(x) && (y == m * x + b);
    }

    /**
     * @brief Gets the y-coordinate on the slide's line for a given x.
     * @param x The x-coordinate.
     * @return The corresponding y-coordinate.
     */
    int getY(int x) const {
        return m * x + b;
    }
};

/**
 * @brief Checks if a point is a "stuck" point (a 'V' intersection).
 * @param x The current x-coordinate.
 * @param y The current y-coordinate.
 * @param slides The list of all slides.
 * @return true if the point is a concave 'V' intersection, false otherwise.
 */
bool isStuck(int x, int y, const vector<Slide>& slides) {
    int intersections = 0;
    int slopes[2];
    
    // Find all slides that pass through (x, y)
    for (const auto& slide : slides) {
        if (slide.isPointOnSlide(x, y)) {
            if (intersections < 2) {
                slopes[intersections] = slide.m;
            }
            intersections++;
        }
    }

    // A "stuck" point is an intersection of exactly two slides
    // with opposite slopes (m=1 and m=-1).
    if (intersections == 2 && slopes[0] != slopes[1]) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Slide> slides(n);
    for (int i = 0; i < n; ++i) {
        cin >> slides[i].x1 >> slides[i].y1 >> slides[i].x2 >> slides[i].y2;
        slides[i].calculateEquation();
    }

    int currentX, currentY, currentEnergy;
    cin >> currentX >> currentY >> currentEnergy;

    // A state machine to manage movement.
    // 0 = FALLING, 1 = SLIDING
    int mode = 0; // Start by falling
    int currentSlideIndex = -1;

    // We use a large loop limit to prevent infinite loops in case of bad data,
    // given the grid size (50x50) and energy, a valid path should be much shorter.
    for (int loopGuard = 0; loopGuard < 10000; ++loopGuard) {
        
        // Stop conditions
        if (currentY == 0 || currentEnergy == 0) {
            break;
        }
        // The problem text "ground (x = 0)" seems to be incorrect based on
        // examples. We will rely on y=0 or E=0.

        if (mode == 0) { // FALLING
            int yTarget = 0; // Ground
            int hitSlideIndex = -1;

            // Find the highest slide *below* the current position at currentX
            for (int i = 0; i < n; ++i) {
                if (slides[i].isXOnSlide(currentX)) {
                    int yOnSlide = slides[i].getY(currentX);
                    if (yOnSlide < currentY && yOnSlide >= yTarget) {
                        yTarget = yOnSlide;
                        hitSlideIndex = i;
                    }
                }
            }

            if (hitSlideIndex != -1) {
                // Landed on a slide
                currentY = yTarget;
                currentSlideIndex = hitSlideIndex;
                mode = 1; // Switch to SLIDING mode
            } else {
                // No slide below, fall to the ground
                currentY = 0;
                break;
            }
        } else { // SLIDING
            
            // 1. Check if stuck
            if (isStuck(currentX, currentY, slides)) {
                long long unlockCost = (long long)currentX * currentY;
                if (currentEnergy < unlockCost) {
                    currentEnergy = 0; // Not enough energy, stop
                    break;
                }
                currentEnergy -= unlockCost;
                // After unlocking, we continue sliding
            }
            
            // 2. Try to slide one unit
            if (currentEnergy == 0) break; // Check energy again after unlocking

            Slide& s = slides[currentSlideIndex];

            // Determine the "one direction" to slide.
            // Based on Example 1 (4,7) -> (3,6) on slide y=x+3 [ends (2,5), (5,8)]
            // It moves towards the (2,5) end (lower y).
            // Based on Example 2 (2,5) -> (3,4) on slide y=-x+7 [ends (2,5), (4,3)]
            // It moves towards the (4,3) end (lower y).
            // Hypothesis: Always slide towards the endpoint with the lower y-coordinate.
            
            int targetX, targetY;
            if (s.y1 < s.y2) {
                targetX = s.x1;
                targetY = s.y1;
            } else if (s.y2 < s.y1) {
                targetX = s.x2;
                targetY = s.y2;
            } else {
                // y-coords are equal, impossible for 45-degree slide unless x1=x2
                // As a fallback, let's pick the one with lower x
                targetX = (s.x1 < s.x2) ? s.x1 : s.x2;
            }

            // If we are *at* the lower-y endpoint, the "one direction"
            // must be towards the *other* endpoint.
            if (currentX == targetX && currentY == s.getY(targetX)) {
                 targetX = (currentX == s.x1) ? s.x2 : s.x1;
            }


            if (currentX == targetX) {
                // We are at the target endpoint, we can't slide further
                // in this direction. We must fall.
                mode = 0;
                continue;
            }

            // Calculate the 1-unit step
            int deltaX = (targetX > currentX) ? 1 : -1;
            int deltaY = s.m * deltaX;
            
            // Cost of a 1-unit slide (dist = max(|dx|, |dy|) = 1)
            int slideCost = 1; 

            if (currentEnergy >= slideCost) {
                currentEnergy -= slideCost;
                currentX += deltaX;
                currentY += deltaY;

                // If we reached an endpoint, switch to falling
                if (currentX == s.x1 || currentX == s.x2) {
                    mode = 0;
                }
                // Otherwise, stay in SLIDING mode for the next loop
                
            } else {
                // Not enough energy to slide, stop
                currentEnergy = 0;
                break;
            }
        }
    }

    // Print the final position
    cout << currentX << " " << currentY << endl;

    return 0;
}