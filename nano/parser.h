#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

// Function to validate and parse input values
bool validateAndParseInput(float values[], int expectedCount) {
    while (Serial.available() == 0);  // Wait for input

    String inputString = Serial.readString();  // Read entire input line
    inputString.trim();  // Remove whitespace

    int startIndex = 0, count = 0;

    while (count < expectedCount) {
        int commaIndex = inputString.indexOf(',', startIndex);
        String value;

        if (commaIndex == -1) {
            value = inputString.substring(startIndex);  // Last value
        } else {
            value = inputString.substring(startIndex, commaIndex);
            startIndex = commaIndex + 1;
        }

        value.trim();  // Ensure no leading/trailing spaces
        if (!value.length()) return false;  // Empty input case

        values[count] = value.toFloat();
        count++;

        if (commaIndex == -1) break;
    }

    return (count == expectedCount);
}

#endif
