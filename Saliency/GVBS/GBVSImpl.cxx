#include <iostream>
#include <limits>
#include <cmath>
#include <ctime>
#include <stdlib.h>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkThresholdImageFilter.h"
#include "itkMatrix.h"

typedef itk::Image<unsigned char, 2>  UnsignedCharImageType;
typedef itk::ImageFileReader<UnsignedCharImageType> ImageFileReaderType;
typedef itk::ThresholdImageFilter< UnsignedCharImageType > ThresholdFilterType;

struct Node {
    int row;
    int column;
    int value;
};

UnsignedCharImageType::Pointer removeZeros(UnsignedCharImageType::Pointer inputImage);
float **InitAdjacencyMatrix(int rows, int columns);
float** createAdjacencyMatrix(UnsignedCharImageType::Pointer itkInputImage);
float calculateWeight(Node origin, Node destin, float ro);
float **normalizeEachRowToOne(float **matrix, float *sum, int rows, int columns);
float **arrayToMatrix(float *arr, int rows, int columns);
float getSumatoryOfArray(float *arr, int size);
float *divideArrayByScalar(float *arr, int size, float scalar);
float *copyArray(float *arr, int size);
float **copyMatrix(float **matrix, int rows, int columns);
float getSumatoryOfVector(float **vector, int size);
float **multiplyMatrices(float **mat1, float **mat2, int rowsM1, int columnsM1, int rowsM2, int columnsM2);
float **calculateEigenVector(float **vector, float **matrix, int rowsVector, int columnsVector, int rowsMatrix,
                             int columnsMatrix, int tolerance);
float norm(float value);
float *calculateArrayOfValues(float **adjacencyMatrix, int size);
std::string nodeToString(Node node);
void printMatrix(float **matrix, int rows, int columns);
void printArray(float *arr, int size);
void printTime();


/**************************************************************************************/
UnsignedCharImageType::Pointer removeZeros(UnsignedCharImageType::Pointer inputImage){
    ThresholdFilterType::Pointer thresholdFilter = ThresholdFilterType::New();
    thresholdFilter->SetInput( inputImage );
    thresholdFilter->ThresholdOutside(1,255);
    thresholdFilter->SetOutsideValue(1);
    thresholdFilter->Update();
    return thresholdFilter->GetOutput();
}

/**************************************************************************************/
float **initMatrix(int rows, int columns) {
    int numberOfNodes = rows * columns;
    float **adjacencyMatrix = new float *[numberOfNodes];
    for (int rowIndex = 0; rowIndex < numberOfNodes; rowIndex++) {
        adjacencyMatrix[rowIndex] = new float[numberOfNodes];
        for (int columnIndex = 0; columnIndex < numberOfNodes; columnIndex++) {
            adjacencyMatrix[rowIndex][columnIndex] = 0;
        }
    }
    return adjacencyMatrix;
}
/**************************************************************************************/
float** createAdjacencyMatrix(UnsignedCharImageType::Pointer itkInputImage, float ro){
    UnsignedCharImageType::RegionType region = itkInputImage->GetLargestPossibleRegion();
    UnsignedCharImageType::SizeType regionSize = region.GetSize();
    
    int r = regionSize[0];
    int c = regionSize[1];

    Node origin;
    Node destin;
    int adjacencyRow = 0;
    int adjacencyColumn = 0;

    float **adjacencyMatrix = initMatrix(r, c);
    for (unsigned int rowIndex = 0; rowIndex < r; rowIndex++) {
        for (unsigned int columnIndex = 0; columnIndex < c; columnIndex++) {
            UnsignedCharImageType::IndexType pixelIndex;
            pixelIndex[0] = rowIndex;
            pixelIndex[1] = columnIndex;
            origin.row = rowIndex;
            origin.column = columnIndex;
            origin.value = (int)itkInputImage->GetPixel(pixelIndex);
            float weight = 0;
            for (unsigned int relativeRowIndex = 0; relativeRowIndex < r; relativeRowIndex++) {
                for (unsigned int relativeColumnIndex = 0; relativeColumnIndex < c; relativeColumnIndex++) {
                    UnsignedCharImageType::IndexType pixelIndexAux;
                    pixelIndexAux[0] = relativeRowIndex;
                    pixelIndexAux[1] = relativeColumnIndex;
                    destin.row = relativeRowIndex;
                    destin.column = relativeColumnIndex;
                    destin.value = (int)itkInputImage->GetPixel(pixelIndexAux);
                    weight = calculateWeight(origin, destin,ro);
                    adjacencyMatrix[adjacencyRow][adjacencyColumn] = weight;
                    adjacencyRow++;
                    if (adjacencyRow > (r * c) - 1) {
                        adjacencyRow = 0;
                    }
                }
            }
            adjacencyColumn++;
        }
    }

    return adjacencyMatrix;
}

/**************************************************************************************/
float calculateWeight(Node origin, Node destin, float ro) {
    
    float dissimilarity = (float) log(origin.value) - (float) log(destin.value);
    if (dissimilarity < 0) {
        dissimilarity *= -1;
    }

    if(ro <= 0){
        ro = 2.5;
    }

    float a = origin.row - destin.row;
    float b = origin.column - destin.column;
    float F_ab = ((a * a) + (b * b)) / (2 * ro * ro);
    float F_abExp = (float) exp(-F_ab);

    return dissimilarity*F_abExp;
}

/**********************************************************************************************/
float **normalizeEachRowToOne(float **matrix, float *sum, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            matrix[row][column] /= sum[row];
        }
    }
    return matrix;
}

/**********************************************************************************************/
float **arrayToMatrix(float *arr, int rows, int columns) {
    float **matrix = new float *[rows];
    int arrIndex = 0;
    for (int row = 0; row < rows; row++) {
        matrix[row] = new float[columns];
        for (int column = 0; column < columns; column++) {
            matrix[row][column] = arr[arrIndex];
            arrIndex++;
        }
    }
    return matrix;
}

/***************************************************************/
float *createArrayOfSameValue(int size, float value) {
    float *arr = new float[size];
    for (int index = 0; index < size; index++) {
        arr[index] = value;
    }
    return arr;
}

/***************************************************************/
float *matrixToArray(float **matrix, int rows, int columns) {
    float *arr = new float[rows * columns];
    int arrayIndex = 0;
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            arr[arrayIndex] = matrix[row][column];
            arrayIndex++;
        }
    }
    return arr;
}

/***************************************************************/
float getSumatoryOfArray(float *arr, int size) {
    float sum = 0;
    for (int index = 0; index < size; index++) {
        sum += arr[index];
    }
    return sum;
}

/***************************************************************/
float getSumatoryOfVector(float **vector, int size) {
    float sum = 0;
    for (int index = 0; index < size; index++) {
        sum += vector[index][0];
    }
    return sum;
}

/***************************************************************/
float *divideArrayByScalar(float *arr, int size, float scalar) {
    float *auxiliarArr = new float[size];
    for (int index = 0; index < size; index++) {
        auxiliarArr[index] = arr[index] / scalar;
    }
    return auxiliarArr;
}

/***************************************************************/
float **divideVectorByScalar(float **arr, int size, float scalar) {
    float **auxiliarArr = new float *[size];
    for (int index = 0; index < size; index++) {
        auxiliarArr[index] = new float[1];
        auxiliarArr[index][0] = arr[index][0] / scalar;
    }
    return auxiliarArr;
}

/***************************************************************/
float *copyArray(float *arr, int size) {
    float *auxiliarArr = new float[size];
    for (int index = 0; index < size; index++) {
        auxiliarArr[index] = arr[index];
    }
    return auxiliarArr;
}

/***************************************************************/
float **copyMatrix(float **matrix, int rows, int columns) {
    float **newMatrix = new float *[rows];
    for (int row = 0; row < rows; row++) {
        newMatrix[row] = new float[columns];
        for (int column = 0; column < columns; column++) {
            newMatrix[row][column] = matrix[row][column];
        }
    }
    return newMatrix;
}

/***************************************************************/
float **multiplyMatrices(float **mat1, float **mat2, int rowsM1, int columnsM1, int rowsM2, int columnsM2) {
    float **newMatrix = new float *[rowsM1];
    if (columnsM1 != rowsM2) {
        std::cerr << "Impossible to multiply the matrices" << std::endl;

    } else {
        for (int row = 0; row < rowsM1; row++) {
            newMatrix[row] = new float[columnsM2];
            for (int columnM2 = 0; columnM2 < columnsM2; columnM2++) {
                for (int columnM1 = 0; columnM1 < columnsM1; columnM1++) {
                    newMatrix[row][columnM2] += mat1[row][columnM1] * mat2[columnM1][columnM2];
                }
            }
        }
    }
    return newMatrix;
}

/***************************************************************/
float **calculateEigenVector(float **vector, float **matrix, int rowsVector, int columnsVector, int rowsMatrix,
                             int columnsMatrix, int tolerance) {
    int iterations = 0;
    float difference = 1;
    float **copyOfVector = copyMatrix(vector, rowsVector, columnsVector);
    float **copyOfVector2 = copyMatrix(vector, rowsVector, columnsVector);

    while (difference > tolerance) {
        copyOfVector = copyMatrix(vector, rowsVector, columnsVector);
        copyOfVector2 = copyMatrix(copyOfVector, rowsVector, columnsVector);
        vector = multiplyMatrices(matrix, vector, rowsMatrix, columnsMatrix, rowsVector, columnsVector);
        difference = norm(
                getSumatoryOfVector(vector, rowsVector * columnsVector)
                - getSumatoryOfVector(copyOfVector, rowsVector * columnsVector)
        );
        iterations++;
        float sum = getSumatoryOfVector(vector, rowsVector * columnsVector);
        if (sum >= 0 && sum < std::numeric_limits<float>::infinity()) {
            continue;
        } else {
            vector = copyMatrix(copyOfVector2, rowsVector, columnsVector);
            break;
        }
    }

    float sum = getSumatoryOfVector(vector, rowsVector * columnsVector);
    vector = divideVectorByScalar(vector, rowsVector * columnsVector, sum);
    return matrix;
}

/***************************************************************/
float norm(float value) {
    if (value < 0) {
        return value * (-1);
    } else {
        return value;
    }
}

/**********************************************************************************************/
float *calculateArrayOfValues(float **adjacencyMatrix, int size) {

    float *sum = new float(size);
    try {
        for (int row = 0; row < size; row++) {
            float rowSum = 0;
            for (int column = 0; column < size; column++) {
                rowSum += adjacencyMatrix[row][column];
                //std::cout << rowSum << std::endl;
            }
            sum[row] = rowSum;
        }
        std::cout << sizeof(sum) << std::endl;
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory exception " << e.what() << std::endl;
    }

    return sum;
}

//******************************************UTIL METHODS**************************************
/**********************************************************************************************/
std::string nodeToString(Node node) {
    return std::to_string(node.row) + " , " + std::to_string(node.column) + " v: " + std::to_string(node.value) +
           "    ";
}

/**********************************************************************************************/
void printMatrix(float **matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            std::cout<< row << " , " << column <<" -> " <<matrix[row][column] << std::endl;
        }
        std::cout << std::endl;
    }
}

/**********************************************************************************************/
void printArray(float *arr, int size) {
    std::cout << std::endl << "---" << std::endl;
    for (int index = 0; index < size; index++) {
        std::cout << arr[index] << "  ";
    }
    std::cout << std::endl << "---" << std::endl;
}

/**********************************************************************************************/
void printTime() {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    std::cout << (now->tm_year + 1900) << "-" << (now->tm_mon + 1) << "-" << now->tm_mday << " " << now->tm_hour
              << ":" << now->tm_min << ":" << now->tm_sec << std::endl;
}

/**********************************************************************************************/
int main(int argc, char *argv[]) {
    printTime();
    std::string inputFileName = argv[1];
    float tolerance = atof(argv[2]);
    float ro = atof(argv[3]);

    ImageFileReaderType::Pointer reader = ImageFileReaderType::New();
    reader->SetFileName(inputFileName);
    reader->Update();

    UnsignedCharImageType::Pointer itkInputImage = removeZeros(reader->GetOutput());
    UnsignedCharImageType::RegionType region = itkInputImage->GetLargestPossibleRegion();
    UnsignedCharImageType::SizeType regionSize = region.GetSize();
    
    int r = regionSize[0];
    int c = regionSize[1];

    float **adjacencyMatrix = createAdjacencyMatrix(itkInputImage, ro);
    float *sum = calculateArrayOfValues(adjacencyMatrix, r * c);
    float **normalizedMatrix = normalizeEachRowToOne(adjacencyMatrix, sum, r * c, r * c);
    float *arrayOfOnes = createArrayOfSameValue(r * c, 1);
    float scalar = getSumatoryOfArray(arrayOfOnes, r * c);
    float *initialVector = divideArrayByScalar(arrayOfOnes, r * c, scalar);
    float **vectorToMatrix = arrayToMatrix(initialVector, r * c, 1);
    float **eigenVector = calculateEigenVector(vectorToMatrix, normalizedMatrix, r * c, 1, r * c, r * c, tolerance);
    //This is the answer
    float **GBVS = arrayToMatrix(matrixToArray(eigenVector, r * c, 1), r, c);
    printMatrix(GBVS, r, c);
    printTime();
    return EXIT_SUCCESS;
}
