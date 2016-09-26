#include "AttentionMap.h"
#include "booleanMapTypes.h"

UnsignedCharImageType::Pointer AttentionMap(std::list<UnsignedCharImageType::Pointer> listOfBooleanMaps)
{
    std::list<UnsignedCharImageType::Pointer> attentionMapsList;
    std::list<UnsignedCharImageType::Pointer>::iterator itBooleanMaps = listOfBooleanMaps.begin();
    UnsignedCharImageType::Pointer finalMap = UnsignedCharImageType::New();

    for(itBooleanMaps; itBooleanMaps != listOfBooleanMaps.end(); itBooleanMaps++)
    {
        //Assuming that the image does not have to receive a flood fill process
        UnsignedCharImageType::Pointer temporalImage = dilateImage(*itBooleanMaps);
        temporalImage.Update();
        temporalImage = normalizeImage( temporalImage->GetOutput() );
        temporalImage.Update();
        attentionMapsList.insert( temporalImage->GetOutput() );
    }    
    
    finalMap = generateMeanAttentionMapImage(attentionMapsList);
    return finalMap;
}

UnsignedCharImageType::Pointer dilateImage(UnsignedCharImageType::Pointer booleanMap);
{
    DilateFilterType::Pointer binaryDilate = DilateFilterType::New();
    KernelType kernel;
    kernel.SetRadius( 1 );//Kernel 3x3
    kernel.CreateStructuringElement();
    binaryDilate->SetKernel( kernel );
    binaryDilate->SetInput( booleanMap->GetOutput() );
    binaryDilate->Update();

    return binaryDilate->GetOutput();
}

UnsignedCharImageType::Pointer normalizeImage(UnsignedCharImageType::Pointer inputImage)
{
    CastToFloat::Pointer castToFloat = CastToFloat::New();
    castToFloat->SetInput(inputImage->GetOutput());
    castToFloat->Update();
    NormalizeFilterType::Pointer normalizeFilter = NormalizeFilterType::New();
    normalizeFilter->SetInput( castToFloat->GetOutput() );
    normalizeImage->Update();
    CastToUnsignedChar::Pointer castToUnsignedChar = CastToUnsignedChar::New();
    castToUnsignedChar->SetInput(normalizeImage->GetOutput());
    castToUnsignedChar->Update();

    return castToUnsignedChar->GetOutput();
    
}

UnsignedCharImageType::Pointer generateMeanAttentionMapImage(std::list<UnsignedCharImageType::Pointer> attentionMapsList)
{
    float numberOfImages = attentionMapsList.size();
    AddImageFilterType::Pointer imagesSum = AddImageFilterType::New();
    MultiplyImageFilterType::Pointer multiplyImageFilter = MultiplyImageFilterType::New();
    multiplyImageFilter->SetConstant(numberOfImages);
    std::list< UnsignedCharImageType::Pointer >::iterator attMapIt= attentionMapsList.begin();
    for( attMapIt ; attMapIt!= attentionMapsList.end(); attMapIt++ )
    {
        multiplyImageFilter->SetInput( *attMapIt );
        multiplyImageFilter->Update();
        if(imagesSum->GetOutput() == NULL)
        {
            imagesSum->SetInput1( UnsignedCharImageType::New() );
        }else{
            imagesSum->SetInput1( imagesSum->GetOutput() );
        }
        
        imagesSum->SetInput2(multiplyImageFilter->GetOutput());
        imagesSum->Update();
        imagesSum = imagesSum->GetOutput();
    }
    return imagesSum->GetOutput();
}