#include "PredictAheadTarget.h"

QPoint PredictAheadTarget::predict(const QPoint &currentPosition, const QPoint &velocity)
{
    // Simple prediction logic, you can adjust this as needed
    int predictionFactor = 5; // Example factor for prediction
    QPoint predictedPosition = currentPosition + velocity * predictionFactor;
    return predictedPosition;
}
