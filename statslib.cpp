/*
    version-2023.01.11
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
using namespace std;


void display(vector<double> &data){
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

string author = "Sahil Rajwar";
string version = "2023.01.11";
string homepage = "https://github.com/Sahil-Rajwar-2004/stats-lib";

class Statistics{
    public:
		double sum(vector<double> &data){
			float x = 0.0;
			for(int i=0;i<data.size();i++){
				x += data[i];
			}
			return x;
		}

        double product(vector<double> &data){
            float p = 1.0;
            for(int i=0;i<data.size();i++){
                p *= data[i];
            }
            return p;
        }

		double len(vector<double> &data){
			return data.size();
		}
		
        double mean(vector<double> &data){
            float sum = 0.0;
            for(int i=0; i<data.size(); i++){
                sum += data[i];
            }
            return sum/data.size();
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
            }
            return mode;
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
            }
            return max_val-min_val;
        }

		double harmonic_mean(vector<double> &data){
			float sum = 0.0;
			for(int i=0;i<data.size();i++){
                if(data[i] != 0){
				    float a = 1/data[i];
				    sum += a;
                }else{
                    return -1;
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
            }
            return sum;
        }

        double standard_deviation(vector<double> &data){
            vector<double> res;
            for(int i=0;i<len(data);i++){
                float x = pow(data[i]-mean(data),2);
                res.push_back(x);
            }
            return sqrt(sum(res)/(len(data)-1));
        }
};
