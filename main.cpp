#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>



using namespace std;
class SortingAlgorithms
{
  public:
    void bubbleSort(double myArray[], int size);
    void selectionSort(double arr[], int size);
    void insertionSort(double arr[], int size);
    void merge(double arr[], int start, int mid, int end);
    void mergeSort(double arr[], int start, int end);
    int partition(double a[], int low, int high);
    int randomPivotPartition(double a[], int low, int high);
    int quickSort(double a[], int low, int high);
};


int main(int argc, char const *argv[])
{
    SortingAlgorithms sort;
    ifstream inFile;
    ofstream outFile;
    string line = " ";
    bool firstLine = true;
    int index = 0;
    int MAX_ARRAY_SIZE = 0;

    // Writing random numbers(doubles) to a file
    outFile.open("mattNwerem.txt");
    outFile << 100000 << endl;
    for(int i = 0; i < 100000; i++)
    {
      outFile << static_cast <float> (rand())/ static_cast <float> (RAND_MAX) << endl;
    }
    outFile.close();

    inFile.open("mattNwerem.txt");
    if(!inFile)
    {
      cout << "Unable to open file: " << argv[1] << endl;
      cout << "Exiting..." << endl;
      exit(1);
    }

    while (inFile >> line)
    {
      if(firstLine == true)
      {
        MAX_ARRAY_SIZE = stoi(line);
        firstLine = false;
        break;
      }
    }

    double bubbleArray[MAX_ARRAY_SIZE];
    double quickArray[MAX_ARRAY_SIZE];
    double insertionArray[MAX_ARRAY_SIZE];
    double selectionArray[MAX_ARRAY_SIZE];
    double mergeArray[MAX_ARRAY_SIZE];

    for(int i = 0; i < MAX_ARRAY_SIZE; ++i)
    {
      bubbleArray[i] = 0;
      quickArray[i] = 0;
      insertionArray[i] = 0;
      selectionArray[i] = 0;
      mergeArray[i] = 0;
    }

    while (inFile >> line)
    {
      bubbleArray[index] = stod(line);
      quickArray[index] = stod(line);
      insertionArray[index] = stod(line);
      selectionArray[index] = stod(line);
      mergeArray[index] = stod(line);
      index++;
    }
    inFile.close();

    clock_t bubbleTimeStart = clock();
    sort.bubbleSort(bubbleArray, MAX_ARRAY_SIZE);
    clock_t bubbleTimeEnd = clock();
    double cpu_time_used = ((double)(bubbleTimeEnd - bubbleTimeStart)) / CLOCKS_PER_SEC;

    clock_t selectionTimeStart = clock();
    sort.selectionSort(selectionArray, MAX_ARRAY_SIZE);
    clock_t selectionTimeEnd = clock();
    double cpu_time_used2 = ((double)(selectionTimeEnd - selectionTimeStart)) / CLOCKS_PER_SEC;

    clock_t insertionTimeStart = clock();
    sort.insertionSort(insertionArray, MAX_ARRAY_SIZE);
    clock_t insertionTimeEnd = clock();
    double cpu_time_used3 = ((double)(insertionTimeEnd - selectionTimeStart)) / CLOCKS_PER_SEC;

    clock_t mergeTimeStart = clock();
    sort.mergeSort(mergeArray, 0, MAX_ARRAY_SIZE);
    clock_t mergeTimeEnd = clock();
    double cpu_time_used4 = ((double)(mergeTimeEnd - mergeTimeStart)) / CLOCKS_PER_SEC;

    clock_t quickTimeStart = clock();
    sort.quickSort(mergeArray, 0, MAX_ARRAY_SIZE);
    clock_t quickTimeEnd = clock();
    double cpu_time_used5 = ((double)(quickTimeEnd - quickTimeStart)) / CLOCKS_PER_SEC;


    cout << "------------------------------------------------------------------" << endl;
    cout << "Sorting Algorithm: Bubble Sort" << endl << endl;
    cout << "Time Sort Started: " << bubbleTimeStart << endl;
    cout << "Time Sort Ended: " << bubbleTimeEnd << endl;
    cout << "CPU Time Used: " << cpu_time_used << endl;
    cout << "------------------------------------------------------------------" << endl << endl;

    cout << "------------------------------------------------------------------" << endl;
    cout << "Sorting Algorithm: Selection Sort" << endl << endl;
    cout << "Time Sort Started: " << selectionTimeStart  << endl;
    cout << "Time Sort Ended: " << selectionTimeEnd << endl;
    cout << "CPU Time Used: " << cpu_time_used2 << endl;
    cout << "------------------------------------------------------------------" << endl << endl;

    cout << "------------------------------------------------------------------" << endl;
    cout << "Sorting Algorithm: Insertion Sort" << endl << endl;
    cout << "Time Sort Started: " << insertionTimeStart  << endl;
    cout << "Time Sort Ended: " << insertionTimeEnd << endl;
    cout << "CPU Time Used: " << cpu_time_used3 << endl;
    cout << "------------------------------------------------------------------" << endl << endl;

    cout << "------------------------------------------------------------------" << endl;
    cout << "Sorting Algorithm: Merge Sort" << endl << endl;
    cout << "Time Sort Started: " << mergeTimeStart  << endl;
    cout << "Time Sort Ended: " << mergeTimeEnd << endl;
    cout << "CPU Time Used: " << cpu_time_used4 << endl;
    cout << "------------------------------------------------------------------" << endl << endl;

    cout << "------------------------------------------------------------------" << endl;
    cout << "Sorting Algorithm: Quick Sort" << endl << endl;
    cout << "Time Sort Started: " << quickTimeStart  << endl;
    cout << "Time Sort Ended: " << quickTimeEnd << endl;
    cout << "CPU Time Used: " << cpu_time_used5 << endl;
    cout << "------------------------------------------------------------------" << endl << endl;





  return 0;
}

void SortingAlgorithms::bubbleSort(double myArray[], int size)
{
  for(int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size - 1; ++j)
    {
      if(myArray[j] > myArray[j + 1])
      {
        double temp = 0;
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void SortingAlgorithms::selectionSort(double arr[], int size)
{
  int i, j, minIndex, tmp;
  for (i = 0; i < size - 1; i++)
  {
    minIndex = i; //get index of minimum data
    for(j = i + 1; j < size; j++)
    {
      if(arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }

    if(minIndex != i)
    {
      tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
}

void SortingAlgorithms::insertionSort(double arr[], int size)
{
  for(int j = 1; j < size; ++j)//gonna need to change 10 to size for assignment
  {
    double temp = arr[j]; // Store marked item
    int k = j; //where to start shifting
    while(k > 0 && arr[k-1] >= temp) //while the thing to the left is larger, shift
    {
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp; //put marked item in right spot
  }
}

void SortingAlgorithms::merge(double arr[], int start, int mid, int end)
{
	double temp[end - start + 1]; 	// create a temp array
	int i = start, j = mid+1, k = 0; 	// crawlers for both intervals and for temp

	// traverse both arrays and in each iteration add smaller of both elements in temp
	while(i <= mid && j <= end)
  {
		if(arr[i] <= arr[j])
    {
			temp[k] = arr[i];
			k += 1; i += 1;
		}
		else
    {
			temp[k] = arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval
	while(i <= mid) {
		temp[k] = arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval
	while(j <= end)
  {
		temp[k] = arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1)
  {
		arr[i] = temp[i - start];
	}
}

// start and end = the starting and ending index of current interval of Arr
void SortingAlgorithms::mergeSort(double arr[], int start, int end)
{
	if(start < end)
  {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

// Partitioning the array on the basis of values at high as pivot value.
int SortingAlgorithms::partition(double a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;

	// Getting index of the pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
      double temp;
      temp = a[i];
      a[i] = a[index];
      a[index] = temp;
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
  double temp;
  temp = a[pivot];
  a[pivot] = a[index];
  a[index] = temp;

	return index;
}

// Random selection of pivot.
int SortingAlgorithms::randomPivotPartition(double a[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);

	// Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
  double tmp = 0;
  tmp = a[high];
  a[high] = a[pvt];
  a[pvt] = tmp;

	return partition(a, low, high);
}

int SortingAlgorithms::quickSort(double a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
		// Partitioning array using randomized pivot.
		pindex = randomPivotPartition(a, low, high);
		// Recursively implementing QuickSort.
		quickSort(a, low, pindex-1);
		quickSort(a, pindex+1, high);
	}
	return 0;
}
