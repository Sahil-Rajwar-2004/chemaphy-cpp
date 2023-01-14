/*
    version-2023.01.15
    Created by Sahil Rajwar
    Date: 11th January 2023
    HomePage: https://www.github.com/Sahil-Rajwar-2004/chemaphy-cpp
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
    }cout<<endl;
}

string author = "Sahil Rajwar";
string version = "2023.01.15";
string homepage = "https://github.com/Sahil-Rajwar-2004/chemaphy-cpp";

int error = -1;

class Constants{
    public:
        float h = 6.626e-34;
        float e = 1.6e-19;
        float k = 9e9;
        float c = 3e8;
        float R = 1.0973e7;
        float gas_const = 8.3145;
        float pie = 3.14159265358979;
        float exp = 2.71828182845904;
        float null = nan("");

        float ang = 1e-10;
        float decillion = 1e33;
        float nonillion = 1e30;
        float octillion = 1e27;
        float septollion = 1e24;
        float sextillion = 1e21;
        float quintillion = 1e18,exa = 1e18;
        float quadrillion = 1e15,peta = 1e15;
        float trillion = 1e12,tera = 1e12;
        float billion = 1e9,giga = 1e9;
        float ten_crore = 1e8;
        float crore = 1e7;
        float ten_lakh = 1e6,million = 1e6,mega = 1e6;
        float lakh = 1e5,hundred_thousand = 1e5;
        float ten_thousand = 1e4;
        float thousand = 1e3,kilo = 1e3;
        float hundred = 1e3,hecto = 1e3;
        float one = 1e0;
        float zero = 0e0;
        float one_tenth = 1e-1,deci = 1e-1;
        float one_hundredth = 1e-2,centi = 1e-2;
        float one_thousandth = 1e-3,milli = 1e-3;
        float one_millionth = 1e-6,micro = 1e-6;
        float one_billionth = 1e-9,nano = 1e-9;
        float one_trillionth = 1e-12,pico = 1e-12;
        float one_quadrillionth = 1e-15,femto = 1e-15;
        float one_quintillionth = 1e-18,atto = 1e-18;

        float mass_electron = 9.1e-31;
        float electron_amu = 0.00054858;
        float mass_proton = 1.67262e-27;
        float proton_amu = 1.007825;
        float mass_neutron = 1.67493e-27;
        float neutron_amu = 1.008665;

        float gSun = 274;
        float gMercury = 3.7;
        float gVenus = 8.87;
        float gEarth = 9.8;
        float gMoon = 1.62;
        float gMars = 3.712;
        float gJupiter = 24.79;
        float gSaturn = 10.44;
        float gUranus = 8.87;
        float gNeptune = 11.15;
        float G = 6.6743e-11;

        float mass_sun = 1.989e30;
        float radius_sun = 696340000;
        float mass_mercury = 6.39e23;
        float radius_mercury = 3389500;
        float mass_venus = 4.867e24;
        float radius_venus = 6051800;
        float mass_earth = 5.972e24;
        float radius_earth = 6371800;
        float mass_moon = 7.347e22;
        float radius_moon = 1737400;
        float mass_mars = 6.39e23;
        float radius_mars = 3389500;
        float mass_jupiter = 1.898e27;
        float radius_jupiter = 69911000;
        float mass_saturn = 5.683e26;
        float radius_saturn = 58232000;
        float mass_uranus = 8.681e25;
        float radius_uranus = 25362000;
        float mass_neptune = 1.024e26;
        float radius_neptune = 24622000;
};

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
