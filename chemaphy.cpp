/*
    version-2023.02.23
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

#define h 6.626e-34
#define e 1.6e-19
#define k 9e9
#define c 3e8
#define R 1.0973e7
#define gas_const 8.3145
#define pi 3.14159265358979323846
#define exp 2.7182818284590452354

#define ang 1e-10
#define decillion 1e33
#define nonillion 1e30
#define octillion 1e27
#define septollion 1e24
#define sextillion 1e21
#define quintillion 1e18
#define exa 1e18
#define quadrillion 1e15
#define peta 1e15
#define trillion 1e12
#define tera 1e12
#define billion 1e9
#define giga 1e9
#define ten_crore 1e8
#define crore 1e7
#define ten_lakh 1e6
#define million 1e6
#define mega 1e6
#define lakh 1e5
#define hundred_thousand 1e5
#define ten_thousand 1e4
#define thousand 1e3
#define kilo 1e3
#define hundred 1e3
#define hecto 1e3
#define one 1e0
#define zero 0e0
#define one_tenth 1e-1
#define deci 1e-1
#define one_hundredth 1e-2
#define centi 1e-2
#define one_thousandth 1e-3
#define milli 1e-3
#define one_millionth 1e-6
#define micro 1e-6
#define one_billionth 1e-9
#define nano 1e-9
#define one_trillionth 1e-12
#define pico 1e-12
#define one_quadrillionth 1e-15
#define femto 1e-15
#define one_quintillionth 1e-18
#define atto 1e-18

#define mass_electron 9.1e-31
#define electron_amu 0.00054858
#define mass_proton 1.67262e-27
#define proton_amu 1.007825
#define mass_neutron 1.67493e-27
#define neutron_amu 1.008665

#define gSun 274
#define gMercury 3.7
#define gVenus 8.87
#define gEarth 9.8
#define gMoon 1.62
#define gMars 3.712
#define gJupiter 24.79
#define gSaturn 10.44
#define gUranus 8.87
#define gNeptune 11.1
#define G 6.6743e-11

#define mass_sun 1.989e30
#define radius_sun 696340000
#define mass_mercury 6.39e23
#define radius_mercury 3389500
#define mass_venus 4.867e24
#define radius_venus 6051800
#define mass_earth 5.972e24
#define radius_earth 6371800
#define mass_moon 7.347e22
#define radius_moon 1737400
#define mass_mars 6.39e23
#define radius_mars 3389500
#define mass_jupiter 1.898e27
#define radius_jupiter 69911000
#define mass_saturn 5.683e26
#define radius_saturn 58232000
#define mass_uranus 8.681e25
#define radius_uranus 25362000
#define mass_neptune 1.024e26
#define radius_neptune 24622000

void display(vector<double> &data){
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<" ";
    }cout<<endl;
}

string author = "Sahil Rajwar";
string version = "2023.02.23";
string homepage = "https://github.com/Sahil-Rajwar-2004/chemaphy-cpp";

int error = -1;

class Bitshift{
    public:
        int right_shift(int number,int times){
            return number>>times;
        }

        int left_shift(int number,int times){
            return number<<times;
        }
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

        int absolute(double n){
            if(n<0){
                return -n;
            }else if(n == 0){
                return 0;
            }else{
                return n;
            }
        }
};

class Physics{
    public:
        double horizontal_range(double velocity, double garvity, double angle){
            return pow(velocity,2)*sin(2*angle*pi/180)/garvity;
        }

        double max_height(double velocity,double gravity,double angle){
            return pow(velocity,2)*sin(angle*pi/180)/(2*gravity);
        }

        double time_interval(double velocity,double gravity,double angle){
            return 2*velocity*sin(angle*pi/180)/gravity;
        }
};

class Log{
    public:
        double log_10(double x){
            return log10(x);
        }

        double log_e(double x){
            return log(x);
        }

        double log_2(double x){
            return log2(x);
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

        double variance(vector<double> &data,char kind='s'){
            vector<double> res;
            for(int i=0;i<len(data);i++){
                float a = pow(data[i]-mean(data),2);
                res.push_back(a);
            }
            if (kind == 's'){
                return sum(res)/len(data)-1;
            }else if (kind == 'p'){
                return sum(res)/len(data);
            }else{
                return error;
            };
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

        double mean_squared_error(vector<double> &actual,vector<double> &predicted){
            if(len(actual)==len(predicted)){
                vector<double> errors;
                for(int i=0;i<len(actual);i++){
                    float a = pow(actual[i]-predicted[i],2);
                    errors.push_back(a);
                }return sum(errors)/len(actual);
            }return error;
        }

        double root_mean_squared_error(vector<double> &actual, vector<double> &predicted){
            if(len(actual)==len(predicted)){
                return sqrt(mean_squared_error(actual,predicted));
            }return error;
        }

        double mean_absolute_error(vector<double> &actual, vector<double> &predicted){
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
