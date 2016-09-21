#ifndef BOOLEANMAP_H
#define BOOLEANMAP_H

#include "booleanMapTypes.h"

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(std::list<std::string> listOfFeatureImagesPath, std::list<int> listOfThreshold);
std::list<UnsignedCharImageType::Pointer> loadFeatureImages(std::list<std::string> listOfFeatureImagesPath);

#endif