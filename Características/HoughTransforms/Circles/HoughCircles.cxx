#include "HoughCircles.h"
/*
  std::string showParametersInfo(char * argv[])
  {
    std::string execute= "";
    std::cout<<"Parameters"<<std::endl;
    std::cout<< "Input image name: "<< argv[1] <<std::endl;
    std::cout<< "Output image name: "<< argv[2] <<std::endl;
    std::cout<< "Number of circles: "<< argv[3] <<std::endl;
    std::cout<< "Radius min: "<< argv[4] <<std::endl;
    std::cout<< "Radius max: "<< argv[5] <<std::endl;
	std::cout<< "Sigma gradient: "<< argv[6] <<std::endl;
	std::cout<< "Threshold: "<< argv[7] <<std::endl;
	std::cout<< "Disc radius ratio: "<< argv[8] <<std::endl;
	std::cout<< "Variance: "<< argv[9] <<std::endl;
	std::cout<< "Sweep angle: "<< argv[10] <<std::endl;
    std::cout<<"*********************************************"<<std::endl;
    std::cout<<"Continue?...(Y/N)"<<std::endl;
    std::cin>>execute;
    return execute;
  }
*/

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
	/*AccumulatorImageType::Pointer localAccumulator = houghFilter->GetOutput();
	HoughTransformFilterType::CirclesListType circles;
	circles = houghFilter->GetCircles(numberOfCircles);

	UnsignedCharImageType::Pointer outputImage = UnsignedCharImageType::New();
	UnsignedCharImageType::RegionType region;
	region.SetSize(localImage->GetLargestPossibleRegion().GetSize());
	region.SetIndex(localImage->GetLargestPossibleRegion().GetIndex());
	outputImage->SetRegions(region);
	outputImage->SetOrigin(localImage->GetOrigin());
	outputImage->SetSpacing(localImage->GetSpacing());
	outputImage->Allocate(true);
	typedef HoughTransformFilterType::CirclesListType CirclesListType;
	CirclesListType::const_iterator itCircles = circles.begin();

	while( itCircles != circles.end() )
		{
		std::cout << "Center: ";
		std::cout << (*itCircles)->GetObjectToParentTransform()->GetOffset()
					<< std::endl;
		std::cout << "Radius: " << (*itCircles)->GetRadius()[0] << std::endl;
		for(double angle = 0;angle <= itk::Math::pi; angle += itk::Math::pi/60.0 )
		{
		localIndex[0] =
			(long int)((*itCircles)->GetObjectToParentTransform()->GetOffset()[0]
						+ (*itCircles)->GetRadius()[0]*std::cos(angle));
		localIndex[1] =
			(long int)((*itCircles)->GetObjectToParentTransform()->GetOffset()[1]
						+ (*itCircles)->GetRadius()[0]*std::sin(angle));
		UnsignedCharImageType::RegionType outputRegion =
										outputImage->GetLargestPossibleRegion();
		if( outputRegion.IsInside( localIndex ) )
			{
			outputImage->SetPixel( localIndex, 255 );
			}
		}
		itCircles++;
		}
*/
	UnsignedCharImageType::Pointer outputImage = houghFilter->GetOutput();
	outputImage->Update();
	return outputImage;
}