#ifndef AIMMYV2_CPP_AIMODEL_H
#define AIMMYV2_CPP_AIMODEL_H

#include <string>
#include <vector>
#include <memory>
#include <onnxruntime_cxx_api.h>

class AIModel {
public:
    AIModel(const std::string& model_path);

    void LoadModel(const std::string& model_path);
    void RunInference(const std::vector<float>& input_data, std::vector<float>& output_data);

private:
    std::unique_ptr<Ort::Session> onnxModel;
    std::vector<const char*> inputNamesCStr;
    std::vector<const char*> outputNamesCStr;
};

#endif //AIMMYV2_CPP_AIMODEL_H
