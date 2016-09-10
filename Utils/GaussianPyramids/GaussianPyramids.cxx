#include "GaussianPyramids.h"

UnsignedCharImageType::Pointer gaussianPyramid(std::string inputImageName, int numberOfLevels){
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImageName);
    reader->Update();
    ImagePyramidType::Pointer pyramid =ImagePyramidType::New();
    pyramid->SetInput(reader->GetOutput());
    pyramid->SetNumberOfLevels(numberOfLevels);
    pyramid->SetStartingShrinkFactors(256);
    pyramid->Update();



    return pyramid->GetOutput();
}