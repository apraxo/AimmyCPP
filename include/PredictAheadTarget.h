#ifndef PREDICTAHEADTARGET_H
#define PREDICTAHEADTARGET_H

#include "PredictionMethod.h"

class PredictAheadTarget : public PredictionMethod
{
public:
    QPoint predict(const QPoint &currentPosition, const QPoint &velocity) override;
};

#endif // PREDICTAHEADTARGET_H
