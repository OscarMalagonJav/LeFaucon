#include "Noise-BinomialBlur"

ItkImageType::Pointer applyNoiseBinomialBlur(std::string inputImageName, int repetitions)
{

  ItkFileReaderType::Pointer reader = ItkFileReaderType::New();
  reader->SetFileName(inputImageName);
  smoothingFilterType::Pointer smoothingFilter = smoothingFilterType::New();
  smoothingFilter->SetInput( reader->GetOutput() );
  smoothingFilter->SetRepetitions( repetitions);
  smoothingFilter->Update();
  return smoothingFilter->GetOutput();
}
