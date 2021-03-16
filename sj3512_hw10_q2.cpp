#include <iostream>
#include <string>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int arrSize;

    cout<<"Please give the size of your array: "<<endl;
    cin>>arrSize;
    int arr[arrSize];
    cout<<"Please type in that many numbers separated by a space: "<<endl;
    for(int i = 0; i < arrSize; i++){
        cin>>arr[i];
    }

    int resArrSize = 0;
    int* outArr = findMissing(arr, arrSize, resArrSize);
    cout<<"New array size is: "<<resArrSize<<endl;
    cout<<"New array is: ";
    for(int i = 0; i < resArrSize; i++){
        cout<<outArr[i]<<" ";
    }

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int* newArr;
    int sentArrSize = n;
    newArr = new int[sentArrSize*2];

    int arrSize = 0;
    int* tempArr;

    tempArr = new int[sentArrSize*2];

    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    for(int i = 0; i < n; i++){
        tempArr[arr[i]] = -1;
    }


    int j = 0;
    for (int i = 0; i < max; i++) {
        if(tempArr[i] != -1) {
            newArr[j] = i;
            arrSize++;
            j++;
        }
    }
    delete [] tempArr;
    resArrSize = arrSize;
    return newArr;
}
