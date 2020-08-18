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
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main() {
  cout << "Enter the number of elements in array:";
  cin >> size;
  int data[size];
  cout << "Enter the elements :";
  for (int count = 0; count < size; count++)
    cin >> data[count];
  quickSort(data, 0, size - 1);
  cout << "Sorted array in ascending order: \n";
  printArray(data, size);
}