#include <cmath>

class VariableSpeedControl
{
public:
    // Method to calculate the position based on variable speed control
    // t is the time, b is the start position, c is the change in position, d is the duration
    double easeInOutCubic(double t, double b, double c, double d)
    {
        t /= d / 2;
        if (t < 1) return c / 2 * t * t * t + b;
        t -= 2;
        return c / 2 * (t * t * t + 2) + b;
    }
};
