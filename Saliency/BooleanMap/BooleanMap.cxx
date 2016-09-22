#include "BooleanMap.h"
#include "booleanMapTypes.h"
#include <math.h> 

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(std::list<std::string> listOfFeatureImagesPath, int numberOfThresholds)
{
    std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps;
    std::list<UnsignedCharImageType::Pointer> listOfFeatureImages = loadFeatureImages(listOfFeatureImagesPath);
    std::list<int> listOfThreshold = calculateListOfThresholds(numberOfThresholds);
    std::list<UnsignedCharImageType::Pointer>::iterator itFeatures = listOfFeatureImages.begin();
    std::list<std::string>::iterator itThreshold = listOfThreshold.begin();

    for(itThreshold; itThreshold != listOfThreshold.end(); itThreshold++)
    {
        for(itFeatures; itFeatures != listOfFeatureImages.end(); itFeatures++)
        {
            UnsignedCharImageType::Pointer booleanImage        = thresholdingImage( *itThreshold, *itFeatures->GetOutput(), false);
            UnsignedCharImageType::Pointer inverseBooleanImage = thresholdingImage( *itThreshold, *itFeatures->GetOutput(), true);
            
            //listOfBooleanMaps.insert(thresholdFilter->GetOutput());
        }
    }
    return listOfBooleanMaps;
}

std::list<UnsignedCharImageType::Pointer> loadFeatureImages(std::list<std::string> listOfFeatureImagesPath)
{
    std::list<UnsignedCharImageType::Pointer> listOfImages;
    std::list<std::string>::iterator itImagesPath = listOfFeatureImagesPath.begin();   
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    for(itImagesPath; itImagesPath != listOfFeatureImagesPath.end() ; itImagesPath++ )
    {
        reader->SetFileName(*itImagesPath);
        reader->Update();
        listOfImages.insert(reader->GetOutput());
    }
    return listOfImages;
}

std::list<int> calculateListOfThresholds(int numberOfThresholds) {
    if(numberOfThresholds <= 0)
    {
        return NULL;
    }
    std::list<int> listOfThresholds;
    int delta = floor(255 / numberOfThresholds);
    for (int index = 1; index <= numberOfThresholds; index++)
    {
        listOfThresholds.insert(delta*index);
    }
    return listOfThresholds;
}

UnsignedCharImageType::Pointer thresholdingImage(int thresholdValue, UnsignedCharImageType::Pointer inputImage, bool isNegative)
{
    ThresholdFilterType::Pointer thresholdFilter = FilterType::New();
    thresholdFilter->SetInput( inputImage );
    thresholdFilter->SetUpperThreshold( thresholdValue );
    if(isNegative)
    {
        thresholdFilter->SetOutsideValue( 255 );
        thresholdFilter->SetInsideValue( 0 );
    }else{
        thresholdFilter->SetOutsideValue( 0 );
        thresholdFilter->SetInsideValue( 255 );
    }
    thresholdFilter->Update();
    return thresholdImage->GetOutput();
}