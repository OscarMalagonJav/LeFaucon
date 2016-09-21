#ifndef ATTENTIONMAP_H
#define ATTENTIONMAP_H

#include "booleanMapTypes.h"

std::list<UnsignedCharImageType::Pointer> generateAttentionMapList(std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps);
UnsignedCharImageType::Pointer calculateAttentionMap(UnsignedCharImageType::Pointer booleanMap);

#endif