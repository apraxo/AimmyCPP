#ifndef PREDICTIONMETHOD_H
#define PREDICTIONMETHOD_H

#include <QPoint>

class PredictionMethod
{
public:
    virtual QPoint predict(const QPoint &currentPosition, const QPoint &velocity) = 0;
};

#endif // PREDICTIONMETHOD_H
