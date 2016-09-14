#include "HoughLines.h"
UnsignedCharImageType::Pointer applyHoughTransformForLines(std::string inputImageName, int numberOfLines,float threshold,
                                                           float discRadius,float variance,float angleResolution)
{
    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	reader->SetFileName(inputImageName);
	UnsignedCharImageType::Pointer localImage = reader->GetOutput();
	HoughTransformFilterType::Pointer houghFilter = HoughTransformFilterType::New();
	houghFilter->SetInput( reader->GetOutput() );
	houghFilter->SetNumberOfLines(numberOfLines);
	houghFilter->SetThreshold(threshold);
	houghFilter->SetDiscRadius(discRadius);
	houghFilter->SetVariance(variance);
	houghFilter->SetAngleResolution(angleResolution);

	UnsignedCharImageType::IndexType localIndex;
	houghFilter->Update();
    UnsignedCharImageType::Pointer outputImage = houghFilter->GetOutput();
	outputImage->Update();
	return outputImage;
}
