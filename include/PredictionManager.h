#ifndef PREDICTIONMANAGER_H
#define PREDICTIONMANAGER_H

#include <vector>
#include <string>
#include <memory>

class Prediction {
public:
    std::string name;
    float confidence;

    Prediction(const std::string& name, float confidence);
};

class PredictionManager {
public:
    void AddPrediction(std::shared_ptr<Prediction> prediction);
    std::vector<std::shared_ptr<Prediction>> GetPredictions() const;
    void ClearPredictions();

private:
    std::vector<std::shared_ptr<Prediction>> predictions;
};

#endif // PREDICTIONMANAGER_H
