#include "AttentionMap.h"
#include "booleanMapTypes.h"

std::list<UnsignedCharImageType::Pointer> generateAttentionMapList(std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps)
{
    std::list<UnsignedCharImageType::Pointer> attentionMapsList;
    std::list<UnsignedCharImageType::Pointer>::iterator itBooleanMaps = listOfBooleanMaps.begin();

    for(itBooleanMaps; itBooleanMaps != listOfBooleanMaps.end(); itBooleanMaps++)
    {
        UnsignedCharImageType::Pointer attentionMap = calculateAttentionMap(*itBooleanMaps);
        attentionMap.Update();
        attentionMapsList.insert(attentionMap->GetOutput);
    }

    return attentionMapList;
}

UnsignedCharImageType::Pointer calculateAttentionMap(UnsignedCharImageType::Pointer booleanMap);
{
    //TODO
}
