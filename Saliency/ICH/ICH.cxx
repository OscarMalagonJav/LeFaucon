#include <iostream>
#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"

typedef itk::Image<unsigned char, 2 > ItkImageType;
typedef itk::ImageFileReader<ItkImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<ItkImageType> ImageFileWriterType;

int** initializeMatrix(int rows, int columns);
float** initializeMatrixF(int rows, int columns);
int** calculateCoocurrenceMatrix(ItkImageType::Pointer image, int rows, int columns, int z);
float calculateDenominator(int** H, int rows, int columns);
float** calculatePMF(int **H,int rows, int columns, float denominator);
float calculateU(float **PMF, int rows, int columns);
float ** calculateInversePMF(float **PMF, int rows, int columns, float U);
float** calculateSaliency(ItkImageType::Pointer itkInputImage, float** inversePMF, int rows, int columns, int z);

//*********************************************************************
int** initializeMatrix(int rows, int columns)
{
    int** matrix = new int*[rows];
    for (int row = 0; row < rows; row++)
    {
        matrix[row] = new int[columns];
        for (int col = 0; col < columns; col++)
        {
            matrix[row][col] =0;
        }
    }
    return matrix;
}
//*********************************************************************
float** initializeMatrixF(int rows, int columns)
{
    float** matrix = new float*[rows];
    for (int row = 0; row < rows; row++)
    {
        matrix[row] = new float[columns];
        for (int col = 0; col < columns; col++)
        {
            matrix[row][col] =0;
        }
    }
    return matrix;
}

//*********************************************************************
int** calculateCoocurrenceMatrix(ItkImageType::Pointer image, int rows, int columns, int z)
{
    int** ICH = initializeMatrix(256, 256);
    for(unsigned int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for(unsigned int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
          ItkImageType::IndexType pixelIndex;
          pixelIndex[0] = rowIndex;
          pixelIndex[1] = columnIndex;
          int center = (int)image->GetPixel(pixelIndex);
          for(int i = -z; i< z+1; i++)
          {
              for(int j = -z; j< z+1; j++)
              {
                  if( rowIndex +i >0 && rowIndex +i < rows && columnIndex +j >0 && columnIndex +j < columns )
                  {
                      ItkImageType::IndexType pixelIndexNeigh;
                      pixelIndexNeigh[0] = rowIndex + i;
                      pixelIndexNeigh[1] = columnIndex + j;
                      int neighbor = (int)image->GetPixel(pixelIndexNeigh);
                      ICH[center][neighbor] ++;
                  }
              }
          }
        }
    }
    return ICH;
}

//*********************************************************************
float calculateDenominator(int** H, int rows, int columns)
{
    float denominator = 0.0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            denominator += (float) H[i][j];
        }
    }
    return denominator;
}

//*********************************************************************
float** calculatePMF(int **H,int rows, int columns, float denominator)
{
    float **PMF = new float*[rows];
    for (int i = 0; i < rows; ++i) {
        PMF[i] = new float[columns];
        for (int j = 0; j < columns; ++j) {
            PMF[i][j] = ( (float) H[i][j] / denominator );
        }
    }
    return PMF;
}

//*********************************************************************
float calculateU(float **PMF, int rows, int columns)
{
    int nonZeros =0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if( PMF[i][j] != 0 ){
                nonZeros++;
            }
        }
    }
    float U = ( (float) 1/nonZeros );
    return U;
}

//*********************************************************************
float ** calculateInversePMF(float **PMF, int rows, int columns, float U)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (PMF[i][j] == 0 || PMF[i][j] > U) {
                PMF[i][j] = 0;
            } else if (PMF[i][j] <= U) {
                PMF[i][j] = U - PMF[i][j];
            }
        }
    }
    return PMF;
}

//*********************************************************************
float** calculateSaliency(ItkImageType::Pointer itkInputImage, float** inversePMF, int rows, int columns, int z)
{
    float **newImage = initializeMatrixF(rows, columns);
    for(unsigned int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for(unsigned int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
          ItkImageType::IndexType pixelIndex;
          pixelIndex[0] = rowIndex;
          pixelIndex[1] = columnIndex;
          int center = (int)itkInputImage->GetPixel(pixelIndex);
          for(int i = -z; i< z+1; i++)
          {
              for(int j = -z; j< z+1; j++)
              {
                  if( rowIndex +i >0 && rowIndex +i < rows && columnIndex +j >0 && columnIndex +j < columns )
                  {
                      ItkImageType::IndexType pixelIndexNeigh;
                      pixelIndexNeigh[0] = rowIndex + i;
                      pixelIndexNeigh[1] = columnIndex + j;
                      int neighbor = (int)itkInputImage->GetPixel(pixelIndexNeigh);
                      newImage[rowIndex][columnIndex] += (float) inversePMF[center][neighbor];
                  }
              }
          }
        }
    }
    return newImage;

}

int main(int argc, char * argv[])
{
    std::string inputImageName = argv[1];
    int z = atoi(argv[2]);

    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputImageName);
    reader->Update();

    ItkImageType::Pointer itkInputImage = reader->GetOutput();
    ItkImageType::RegionType region = itkInputImage->GetLargestPossibleRegion();
    ItkImageType::SizeType regionSize = region.GetSize();

    int rows = regionSize[0];
    int columns = regionSize[1];
    
    int** H = calculateCoocurrenceMatrix(itkInputImage, rows, columns, 1);
    float den = calculateDenominator(H, 256,256);
    float** PMF = calculatePMF(H,256, 256, den);
    float U = calculateU(PMF, 256, 256);
    float** inversePMF = calculateInversePMF(PMF, 256, 256, U);
    float** saliency = calculateSaliency(itkInputImage, inversePMF, rows, columns, z);
}

