#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    string userInput;

    cout<<"Please type a sentence:"<<endl;
    getline(cin, userInput);
    int wordsArrSize;
    string* sentenceArray;

    sentenceArray = createWordsArray(userInput, wordsArrSize);

    for(int i = 0; i < wordsArrSize; i++){
        cout<<i+1<<". "<<sentenceArray[i]<<endl;
    }

    return 0;
}
string* createWordsArray(string sentence, int& outWordsArrSize){
    int wordsArrPhysicalSize;

    string* wordsArray; //new string that will have each word in its own spot
    wordsArray = new string[1]; //new string of size 1

    wordsArrPhysicalSize = 1; //array starts with capacity of 1
    string word;

    int arrSize = 0;
    int sentenceLength = sentence.length();
    int i = 0;

    while(sentenceLength >= 0){
        if(sentence[i] == ' ' || sentence[i] == '\0') {
            if (arrSize > 0) {
                string *newWordsArr;
                newWordsArr = new string[wordsArrPhysicalSize * 2];//new large array
                for (int i = 0; i < arrSize; i++)
                    newWordsArr[i] = wordsArray[i];// copy in the small array values into large array
                delete[]wordsArray;
                wordsArray = newWordsArr;
                wordsArrPhysicalSize *= 2;
                }
            wordsArray[arrSize] = word;
            arrSize++;
            word = "";
                }
        else{
            word += sentence[i];
        }

        i++;
        sentenceLength--;

        }
        outWordsArrSize = arrSize;
        return wordsArray;
    }