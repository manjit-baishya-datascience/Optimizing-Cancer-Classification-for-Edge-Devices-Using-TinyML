#include <Arduino.h>
#include "parser.h"
#include "model.h"

void setup() {
    Serial.begin(9600);
    Serial.println("Logistic Regression Classifier");
    Serial.println("===============================");
    Serial.print("Enter 13 comma separated values:");
}

void loop() {
    float inputs[13];
    if (validateAndParseInput(inputs, 13)) {
        int predicted_class = predict(inputs, 13, 5);
        Serial.print("Predicted Class: ");
        Serial.println(predicted_class);
    } else {
        Serial.println("Invalid input! Please enter exactly 14 comma-separated numbers.");
    }

    delay(500);
}