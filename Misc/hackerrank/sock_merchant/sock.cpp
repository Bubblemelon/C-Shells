#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
     

    int n; // number of socks

    cin >> n;
    cout << n << endl;

    vector<int> ar(n); // for each sock

    for(int i =0; i < n; i++){
      cin >> ar[i];
      cout << ar[i] << " ";
    }

    cout << endl;

// Complete the sockMerchant function below.
//int sockMerchant(int n, vector<int> ar) {


    vector<int> paired(n/2, n+1); // paired (should be even)
    // populate with an index number not reachable
    int count=0;

 

    for(int j = 0; j < ar.size(); j++){

        // check if index has a pair
        // proceed if no pair
        if( find(paired.begin(), paired.end(), j) == paired.end() ){

            // does comparing
            for(int k = j+1; k < ar.size(); k++)
            {
                //pair found
                if(ar[j] == ar[k]){
                    paired[count] = k;
                    count++;
                    break;
                }
            }
        }
    }

    // to save indexes that were already matched
    for(auto p : paired){
      cout << p << " ";
    }
    cout << endl;   

    cout << count;

}

    // int i = 0;
        
    //     for(int ii=0; ii < paired.size(); ii++, i++){

    //         if(i == paired.at(ii)){
    //             i++;
                
    //             cout << "breakkig" << endl;
                
    //             break;
                
    //         } else {
    //             for(int j = i + 1; j < ar.size(); j++){
                    
    //                 cout << "ar[" << i << "] " << "=" << ar[i] << endl;
    //                 cout << "ar[" << j << "]" << "=" << ar[j] << endl;
                   
    //                 if(ar.at(i) == ar.at(j)){
                        
    //                     cout << "matched" << endl; 
                        
    //                     paired[ar.at(j)];
    //                     count++;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    