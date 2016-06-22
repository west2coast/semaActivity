/*
 * main.cpp
 *
 *  Created on: Sep 24, 2015
 *      Author: Chris West
 */
#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <map>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;
void* dissector2(void* message);
void* thinkers (void* message);
void* part3 (void* input);
void* part2 (void* input);
void* part1 (void* input);

int starCount = 0;
int tempo1 = 0, tempo2 = 0, tempo3 = 0, tempo = 0;




int main (){
    pthread_t thinker;
    int result = pthread_create(&thinker, NULL, thinkers, (void*) NULL);;
    if (result){
        printf("Error - pthread_create() return code: %d\n", result);
        exit(EXIT_FAILURE);

    }
    result = pthread_join(thinker, NULL);
    exit(EXIT_SUCCESS);
}

void* thinkers (void* message){
    pthread_t dissector;
    int fails = 0;
    string input;
    cout << "Enter a character string: ";

    bool exit1 = false, exit2 = false;
    //while(){
    while ((exit2 == false && fails < 3 && exit1 == false)){
        if(starCount == 3){
            exit1 = true;
        }
        getline(cin, input);
        int x = 0;
        starCount = 0;
        bool starCheck = true;
        if(input.empty()){
            getline(cin, input);
            if (input.empty()){
                exit2 = true;
            }
        }
        
        while ((x <= input.size()) && (starCheck == true) && (exit1 == false)){
 
            if(input.at(x) == '*'){ // star 1
                cout << "STAR";
                tempo = x;
                ++x;
                
                if(input.at(x) == '*'){ // star 2
                    tempo = x;
                    cout << "STAR";
                    if(isspace(input.at(x))){
                        ++x;
                        
                        if(isdigit(input.at(x))){
                            ++x;
                            starCheck = true;
                            starCount++;
                            tempo2 = tempo + 1;
                        }
                        else{
                            starCheck = false;
                            fails++;
                        }
                    }
                    
                    else if(input.at(x) == '*'){ // star 3
                        cout << "STAR";
                        x++;
                        tempo = x;
                        if(isspace(input.at(x))){
                            x++;
                            char up = input[x], low = input[x];
                            
                            if(islower(low) || isupper(up)){
                                x++;
                                starCheck = true;
                                starCount++;
                                
                                tempo3 = tempo + 1;
                            }
                            else{
                                starCheck = false;
                                fails++;
                            }    
                            
                        }
                    }
                }
                else if(isspace(input.at(x))){
                    ++x;
                    
                    if(input.at(x) == 'F' || input.at(x) == 'M' || input.at(x) == 'L' || input.at(x) == 'B'){
                        starCheck = true;
                        cout << "FUCK";
                        starCount++;
                        tempo1 = tempo + 1;
                        x++;
                    }
                    else{
                        starCheck = false;
                        cout << "FUCKer";
                        fails++;
                    }
                    
                }
            }
            
                cout << "SHIT";
                x++;
            
        } // second while
        
        
    } // leave while loops
    int result = pthread_create(&dissector, NULL, &dissector2, NULL);
    if (fails == 3){
        exit(EXIT_FAILURE);
    }
    else if(result){
            printf("Error - pthread creation failed, return code is: %d\n", result);
            exit(EXIT_FAILURE);
        }   
        pthread_join(dissector, NULL);
        return 0;
}

    void* part1 (void* input){
        string *inputOLD = static_cast<string*>(input);
        string inputNEW = *inputOLD;
        char letter[4] =  {'F', 'M', 'L', 'B'};
        string first, middle, last, birth;
        int temp = -1, temp2 = -1, count = 0;
        for (int y = 0; y < 4; y++){
            for (int x = 0; x < inputNEW.size(); x++){
                if (inputNEW.at(x) == letter[y]){
                    temp = x;

                }
                else if ((temp > 0) && !isspace(inputNEW.at(x))){
                    count++;
                }
                else if(isspace(inputNEW.at(x)) && (temp > 0 || temp == 0) &&  count == 0){
                    x = inputNEW.size();
                    if(letter[y] == 'F'){
                        first = "missing value";
                    }
                    else if(letter[y] == 'M'){
                        middle = "missing value";
                    }
                    else if(letter[y] == 'L'){
                        last = "missing value";
                    }
                    else if(letter[y] == 'B'){
                        birth = "missing value";
                    }                    
                }
                else if(isspace(inputNEW.at(x)) && (temp > 0 || temp == 0) && count > 0){
                    x = inputNEW.size();
                    if(letter[y] == 'F'){
                        first = inputNEW.substr(temp+1, count);
                    }
                    else if(letter[y] == 'M'){
                        middle = inputNEW.substr(temp+1, count);
                    }
                    else if(letter[y] == 'L'){
                        last = inputNEW.substr(temp+1, count);
                    }
                    else if(letter[y] == 'B'){
                        birth = inputNEW.substr(temp+1, count);
                    }  
                }
            }

            }
            printf("%s\n%s\n%s\n%s\n", first.c_str(), last.c_str(), middle.c_str(), birth.c_str());
        

        return(0);
    }
    
    
    void* part2 (void* input){
        string *inputOLD = static_cast<string*>(input); 
        string inputNEW = *inputOLD;

        int x = 0, sum, count = 0;
        double total = 0, e = 0, average, inverse, standardD, m;
        vector<int> scores;
        
        while (x < inputNEW.size()){
            if(isdigit(inputNEW.at(x))){
                count++;
            }
            else{
                if(count > 0){
                    scores.push_back(stoi(inputNEW.substr(x - count, count)));
                }
                count = 0;  
            }
            x++;
        }
        
        x = 0;
        sum = accumulate(scores.begin(), scores.end(), 0);
        average = sum / scores.size();
        inverse = 1.0 / static_cast<double>(scores.size());
        
        while (x < scores.size()){
            m = static_cast<double>(scores.at(x) - average);
            e += m * m;
            x++;
        }
        standardD = sqrt(inverse * e);        
        printf("Score Average: %f\n", average);
        printf("Standard Deviation: %f\n", standardD);
        return(0);
    }

    void* part3 (void* input){
        
        return(0);
    }

void* dissector2(void* message) {

    pthread_t part1T, part2T, part3T;
    
    string *in = static_cast<string*>(message);
    
    string input = *in;
    
    if (starCount == 3){
        int temp = 0;
        if (min(min(tempo3,tempo2),tempo1) == tempo1){ // first
            if (max(tempo3, tempo2) == tempo2){ // temp1, temp3, temp2
                temp = tempo3 - tempo1;
                string part1S = input.substr(tempo1,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);
                        
                temp = tempo2 - tempo3;
                string part2S = input.substr(tempo3, temp);
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);
                        
                temp = input.size() - tempo2;
                string part3S = input.substr(tempo2, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
                pthread_join(part3T, NULL);

            } // nested 
            
            else if(max(tempo3, tempo2) == tempo3){ // temp1, temp2, temp3
                temp = tempo2 - tempo1;
                string part1S = input.substr(tempo1,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);

                temp = tempo3 - tempo2;
                string part2S = input.substr(tempo2, temp);
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);

                temp = input.size() - tempo3;
                string part3S = input.substr(tempo3, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
                pthread_join(part3T, NULL);
            } // nested
        }

        else if(min(min(tempo3,tempo2),tempo1) == tempo2){
            if (max(tempo3, tempo1) == tempo1){  // temp2, temp3, temp1
                temp = tempo3 - tempo2;
                string part1S = input.substr(tempo2,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);

                temp = tempo1 - tempo3;
                string part2S = input.substr(tempo3, temp);
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);

                temp = input.size() - tempo1;
                string part3S = input.substr(tempo1, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
                pthread_join(part3T, NULL);
            }

            else if (max(tempo3, tempo1) == tempo3){  // temp2, temp1, temp3
                temp = tempo1 - tempo2;
                string part1S = input.substr(tempo2,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);
                        
                temp = tempo3 - tempo1;
                string part2S = input.substr(tempo1, temp);
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);

                temp = input.size() - tempo3;
                string part3S = input.substr(tempo3, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
                pthread_join(part3T, NULL);
            }
        }
        else if (min(min(tempo3,tempo2),tempo1) == tempo3){ 
            if (max(tempo1, tempo2) == tempo2){  // temp3, temp1, temp2
                temp = tempo1 - tempo3; 
                string part1S = input.substr(tempo3,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);
                        
                temp = tempo2 - tempo1;
                string part2S = input.substr(tempo1, temp);
                pthread_create(&part2T, NULL, &part2, (void* ) &part2S);
                pthread_join(part2T, NULL);

                temp = input.size() - tempo2;
                string part3S = input.substr(tempo2, temp);
                pthread_create(&part3T, NULL, &part3, (void* ) &part3S);
                pthread_join(part3T, NULL);
            }
            else if (max(tempo1, tempo2) == tempo1){  // temp3, temp2, temp1
                temp = tempo2 - tempo3; 
                string part1S = input.substr(tempo3,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);
                        
                temp = tempo1 - tempo2;
                string part2S = input.substr(tempo2, temp);
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);

                temp = input.size() - tempo1;
                string part3S = input.substr(tempo2, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
                pthread_join(part3T, NULL);
            }

        }
         
       }     
        return 0;
    }