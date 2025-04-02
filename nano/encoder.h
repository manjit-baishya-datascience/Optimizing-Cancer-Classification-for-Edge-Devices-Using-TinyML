#ifndef LABEL_ENCODER_H
#define LABEL_ENCODER_H

#define NUM_CLASSES 5

const char* class_labels[NUM_CLASSES] = {"BRCA", "COAD", "KIRC", "LUAD", "PRAD"};

const int class_values[NUM_CLASSES] = {0, 1, 2, 3, 4};

#endif // LABEL_ENCODER_H