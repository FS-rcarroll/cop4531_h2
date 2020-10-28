#include <iostream>
#include <fstream>
using namespace std;

int LCS(string s1, string s2, int l1, int l2){
    if(l1 == 0 || l2 == 0){
        return 0;
    }
    if(s1[l1-1] == s2[l2-1]){
        return 1 + LCS(s1, s2, l1-1, l2-1);
    }else{
        return max(LCS(s1, s2, l1, l2-1), LCS(s1, s2, l1-1, l2));
    }
}

int main(int argc, char* argv[])
{
    cout << "Hello, World!" << endl;
    cout << "Files inputted: " << argv[1] << " and " << argv[2]<< endl;

    string string1;
    string string2;

    ifstream file1;
    file1.open (argv[1]);
    ifstream file2;
    file2.open (argv[2]);
    if(!(file1 && file2)){
        cout << "Error: Unable to load one or both input files." << endl;
    }else{
        getline(file1, string1);
        getline(file2, string2);
        cout << "Contents of "<< argv[1] << ":" << string1 << endl;
        cout << "Contents of "<< argv[2] << ":" << string2 << endl;
        int output = LCS(string1, string2, string1.length(), string2.length() );
        cout << "Output: " << output << endl;
    }
    file1.close();
    file2.close();


    return 0;
}


