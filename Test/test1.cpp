
#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <map>
#include <ctype.h>
using namespace std;

int main(){

 string input; //* B010185 FJane LDoe*** thirty two people lost in New Yourk last week** 2, 3, 5, 100,
    int fails = 0;
    bool exit1 = false, exit2 = false;
    //vector<map<char, string>> vector1;
    cout << "Enter a character string: " << endl;
    vector<string> vector1;

	
		while ((!input.empty() || input.empty()) && (exit2 == false && fails <= 3)){
			getline(cin, input);
			int x = 0, starCount;
        	bool starCheck1 = true, starCheck2 = true, starCheck3 = true, starCheck = true;
			if(input.empty()){
				getline(cin, input);
				if (input.empty()){
					 exit2 = true;
				}
			}
        	

        while (x <= input.size() && starCheck == true && exit1 == false){
        	
            if(x == input.size() && starCount == 3){ // check to see if x is equal to input size
                exit1 = true; // best way for me to end the while loop
            }
            else if(x == input.size() && starCount != 3){
            	fails++;
            	starCheck = false;
            }
            else if (input.substr(x) == "*"){ // star 1
                x++;
                char c = input[x];
                if (isspace(c)){
                    x++;
                    
                    if (input.substr(x) == "F" || input.substr(x) == "M" || input.substr(x) == "L" || input.substr(x) == "B"){
                        x++;
                        starCheck = true;
                        starCount++;
                    }
                    else{
                        starCheck = false;
                        fails++;
                    }
                }
                
                else if (input.substr(x) == "*"){ // star 2
                    
                    char c = input[x];
                    if (isspace(c)){
                        x++;
                        
                        if (isdigit(input[x])){
                            x++;
                            starCheck = true;
                            starCount++;
                        }
                        else{
                            starCheck = false;
                            fails++;
                        }
                    }
                    
                    else if (input.substr(x) == "*"){ // star 3
                        char c = input[x];
                        if (isspace(c)){
                            x++;
                            char up = input[x], low = input[x];
                            
                            if (islower(low) || isupper(up)){
                                x++;
                                starCheck = true;
                                starCount++;
                            }
                            else{
                                starCheck = false;
                                fails++;
                            }
                            
                            
                        }
                    }
                }
            }
            else{
            	x++;
            }
        }
    
        
    }
    
    if (fails == 3){
        return 0;
    }
return 0;
}