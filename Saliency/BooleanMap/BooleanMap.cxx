#include "BooleanMap.h"
#include <math.h> 

std::list<int> calculateListOfThresholds(int numberOfThresholds) {
    std::list<int> listOfThresholds;
    if(numberOfThresholds > 0)
    {
        int delta = floor(240 / numberOfThresholds);
        for (int index = 1; index <= numberOfThresholds; index++)
        {
            listOfThresholds.push_back(delta*index);
        }
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
    return thresholdFilter->GetOutput();
}

UnsignedCharImageType::Pointer openingMorphologicalOperation(UnsignedCharImageType::Pointer inputImage, bool isNegative)
{
  KernelType circularKernel;
  KernelType::SizeType circularKernelSize;
  circularKernelSize.Fill( 8 );
  circularKernel.SetRadius(circularKernelSize);
  circularKernel.CreateStructuringElement();

  OpeningMorphologicalOperationFilter::Pointer openingFilter = OpeningMorphologicalOperationFilter::New();
  openingFilter->SetInput( inputImage );
  openingFilter->SetKernel( circularKernel );
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

std::list<UnsignedCharImageType::Pointer> generateBooleanMaps(int numberOfThresholds, UnsignedCharImageType::Pointer inputImage)
{
    std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps;
    std::list<int> listOfThreshold = calculateListOfThresholds(numberOfThresholds);

    for(std::list<int>::iterator itThreshold = listOfThreshold.begin(); itThreshold != listOfThreshold.end(); itThreshold++)
    {
            UnsignedCharImageType::Pointer booleanImage        = thresholdingImage( *itThreshold, inputImage, false);
            UnsignedCharImageType::Pointer inverseBooleanImage = thresholdingImage( *itThreshold, inputImage, true);
            booleanImage->Update();
            inverseBooleanImage->Update();
            UnsignedCharImageType::Pointer openingBooleanImage = openingMorphologicalOperation(booleanImage, false);
            UnsignedCharImageType::Pointer openingInverseBooleanImage = openingMorphologicalOperation(inverseBooleanImage, true);
            listOfBooleanMaps.push_back(openingBooleanImage);
            listOfBooleanMaps.push_back(openingInverseBooleanImage);
    }
    return listOfBooleanMaps;
}