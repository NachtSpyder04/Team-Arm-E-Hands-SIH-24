#include "micro_mutable_op_resolver.h"
#include "micro_interpreter.h"
#include "schema_generated.h"
#include "version.h"
#include "model.h"  // Your model file

const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;

// Define the maximum number of operations your model requires.
constexpr int kOpResolverSize = 10;  // Adjust this number based on the actual number of ops your model uses

void app_main() {
    model = tflite::GetModel(g_model);
    if (model->version() != TFLITE_SCHEMA_VERSION) {
        printf("Model provided is schema version %d not equal "
               "to supported version %d.\n",
               model->version(), TFLITE_SCHEMA_VERSION);
        return;
    }

    // Declare MicroMutableOpResolver with the specified size
    static tflite::MicroMutableOpResolver<kOpResolverSize> resolver;

    // Register the specific ops your model uses
    resolver.AddConv2D();
    resolver.AddFullyConnected();
    resolver.AddSoftmax();
    resolver.AddQuantize();
    resolver.AddDequantize();
    resolver.AddRelu();
    // Add other necessary ops based on your model

    static tflite::MicroInterpreter static_interpreter(
        model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
    interpreter = &static_interpreter;

    interpreter->AllocateTensors();

    input = interpreter->input(0);
    output = interpreter->output(0);

    // Example: setting input tensor data
    input->data.f[0] = 0.5;

    interpreter->Invoke();

    float result = output->data.f[0];
    printf("Model output: %f\n", result);
}
