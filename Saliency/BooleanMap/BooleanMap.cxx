#include "BooleanMap.h"
#include "booleanMapTypes.h"
#include <math.h> 

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(std::list<std::string> listOfFeatureImagesPath, int numberOfThresholds)
{
    std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps;
    std::list<UnsignedCharImageType::Pointer> listOfFeatureImages = loadFeatureImages(listOfFeatureImagesPath);
    std::list<int> listOfThreshold = calculateListOfThresholds(numberOfThresholds);
    std::list<std::string>::iterator itThreshold = listOfThreshold.begin();
    std::list<UnsignedCharImageType::Pointer>::iterator itFeatures = listOfFeatureImages.begin();

    for(itThreshold; itThreshold != listOfThreshold.end(); itThreshold++)
    {
        for(itFeatures; itFeatures != listOfFeatureImages.end(); itFeatures++)
        {
            UnsignedCharImageType::Pointer booleanImage        = thresholdingImage( *itThreshold, *itFeatures->GetOutput(), false);
            UnsignedCharImageType::Pointer inverseBooleanImage = thresholdingImage( *itThreshold, *itFeatures->GetOutput(), true);
            booleanImage->Update();
            inverseBooleanImage->Update();
            UnsignedCharImageType::Pointer openingBooleanImage = openingMorphologicalOperation(booleanImage->GetOutput(), false);
            UnsignedCharImageType::Pointer openingInverseBooleanImage = openingMorphologicalOperation(inverseBooleanImage->GetOutput(), true);
            listOfBooleanMaps.insert(openingBooleanImage);
            listOfBooleanMaps.insert(openingInverseBooleanImage);
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
        return EXIT_FAILURE ;
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
    ThresholdFilterType::Pointer thresholdFilter = ThresholdFilterType::New();
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

UnsignedCharImageType::Pointer openingMorphologicalOperation(UnsignedCharImageType::Pointer inputImage, bool isNegative)
{
  KernelType circularKernel;
  KernelType::SizeType circularKernelSize;
  circularKernelSize.Fill( 8 );
  circularKernel.SetRadius(circularKernelSize);
  circularKernel.CreateStructuringElement();

  OpeningMorphologicalOperationFilter::Pointer openingFilter = OpeningMorphologicalOperationFilter::New();
  openingFilter->SetInput( inputImage->GetOutput() );
  openingFilter->SetKernel( ball );
  if(isNegative)
  {
    openingFilter->SetForegroundValue( 0 );
    openingFilter->SetBackgroundValue( 255 );
  }else{
    openingFilter->SetForegroundValue( 255 );
    openingFilter->SetBackgroundValue( 0 );
  }
  openingFilter->Update();
  return openingFilter->GetOutput();
}