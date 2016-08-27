#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"
#include "itkThresholdImageFilter.h"
#include "itkMinimumMaximumImageCalculator.h"
#include "itkGradientMagnitudeImageFilter.h"
#include "itkDiscreteGaussianImageFilter.h"
#include "itkMath.h"
#include "itkHoughTransform2DCirclesImageFilter.h"
#include <list>

typedef itk::Image<float, 2> AccumulatorImageType;
typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType>        ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::HoughTransform2DCirclesImageFilter<unsigned char,float> HoughTransformFilterType;
typedef HoughTransformFilterType::CirclesListType CirclesListType;

  std::string showParametersInfo(char * argv[])
  {
    std::string execute= "";
    std::cout<<"Parameters"<<std::endl;
    std::cout<< "Input image name: "<< argv[1] <<std::endl;
    std::cout<< "Output image name: "<< argv[2] <<std::endl;
    std::cout<< "Number of circles: "<< argv[3] <<std::endl;
    std::cout<< "Radius min: "<< argv[4] <<std::endl;
    std::cout<< "Radius max: "<< argv[5] <<std::endl;
    std::cout<<"*********************************************"<<std::endl;
    std::cout<<"Continue?...(Y/N)"<<std::endl;
    std::cin>>execute;
    return execute;
  }

  int main(int argc, char * argv[])
  {
    // Verify command line arguments
    if( argc < 6 )
      {
      std::cerr << "Usage: ";
      std::cerr << argv[0] << "inputImage outputImage numberOfCircles radiusMin radiusMax"
			  						<< "[sweepAngle (default =0) sigmaGradient (default=1)] "
									<< "varianceOfTheAccumulator(default=5)"
									<<"radiusOfTheDiskToRemoveFromTheAccumulator (default=10)"<<std::endl;
      return EXIT_FAILURE;
      }

    std::string inputImageName =argv[1];
    std::string outputImageName =argv[2];
	 int numberOfCircles = atoi(argv[3]);
	 float radiusMin = atof(argv[4]);
	 float radiusMax = atof(argv[5]);
	 float sweepAngle = atof(argv[6]);
	 float sigmaGradient = atoi(argv[7]);
	 float variance = atof(argv[8]);
	 float discRadiusRatio = atof(argv[9]);

    std::string execute = showParametersInfo(argv);
    if(execute=="y" || execute=="Y"){

      ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
      ImageFileWriterType::Pointer writer = ImageFileWriterType::New();
      reader->SetFileName(inputImageName);
		  UnsignedCharImageType::Pointer localImage = reader->GetOutput();
		  HoughTransformFilterType::Pointer houghFilter = HoughTransformFilterType::New();
		  houghFilter->SetInput( reader->GetOutput() );
		  houghFilter->SetNumberOfCircles(numberOfCircles);
		  houghFilter->SetMinimumRadius(radiusMin);
		  houghFilter->SetMaximumRadius(radiusMax);
		  UnsignedCharImageType::IndexType localIndex;
		  if( argc > 6 )
			 {
			 houghFilter->SetSweepAngle(sweepAngle);
			 }
		  if( argc > 7 )
			 {
			 houghFilter->SetSigmaGradient(sigmaGradient);
			 }
		  if( argc > 8 )
			 {
			 houghFilter->SetVariance(variance);
			 }
		  if( argc > 9 )
			 {
			 houghFilter->SetDiscRadiusRatio(discRadiusRatio);
			 }

			houghFilter->Update();
			AccumulatorImageType::Pointer localAccumulator = houghFilter->GetOutput();
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
			 for(double angle = 0;angle <= 2*itk::Math::pi; angle += itk::Math::pi/60.0 )
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

        writer->SetFileName(outputImageName);
        writer->SetInput(outputImage);
        writer->Update();
        return EXIT_SUCCESS;
  }else{
    return EXIT_FAILURE;
  }
}
