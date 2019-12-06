#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>



using namespace std;
class SortingAlgorithms
{
  void bubbleSort(int myArray[]);
  void selectionSort(int arr[], int size);
  void insertionSort(double arr[]);
  void merge(int arr[], int start, int mid, int end);
  void mergeSort(int arr[], int start, int end);
  int partition(int a[], int low, int high);
  int randomPivotPartition(int a[], int low, int high);
  int quickSort(int a[], int low, int high);
};


int main(int argc, char const *argv[])
{
  // int array[10] = {2,45,1,6,8,9,43,7,32,99};
  // bubbleSort(array);
  //
  // int arraysecond[10] = {2,45,1,6,8,9,43,7,32,99};
  // selectionSort(arraysecond,10);
  //
  // double arraythird[10] = {2,45,1,6,8,9,43,7,32,99};
  // insertionSort(arraythird);
  //
  // int arrayfourth[10] = {2,45,1,6,8,9,43,7,32,99};
  // mergeSort(arrayfourth,0,9);
  //
  // int arrayfifth[10] = {2,45,1,6,8,9,43,7,32,99};
  // quickSort(arrayfifth,0,9);
  //
  // cout << "------------------------------------------------------------------" << endl;
  // cout << "Array: Bubble Sort" << endl;
  // cout << "------------------------------------------------------------------" << endl;
  //
  // for (int i = 0; i <10; ++i)
  // {
  //   std::cout << array[i] << endl;
  // }
  //
  // cout << "------------------------------------------------------------------" << endl;
  // cout << "Array: Selection Sort" << endl;
  // cout << "------------------------------------------------------------------" << endl;
  //
  // for (int i = 0; i <10; ++i)
  // {
  //   cout << arraysecond[i] << endl;
  // }
  //
  // cout << "------------------------------------------------------------------" << endl;
  // cout << "Array: Insertion Sort" << endl;
  // cout << "------------------------------------------------------------------" << endl;
  //
  // for (int i = 0; i <10; ++i)
  // {
  //   cout << arraythird[i] << endl;
  // }
  //
  // cout << "------------------------------------------------------------------" << endl;
  // cout << "Array: Merge Sort" << endl;
  // cout << "------------------------------------------------------------------" << endl;
  //
  // for (int i = 0; i <10; ++i)
  // {
  //   cout << arrayfourth[i] << endl;
  // }
  //
  // cout << "------------------------------------------------------------------" << endl;
  // cout << "Array: Quick Sort" << endl;
  // cout << "------------------------------------------------------------------" << endl;
  //
  // for (int i = 0; i <10; ++i)
  // {
  //   cout << arrayfifth[i] << endl;
  // }
    SortingAlgorithms sort;
    ifstream inFile;
    ofstream outFile;
    string line = " ";
    bool firstline = true;
    int size;
    int index = 0;

    // Writing random numbers(doubles) to a file
    outFile.open("mattNwerem.txt");
    outFile << 10000 << endl;
    for(int i = 0; i < 10000; i++)
    {
      outFile << static_cast <float> (rand())/ static_cast <float> (RAND_MAX) << endl;
    }
    outFile.close();


    inFile.open(argv[1]);
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
    double insertArray[MAX_ARRAY_SIZE];
    double selectionArray[MAX_ARRAY_SIZE];
    double mergeArray[MAX_ARRAY_SIZE];

    for(int i = 0; i < MAX_ARRAY_SIZE; ++i)
    {
      bubbleArray[i] = 0;
      quickArray[i] = 0;
      insertArray[i] = 0;
      selectionArray[i] = 0;
      mergeArray[i] = 0;
    }

    while (inFile >> line)
    {
      bubbleArray[index] = stod(line);
      quickArray[index] = stod(line);
      insertArray[index] = stod(line);
      selectionArray[index] = stod(line);
      mergeArray[i] = stod(line);
      index++
    }

    inFile.close();

  return 0;
}

void bubbleSort(int myArray[])
{
  for(int i = 0; i < MAX_ARRAY_SIZE; ++i)
  {
    for (int j = 0; j < MAX_ARRAY_SIZE-1; ++j)
    {
      if(myArray[j] > myArray[j + 1])
      {
        int temp = 0;
        temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void selectionSort(int arr[], int size)
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

void insertionSort(double arr[])
{
  for(int j = 1; j < MAX_ARRAY_SIZE; ++j)//gonna need to change 10 to size for assignment
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

void merge(int arr[], int start, int mid, int end)
{
	int temp[end - start + 1]; 	// create a temp array
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
void mergeSort(int arr[], int start, int end)
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
int partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;

	// Getting index of the pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
      int temp;
      temp = a[i];
      a[i] = a[index];
      a[index] = temp;
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
  int temp;
  temp = a[pivot];
  a[pivot] = a[index];
  a[index] = temp;

	return index;
}

// Random selection of pivot.
int randomPivotPartition(int a[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);

	// Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
  int tmp = 0;
  tmp = a[high];
  a[high] = a[pvt];
  a[pvt] = tmp;

	return partition(a, low, high);
}

int quickSort(int a[], int low, int high)
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
