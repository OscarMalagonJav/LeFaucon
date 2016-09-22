#ifndef BOOLEANMAP_H
#define BOOLEANMAP_H

#include "booleanMapTypes.h"

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(std::list<std::string> listOfFeatureImagesPath, int numberOfThresholds);
std::list<UnsignedCharImageType::Pointer> loadFeatureImages(std::list<std::string> listOfFeatureImagesPath);
std::list<int> calculateListOfThresholds(int numberOfThresholds);
UnsignedCharImageType::Pointer thresholdingImage(int thresholdValue, UnsignedCharImageType::Pointer inputImage, bool isNegative);


#endif