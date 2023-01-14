/*
    version-2023.01.14
    Created by Sahil Rajwar
    Date: 11th January 2023
    HomePage: https://www.github.com/Sahil-Rajwar-2004/statslib-cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <string>
#include <climits>
using namespace std;


void display(vector<double> &data){
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

string author = "Sahil Rajwar";
string version = "2023.01.14";
string homepage = "https://github.com/Sahil-Rajwar-2004/stats-lib";

int error = -1;

class Mathematics{
    public:
        int factorial(int num){
            if(num == 0){
                return 1;
            }else if(num < 0){
                return error;
            }return num*factorial(num-1);
        }

        int permutation(int n,int r){
            float res = factorial(n)/factorial(n-r);
            return res;
        }

        int combination(int n,int r){
            float res = factorial(n)/(factorial(r)*factorial(n-r));
            return res;
        }

        int absolute(float n){
            if(n<0){
                return -n;
            }else if(n == 0){
                return 0;
            }else{
                return n;
            }
        }
};


class Statistics{
    public:
        Mathematics maths;
        double max(vector<double> &data){
            double max = INT_MIN;
            for(int i=0;i<data.size();i++){
                if(max<data[i]){
                    max = data[i];
                }
            }return max;
        }

        double min(vector<double> &data){
            double min = INT_MAX;
            for(int i=0;i<data.size();i++){
                if(min>data[i]){
                    min = data[i];
                }
            }return min;
        }

		double sum(vector<double> &data){
			float x = 0.0;
			for(int i=0;i<data.size();i++){
				x += data[i];
			}return x;
		}

        double product(vector<double> &data){
            float p = 1.0;
            for(int i=0;i<data.size();i++){
                p *= data[i];
            }return p;
        }

		double len(vector<double> &data){
			return data.size();
		}
		
        double mean(vector<double> &data){
            float sum = 0.0;
            for(int i=0; i<data.size(); i++){
                sum += data[i];
            }return sum/data.size();
        }

        double median(vector<double> &data){
            sort(data.begin(),data.end());
            if(data.size()%2==1){
                return data[data.size()/2];
            }else{
                int mid = data.size()/2;
                double x = (data[mid-1] + data[mid])/2.0;
                return x;
            }
        }

        double mode(vector<double> &data){
            map<double, double> freq;
            for(const auto&x:data){
                ++freq[x];
            }
            int mode = 0;
            int mode_freq = 0;
            for(const auto& x: freq){
                if(x.second>mode_freq){
                    mode = x.first;
                    mode_freq = x.second;
                }
            }return mode;
        }

        double range(vector<double> &data){
            int len = data.size();
            int max_val = data[0];
            int min_val = data[0];
            for(int i=0;i<len;i++){
                if(data[i]>max_val){
                    max_val = data[i];   
                }
                if(data[i]<min_val){
                    min_val = data[i];
                }
            }return max_val-min_val;
        }

		double harmonic_mean(vector<double> &data){
			float sum = 0.0;
			for(int i=0;i<data.size();i++){
                if(data[i] != 0){
				    float a = 1/data[i];
				    sum += a;
                }else{
                    return error;
                }
			}
			return data.size()/sum;
		}

		double geometric_mean(vector<double> &data){
            double product = accumulate(data.begin(),data.end(),1,multiplies<double>());
            double res = pow(product,1.0/data.size());
            return res;
        }

        double square_sum(vector<double> &data){
            float sum = 1.0;
            for(int i=0;i<len(data);i++){
                float sq = pow(data[i],2);
                sum += sq;
            }return sum;
        }

        double sample_standard_deviation(vector<double> &data){
            vector<double> res;
            for(int i=0;i<len(data);i++){
                float x = pow(data[i]-mean(data),2);
                res.push_back(x);
            }return sqrt(sum(res)/(len(data)-1));
        }

        double population_standard_deviation(vector<double> &data){
            vector<double> res;
            for(int i=0;i<data.size();i++){
                float a = pow(data[i]-mean(data),2);
                res.push_back(a);
            }return sum(res)/len(data);
        }

        double sample_variance(vector<double> &data){
            vector<double> res;
            for(int i=0;i<len(data);i++){
                float a = pow(data[i]-mean(data),2);
                res.push_back(a);
            }return sum(res)/(len(data)-1);
        }

        double population_variance(vector<double> &data){
            vector<double> res;
            for(int i=0;i<data.size();i++){
                float a = pow(data[i]-mean(data),2);
                res.push_back(a);
            }return sum(res)/len(data);
        }

        double sample_standard_error(vector<double> &data){
            return sample_standard_deviation(data)/sqrt(len(data));
        }

        double population_standard_error(vector<double> &data){
            return population_standard_deviation(data)/sqrt(len(data));
        }

        double rms(vector<double> &data){
            vector<double> res;
            for(int i=0;i<data.size();i++){
                float a = pow(data[i],2);
                res.push_back(a);
            }return sqrt(sum(res)/len(data));
        }

        double mse(vector<double> &actual,vector<double> &predicted){
            if(len(actual)==len(predicted)){
                vector<double> errors;
                for(int i=0;i<len(actual);i++){
                    float a = pow(actual[i]-predicted[i],2);
                    errors.push_back(a);
                }return sum(errors)/len(actual);
            }return error;
        }

        double rmse(vector<double> &actual, vector<double> &predicted){
            if(len(actual)==len(predicted)){
                return sqrt(mse(actual,predicted));
            }return error;
        }

        double mae(vector<double> &actual, vector<double> &predicted){
            if(len(actual)==len(predicted)){
                vector<double> errors;
                for(int i=0;i<len(predicted);i++){
                    float a = maths.absolute(actual[i]-predicted[i]);
                    errors.push_back(a);
                }return sum(errors)/len(actual);
            }return error;
        }

        double cost_function(vector<double> &actual,vector<double> &predicted){
            if(len(actual)==len(predicted)){
                vector<double> errors;
                for(int i=0;i<len(predicted);i++){
                    float a = pow(actual[i]-predicted[i],2);
                    errors.push_back(a);
                }return sum(errors)/(2*len(actual));
            }return error;
        }

        double mean_error(vector<double> &actual,vector<double> &expected){
            if(len(actual)==len(expected)){
                vector<double> errors;
                for(int i=0;i<len(expected);i++){
                    float a = actual[i] - expected[i];
                    errors.push_back(a);
                }return mean(errors);
            }return error;
        }

        double accuracy(vector<double> &actual,vector<double> &expected){
            if(len(actual)==len(expected)){
                int score = 0;
                for(int i=0;i<len(expected);i++){
                    if(actual[i] == expected[i]){
                        ++score;
                    }
                }return score/len(actual);
            }return error;
        }
};
