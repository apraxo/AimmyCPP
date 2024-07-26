// Add this before including the ONNX headers
#define _Frees_ptr_opt_

#include "AIModel.h"
#include <onnxruntime_cxx_api.h>
#include <cpu_provider_factory.h>
#include <locale>
#include <codecvt>

AIModel::AIModel(const std::string& model_path) {
    LoadModel(model_path);
}

void AIModel::LoadModel(const std::string& modelPath) {
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "AIModel");
    Ort::SessionOptions sessionOptions;
    sessionOptions.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);

    // Convert modelPath from std::string to std::wstring
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wModelPath = converter.from_bytes(modelPath);

    // Load the ONNX model
    onnxModel = std::make_unique<Ort::Session>(env, wModelPath.c_str(), sessionOptions);

    Ort::AllocatorWithDefaultOptions allocator;

    // Allocate memory for input and output names
    size_t numInputNodes = onnxModel->GetInputCount();
    size_t numOutputNodes = onnxModel->GetOutputCount();

    inputNamesCStr.resize(numInputNodes);
    outputNamesCStr.resize(numOutputNodes);

    // Get input names
    for (size_t i = 0; i < numInputNodes; i++) {
        Ort::AllocatedStringPtr inputName = onnxModel->GetInputNameAllocated(i, allocator);
        inputNamesCStr[i] = inputName.release();
    }

    // Get output names
    for (size_t i = 0; i < numOutputNodes; i++) {
        Ort::AllocatedStringPtr outputName = onnxModel->GetOutputNameAllocated(i, allocator);
        outputNamesCStr[i] = outputName.release();
    }
}

void AIModel::RunInference(const std::vector<float>& input_data, std::vector<float>& output_data) {
    // Implementation of the inference logic
}
