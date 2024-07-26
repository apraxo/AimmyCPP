#include "PredictionManager.h"

// Prediction class implementation
Prediction::Prediction(const std::string& name, float confidence)
    : name(name), confidence(confidence) {}

// PredictionManager class implementation
void PredictionManager::AddPrediction(std::shared_ptr<Prediction> prediction) {
    predictions.push_back(prediction);
}

std::vector<std::shared_ptr<Prediction>> PredictionManager::GetPredictions() const {
    return predictions;
}

void PredictionManager::ClearPredictions() {
    predictions.clear();
}
