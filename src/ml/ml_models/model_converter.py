import tensorflow as tf

# Load your Keras model (assuming it's saved as a .h5 file)
model = tf.keras.models.load_model('emg_moment_prediction_model_cnnlstm.h5')

# Initialize the TFLite converter
converter = tf.lite.TFLiteConverter.from_keras_model(model)

# Enable TensorFlow Lite's built-in ops and TensorFlow select ops
converter.target_spec.supported_ops = [
    tf.lite.OpsSet.TFLITE_BUILTINS,  # Enable TensorFlow Lite built-in ops
    tf.lite.OpsSet.SELECT_TF_OPS     # Enable select TensorFlow ops for unsupported ones
]

# Disable the experimental lowering of tensor list operations
converter._experimental_lower_tensor_list_ops = False

# Enable resource variable support (for dynamic tensor usage like in LSTM layers)
converter.experimental_enable_resource_variables = True

# Optional: Apply optimizations (e.g., quantization for performance)
converter.optimizations = [tf.lite.Optimize.DEFAULT]  # Default quantization

# Convert the model to TFLite format
tflite_model = converter.convert()

# Save the converted TFLite model to a file
with open('model.tflite', 'wb') as f:
    f.write(tflite_model)

print("TFLite model conversion successful!")
