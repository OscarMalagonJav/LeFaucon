#include <iostream>
#include <cstdlib>
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkThresholdImageFilter.h"
#include "itkMinimumMaximumImageCalculator.h"
#include <math.h> 

typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ImageFileWriter<UnsignedCharImageType> ImageFileWriterType;
typedef itk::ThresholdImageFilter< UnsignedCharImageType > ThresholdFilterType;
typedef itk::MinimumMaximumImageCalculator <UnsignedCharImageType> ImageCalculatorFilterType;

struct Node
{
    int id;
    ItkImageType::IndexType pixelIndex;
    bool marked;
    int value;
};

UnsignedCharImageType::Pointer removeZeros(UnsignedCharImageType::Pointer inputImage);
float calculateWeight(Node origin, Node destin);


class AdjacencyMatrix{
    private:
        int numberOfNodes;
        int rows;
        int columns;
        float  **adjacencyMatrix;
    public:
        AdjacencyMatrix(int rows, int columns)
        {
            this->rows = rows;
            this->columns = columns;
            this->numberOfNodes = rows*columns;
            adjacencyMatrix = new float* [n];
            for(int rowIndex = 0; rowIndex < numberOfNodes; rowIndex++)
            {
                adjacencyMatrix[rowIndex] = new float [n];
                for(int columnIndex = 0; columnIndex < rowIndex; columnIndex++)
                {
                    adjacencyMatrix[rowIndex][columnIndex] = 0;
                }
            }
        }

        void addArc(Node origin, Node destin){
            float weight = calculateWeight(origin, destin);
            adjacencyMatrix[origin.id][destin.id] = weight;
            adjacencyMatrix[destin.id][origin.id] = weight;
            if (destin.id == numberOfNodes)
            {
                origin.marked = true;
            }
        }

        float** getAdjacencyMatrix(){
            return adjacencyMatrix;
        }

        int getNumberOfNodes(){
            return numberOfNodes;
        }

}

UnsignedCharImageType::Pointer removeZeros(UnsignedCharImageType::Pointer inputImage){
    ThresholdFilterType::Pointer thresholdFilter = ThresholdFilterType::New();
    thresholdFilter->SetInput( inputImage );
    thresholdFilter->ThresholdOutside(1,255);
    thresholdFilter->SetOutsideValue(1);
    thresholdFilter->Update();
    return thresholdFilter->GetOutput();
}

float calculateWeight(Node origin, Node destin)
{
    //Se supone que el indice ya viene con valores
    //No hay ceros que indeterminen el logaritmo
    float dissimilarity =  log(origin.value) - log(destin.value);
    if(dissimilarity <0){
        dissimilarity *= -1;
    }

    float ro = 2.5;
    float a = origin.pixelIndex[0] - destin.pixelIndex[0];
    float b = origin.pixelIndex[1] - destin.pixelIndex[1];
    float F_ab = ((a*a) + (b*b)) / 2*ro*ro;
    F_ab = exp(F_ab);
    return F_ab;
}