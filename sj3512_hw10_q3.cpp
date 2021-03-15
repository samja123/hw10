#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main1();
int main2();
vector<int> readWithVector();
vector<int> searchForNumberVector(vector<int> vectorToSearch, int numberToSearch);
int* readWithArrays(int& outArrSize);
int* searchForNumberArray(int* arrayToSearch, int arrSize, int numberToSearch, int& outArrSize);
int main() {
    main1();
    cout<<endl;
    cout<<endl;
    main2();
    return 0;
}

int main1(){
    int* arrayToSearch;
    int ArrSize = 0;
    arrayToSearch = readWithArrays(ArrSize);
    cout<<"Please enter the number you want to search."<<endl;
    int numberToSearch;
    cin>>numberToSearch;
    int* outArr;
    int newArrSize = 0;
    outArr = searchForNumberArray(arrayToSearch, ArrSize, numberToSearch, newArrSize);
    if(newArrSize > 0){
        cout<<numberToSearch<<" shows in lines ";
        for(int i = 0; i < newArrSize; i++){
            cout<<outArr[i] + 1<<", ";
        }
        cout<<"\b";
        cout<<"\b";
        cout<<".";
    }
    else{
        cout<<numberToSearch<<" does not show at all in sequence"<<endl;
    }
    return 0;

}

int* readWithArrays(int& outArrSize){
    int* Arr;
    //textArrSize is the logical size
    int ArrSize, ArrPhysicalSize;
    bool seenNeg1;
    int userInput;
    cout<<"Please enter a sequence of numbers"<<endl;
    cout<<"To end the input, type -1"<<endl;

    Arr = new int[1];
    ArrSize = 0; //has nothing in it
    ArrPhysicalSize = 1; //array starts with capacity of 1

    //unsure how many iterations, use a while loop
    seenNeg1 = false;
    while(seenNeg1 == false){
        cin>>userInput;
        if(userInput == -1){
            seenNeg1 = true;
        }
        else{
            if(ArrSize == ArrPhysicalSize){
                int* newArr;
                newArr = new int[2 * ArrPhysicalSize]; //new large array
                for(int i =0; i < ArrSize; i++){
                    newArr[i] = Arr[i];  // copy in the small array values into large array
                }
                delete [] Arr;
                Arr = newArr;
                ArrPhysicalSize *= 2; // double the size for next time
            }
            //else
            Arr[ArrSize] = userInput;
            ArrSize++;
        }
    }

    outArrSize = ArrSize;
    return Arr;
}

int* searchForNumberArray(int* arrayToSearch, int arrSize, int numberToSearch, int& outArrSize){
    int* Arr;
    Arr = new int[1];
    int j = 0;
    for(int i = 0; i < arrSize; i++) {
        if(numberToSearch == arrayToSearch[i]){
            Arr[j] = i;
            j++;
        }
    }
    outArrSize = j;
    return Arr;
}


int main2(){
    vector<int> numVector;
    numVector = readWithVector();
    cout<<"Please enter the number you want to search."<<endl;
    int numberToSearch;
    cin>>numberToSearch;
    vector<int> outVector;
    outVector = searchForNumberVector(numVector, numberToSearch);
    if(outVector.size() > 0){
        cout<<numberToSearch<<" shows in lines ";
        for(int i = 0; i < outVector.size(); i++){
            cout<<outVector[i] + 1<<", ";
        }
        cout<<"\b";
        cout<<"\b";
        cout<<".";
    }
    else{
        cout<<numberToSearch<<" does not show at all in sequence"<<endl;
    }
    return 0;
}

vector<int> readWithVector() {
    vector<int> numVector;

    cout << "Please enter a sequence of numbers" << endl;
    cout << "To end the input, type -1" << endl;
    int userInput;

    bool seenNeg1;
    while (seenNeg1 == false) {
        cin >> userInput;
        if (userInput == -1) {
            seenNeg1 = true;
        }
        else {
            numVector.push_back(userInput);
        }
    }
    return numVector;
}

vector<int> searchForNumberVector(vector<int> vectorToSearch, int numberToSearch){
    vector<int> outVector;
    for(int i = 0; i < vectorToSearch.size(); i++) {
        if(numberToSearch == vectorToSearch[i]){
            outVector.push_back(i);
        }
    }
    return outVector;
}