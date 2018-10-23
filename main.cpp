#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 400

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}
void max_heapify(int** array,size_t size,int pos){
    int l=0,r=0;
    if((2*pos+1)<size){
        l=(*array)[2*pos+1];
    }
    if((2*pos+2)<size){
        r=(*array)[2*pos+2];
    }
    if(l>(*array)[pos] || r>(*array)[pos]) {
        int temp = (*array)[pos];
        if(l <= r){
            (*array)[pos]=r;
            (*array)[2*pos+2]=temp;
            max_heapify(&(*array),size,2*pos+2);
        }else{
            (*array)[pos]=l;
            (*array)[2*pos+1]=temp;
            max_heapify(&(*array),size,2*pos+1);
        }
    }
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapsort(int* array, size_t size) {
    // TODO
    for(int j=size;j>1;j--){
        for(int i=(j/2)-1;i>=0;i--){
            max_heapify(&array,j,i);
        }
        int tem=array[0];
        array[0]=array[j-1];
        array[j-1]=tem;
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
