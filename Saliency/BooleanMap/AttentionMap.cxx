#include "AttentionMap.h"

UnsignedCharImageType::Pointer dilateImage(UnsignedCharImageType::Pointer booleanMap)
{
    DilateFilterType::Pointer binaryDilate = DilateFilterType::New();
    KernelType kernel;
    kernel.SetRadius( 1 );//Kernel 3x3
    kernel.CreateStructuringElement();
    binaryDilate->SetKernel( kernel );
    binaryDilate->SetInput( booleanMap );
    binaryDilate->Update();

    return binaryDilate->GetOutput();
}

UnsignedCharImageType::Pointer normalizeImage(UnsignedCharImageType::Pointer inputImage)
{
    CastToFloat::Pointer castToFloat = CastToFloat::New();
    castToFloat->SetInput(inputImage);
    castToFloat->Update();
    NormalizeFilterType::Pointer normalizeFilter = NormalizeFilterType::New();
    normalizeFilter->SetInput( castToFloat->GetOutput() );
    normalizeFilter->Update();
    CastToUnsignedChar::Pointer castToUnsignedChar = CastToUnsignedChar::New();
    castToUnsignedChar->SetInput(normalizeFilter->GetOutput());
    castToUnsignedChar->Update();

    return castToUnsignedChar->GetOutput();
    
}

std::list<UnsignedCharImageType::Pointer> AttentionMapsList(std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps)
{
    std::list<UnsignedCharImageType::Pointer> attentionMapsList;
    UnsignedCharImageType::Pointer finalMap = UnsignedCharImageType::New();

    for(std::list<UnsignedCharImageType::Pointer>::iterator itBooleanMaps = listOfBooleanMaps.begin(); itBooleanMaps != listOfBooleanMaps.end(); itBooleanMaps++)
    {
        //Assuming that the image does not have to receive a flood fill process
        UnsignedCharImageType::Pointer temporalImage = dilateImage(*itBooleanMaps);
        temporalImage->Update();
        temporalImage = normalizeImage( temporalImage );
        temporalImage->Update();
        attentionMapsList.push_back( temporalImage );
    }    
    
    return attentionMapsList;
}
