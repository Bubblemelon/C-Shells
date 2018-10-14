#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//given
// vector<int> X = {0, 4, 6, 7, 10, 16}; //coordinates x
// vector<int> Y = {0, 1, 2, 9, 12, 20}; //coordinates y
// (0,0) , (4,1) , (6,2) ...
// returns 24

// for example
// vector<int> X = {0, 4}; //coordinates x
// vector<int> Y = {0, 1}; //coordinates y
// returns 4

// vector<int> X = {0, 4, 6}; //coordinates x
// vector<int> Y = {0, 1, 2}; //coordinates y
// returns 6

// vector<int> X = {0, 4, 6, 7}; //coordinates x
// vector<int> Y = {0, 1, 2, 9}; //coordinates y
// returns 13

// vector<int> X = {0, 4, 6, 7, 10}; //coordinates x
// vector<int> Y = {0, 1, 2, 9, 12}; //coordinates y
// returns 16

// compile:
// g++ MinStepInfinteGrid -o MSIG
// test:
// ./MSIG < sometestfile.in

// question source
// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int main() {


        // test inputs
        // vector<int> X = {-7, -13}; //coordinates x
        // vector<int> Y = {1, -5}; //coordinates y
        // return 6


        //find min number of steps, start from first point
        //find the distance between two points

        typedef struct {
                int dx;
                int dy;
        }dXY;

        // max difference = total steps to return
        int max = 0;

        // to save difference between 2 points
        // size of this vector, n
        int n =0;

        // check for uneven sizes
        if(X.size() % 2 == 1) {
                n = (X.size() / 2);
                n *= 2;
        } else {
                n = X.size() -1;
        }
        vector<dXY> difXY (n);
        dXY change;

        for(int i = 0; i < difXY.size(); i++) {

                change.dx =  X[i] - X[i+1];

                if(change.dx <0 ) {
                        change.dx = change.dx * (-1);
                }

                change.dy = Y[i] - Y[i+1];

                if(change.dy <0 ) {
                        change.dy = change.dy * (-1);
                }

                difXY[i] = change;

                cout << change.dx << ",";
                cout << change.dy << endl;
        }

        cout << difXY.size() << endl;
        //find the max difference of either x or y
        for(int j = 0; j < difXY.size(); j++) {

                if( difXY[j].dx > difXY[j].dy )
                {
                        max += difXY[j].dx;
                } else {
                        max += difXY[j].dy;
                }
        }
        cout << max << endl;
        // return max;
}
