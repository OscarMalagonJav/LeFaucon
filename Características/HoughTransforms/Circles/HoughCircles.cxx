#include "HoughCircles.h"


UnsignedCharImageType::Pointer applyHoughTransformForCircles(std::string inputImageName, int numberOfCircles, 
float radiusMin, float radiusMax,float sigmaGradient,float threshold,
float discRadiusRatio,float variance,float sweepAngle){
	ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
	reader->SetFileName(inputImageName);
	UnsignedCharImageType::Pointer localImage = reader->GetOutput();
	HoughTransformFilterType::Pointer houghFilter = HoughTransformFilterType::New();
	houghFilter->SetInput( reader->GetOutput() );
	houghFilter->SetNumberOfCircles(numberOfCircles);
	houghFilter->SetMinimumRadius(radiusMin);
	houghFilter->SetMaximumRadius(radiusMax);
	houghFilter->SetSigmaGradient(sigmaGradient);
	houghFilter->SetThreshold(threshold);
	houghFilter->SetDiscRadiusRatio(discRadiusRatio);
	houghFilter->SetVariance(variance);
	houghFilter->SetSweepAngle(sweepAngle);

	UnsignedCharImageType::IndexType localIndex;
	houghFilter->Update();

	UnsignedCharImageType::Pointer outputImage = houghFilter->GetOutput();
	outputImage->Update();
	return outputImage;
}
