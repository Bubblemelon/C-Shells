#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main() {

    double mealCost;
    int tipPercent;
    int taxPercent;

    cin >> mealCost;
    cin >> tipPercent;
    cin >> taxPercent;

    // to print a double! 
    cout.precision(2);
    // cout << std::fixed << mealCost << endl;

    // cout << tipPercent << endl;
    // cout << taxPercent << endl;

    // Complete the solve function below.
    //void solve(double meal_cost, int tip_percent, int tax_percent) {
    
    double tip;
    double tax;

    tip = (double)(mealCost*tipPercent/100);

    // cout << std::fixed << tip << endl;

    tax = (double)(mealCost*taxPercent/100);

    // cout << std::fixed << tax << endl;

    cout << (int)round(mealCost+tip+tax) << endl;

    
    
}
