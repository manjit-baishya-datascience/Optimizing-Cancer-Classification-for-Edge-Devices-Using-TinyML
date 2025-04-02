#ifndef MODEL_H
#define MODEL_H

#include <Arduino.h>
#include <math.h>

// Logistic Regression Parameters (from trained Scikit-Learn model)
float intercepts[5] = {1.19165903, -1.06551768, -0.33707432, 0.19834431, 0.01258866};  // Beta 0 for each class

float coefficients[5][13] = {
    {-0.072313, -0.512722, -0.208434, 1.011521, -0.741579, -0.785168, -0.468310, -0.388264, -0.301377, 0.130499, -0.873616, -0.400641, -0.722120},
    {-0.319964, -0.383785, -0.057157, -0.558058, 0.065560, -0.295015, -0.294447, 1.444909, -0.147784, 0.124903, 0.214917, -0.123511, 0.712904},
    {0.826979, -0.227229, 0.654585, -0.042681, 0.072105, -0.209043, -0.200523, -0.483675, 0.829880, -0.291372, 0.398283, 0.363675, 0.279982},
    {-0.243337, 1.285777, -0.016978, -0.307841, -0.030399, -0.470153, 1.146116, -0.510914, -0.132217, 0.620621, 0.082608, 0.016989, 0.215490},
    {-0.191365, -0.162040, -0.372016, -0.102941, 0.634313, 1.759380, -0.182836, -0.062056, -0.248501, -0.584651, 0.177808, 0.143489, -0.486257}
};

// Softmax function
void softmax(float logits[], float probabilities[], int num_classes) {
    float sum_exp = 0.0;
    for (int i = 0; i < num_classes; i++) {
        probabilities[i] = exp(logits[i]);
        sum_exp += probabilities[i];
    }
    for (int i = 0; i < num_classes; i++) {
        probabilities[i] /= sum_exp;
    }
}

// Prediction function
int predict(float inputs[], int num_features, int num_classes) {
    float logits[5];  // Adjusted for 5 classes
    float probabilities[5];

    Serial.println("\n===============================");
    Serial.println("Input Features:");
    for (int i = 0; i < num_features; i++) {
        Serial.print(inputs[i], 4);
        if (i < num_features - 1) {
            Serial.print(", ");
        }
    }
    Serial.println();

    // Compute logits
    for (int i = 0; i < num_classes; i++) {
        logits[i] = intercepts[i];
        for (int j = 0; j < num_features; j++) {
            logits[i] += coefficients[i][j] * inputs[j];
        }
    }

    // Apply softmax
    softmax(logits, probabilities, num_classes);

    // Find class with highest probability
    int predicted_class = 0;
    float max_prob = probabilities[0];
    for (int i = 1; i < num_classes; i++) {
        if (probabilities[i] > max_prob) {
            max_prob = probabilities[i];
            predicted_class = i;
        }
    }

    Serial.print("\nPredicted Class: ");
    return predicted_class;
}

#endif
