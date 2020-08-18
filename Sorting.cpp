#include <iostream>

using namespace std;

int size;
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int array[], int size) {
  for (int indexToswap = 0; indexToswap < size; indexToswap++)
    cout << array[indexToswap] << " ";
  cout << endl;
}

/* =================================== QUICK SORT =================================== */ 

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int indexToswap = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      indexToswap++;
      swap(&array[indexToswap], &array[j]);
    }
  }
  swap(&array[indexToswap + 1], &array[high]);
  return (indexToswap + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int partitionIndex = partition(array, low, high);
    quickSort(array, low, partitionIndex - 1);
    quickSort(array, partitionIndex + 1, high);
  }
}

/* =================================== BUBBLE SORT =================================== */

void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) 
        swap(&array[i], &array[i + 1]);
    }
  }
}

/* =================================== INSERTION SORT =================================== */

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

int main() {
  cout << "Enter the number of elements in array: ";
  cin >> size;
  int data[size];
  cout << "Enter the elements:" << endl;
  for (int count = 0; count < size; count++)
    cin >> data[count];
  int choice;  
  cout << "Enter your choice to select a sorting technique.\n \n1--> Quick Sort \n2--> Bubble Sort \n3--> Insertion Sort\n \nYour Choice: ";
 cin >> choice;
 switch (choice) {
  case 1:
    cout << "\nUsing Quick Sort ...." << endl;
    quickSort(data, 0, size - 1);
  break;
  case 2:
    cout << "\nUsing Bubble Sort ...." << endl;
    bubbleSort(data, size - 1);
  break;
  case 3:
    cout << "\nUsing Insertion Sort ...." << endl;
    insertionSort(data, size - 1);
  break;  
  default:
    cout << "\nInvalid Input, Using Quick Sort ...." << endl ;
    quickSort(data, 0, size - 1);
    break;
 }
  
  cout << "\nSorted array in ascending order:";
  printArray(data, size);
}