#include "GaussianPyramids.h"

std::list<UnsignedCharImageType::Pointer> gaussianPyramid(std::string inputImageName,
        int numberOfLevels, float maximumError){
    std::list<UnsignedCharImageType::Pointer> levelsImageList;
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImageName);
    reader->Update();

    RecursiveMultiResolutionPyramidImageFilterType::Pointer pyramids = RecursiveMultiResolutionPyramidImageFilterType::New();
    pyramids->SetInput(reader->GetOutput());
    pyramids->SetNumberOfLevels(numberOfLevels);
    pyramids->SetMaximumError(maximumError);
    pyramids->Update();

      // This outputs the levels (0 is the lowest resolution)
  for(int i = 0; i < numberOfLevels; ++i)
    {
    RescaleFilterType::Pointer rescaleFilter = RescaleFilterType::New();
    rescaleFilter->SetInput(pyramids->GetOutput(i));
    rescaleFilter->SetOutputMinimum(0);
    rescaleFilter->SetOutputMaximum(255);
    rescaleFilter->Update();
    levelsImageList.insert(levelsImageList.end(),rescaleFilter->GetOutput() );
    }
    return levelsImageList;//reader->GetOutput();
}