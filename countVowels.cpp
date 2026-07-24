#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#include <vector>
#include <string>
int main(){
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E' , 'I', 'O' , 'U'};
    string check = "My name is Triyog Shrestha";
    int count = 0;

    for (char i : check){
        if (find(vowels.begin(), vowels.end(), i) != vowels.end()){
            ++count;
        }
    }

    cout << count << endl;
}