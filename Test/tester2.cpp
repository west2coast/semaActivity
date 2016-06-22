
#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <map>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
using namespace std;
int main (){
	string input = " 42, 65, 73, 82, 91";

	int x = 0, sum, count = 0;
	double total = 0, e = 0, average, inverse, standardD, m;            
	vector<int> scores;
	while (x < input.size()){
		if(isdigit(input.at(x))){
			count++;
		} 
		else{
			if(count > 0){
				scores.push_back(stoi(input.substr(x - count, count)));
			}
			count = 0;
				
		}
		x++;
	}
		x = 0;
		sum = accumulate(scores.begin(), scores.end(), 0);
		average = sum / scores.size();
		inverse = 1.0 / static_cast<double>(scores.size());
	
		while (x < scores.size()) {
			m = static_cast<double>(scores.at(x) - average);
				e += m * m;
				x++;
		}
		standardD = sqrt(inverse * e);
	printf("Average of scores is : %4.2f\nStandard Deviation is : %4.2f", average, standardD);
	
return 0;
}

 





