#include "chemaphy.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Statistics stats;
    vector<double> vec = {1,2,3,4,5};
    cout<<stats.geometric_mean(vec)<<endl;
    cout<<stats.harmonic_mean(vec)<<endl;
    cout<<stats.mean(vec)<<endl;
    cout<<stats.variance(vec,'p')<<endl;
    cout<<stats.variance(vec,'s')<<endl;
    // cout<<stats.skewness(vec)<<endl;
    // cout<<stats.kurtosis(vec)<<endl;
    // cout<<stats.percentile(vec, 50)<<endl;
    // cout<<stats.percentile(vec, 90)<<endl;
    return 0;
}


