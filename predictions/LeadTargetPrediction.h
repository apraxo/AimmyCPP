#ifndef LEADTARGERPREDICTION_H
#define LEADTARGERPREDICTION_H

#include "PredictionMethod.h"
#include <QPoint>

class LeadTargetPrediction : public PredictionMethod
{
public:
    QPoint predict(const QPoint &currentPosition, const QPoint &velocity) override;
};

#endif // LEADTARGERPREDICTION_H
