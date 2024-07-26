#include <cmath>

class DistanceBasedSensitivity
{
public:
    // Method to calculate the sensitivity based on the distance
    double calculateSensitivity(double distance, double maxSensitivity, double minSensitivity, double maxDistance)
    {
        // Scale the sensitivity inversely with distance
        // The closer the enemy, the higher the sensitivity
        // The farther the enemy, the lower the sensitivity
        double sensitivity = maxSensitivity - ((maxSensitivity - minSensitivity) * (distance / maxDistance));
        return std::max(minSensitivity, std::min(maxSensitivity, sensitivity));
    }
};
