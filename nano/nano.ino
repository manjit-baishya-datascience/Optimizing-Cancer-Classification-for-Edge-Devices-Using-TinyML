#include <Arduino.h>
#include "parser.h"
#include "model.h"
#include "scaler.h"
#include "encoder.h"

void scaleInput(float inputs[], int size) {
    for (int i = 0; i < size; i++) {
        inputs[i] = (inputs[i] - feature_means[i]) / feature_scales[i];
    }
}

void setup() {
    Serial.begin(19200);
    Serial.println("Logistic Regression Classifier");
    Serial.println("===============================");
    Serial.println("Enter 13 comma-separated values: ");
}

void loop() {
    float inputs[NUM_FEATURES];

    if (validateAndParseInput(inputs, NUM_FEATURES)) {
        // Step 1: Scale the input
        scaleInput(inputs, NUM_FEATURES);

        // Step 2: Perform prediction
        int predicted_class = predict(inputs, NUM_FEATURES, NUM_CLASSES);

        // Step 3: Print the corresponding class label
        Serial.print("Predicted Class: ");
        Serial.println(class_labels[predicted_class]);

        Serial.println("\nEnter 13 comma-separated values: ");  // Prompt for next input
    }

    delay(100);  // Small delay to avoid unnecessary CPU usage
}