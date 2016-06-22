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
//#include <map>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <numeric>
 using namespace std;
/*
 * Global Variables and Methods Defined
 */
 // * B010185 FJane LDoe*** thirty two people lost in New Yourk last week** 2, 3, 5, 100,
 void* dissectors(void* message);
 void* thinkers (void* );
 void* part1 (void* input);
 void* part2 (void* input);
 void* part3 (void* input);
 int starCount = 0;
 int tempo1 = 0, tempo2 = 0, tempo3 = 0, tempo = 0, temp = 0;
/*
 * Main Method
 */
 int main (){
    pthread_t thinker;
    string message;
    int result = pthread_create(&thinker, NULL, thinkers, NULL);

    if (result){
        printf("Error - pthread_create() return code: %d\n", result);
        exit(EXIT_FAILURE);

    }
    result = pthread_join(thinker, NULL);
    exit(EXIT_SUCCESS);
}
/*
 * Thinker Method
 */
 void* thinkers (void*){
    pthread_t dissector;
    int fails = 0;
    bool exit1 = false;
    string input;
    cout << "Enter a character string: ";

    
    //while(){
    while (((fails < 3) && (exit1 != true))){

        //getline(cin, input);
        int x = 0;
        starCount = 0;
        bool starCheck = true;
        getline(cin, input);
        if(input.empty()){
            cout << "YOU";
            exit1 = true;
        }
            //getline(cin, input);
            //cout << "DMA2";
            //if (input.empty()){ 
            //}
        while ((x <= input.size() && !input.empty()) && (starCheck == true && exit1 != true)){
cout << "YOU";
            if(x == input.size() && starCount == 3){
                exit1 = true;
            }
            else if (x == input.size() && starCount != 3){
                starCheck = false;
                fails++;
                input.clear();
            }
            else if (input.at(x) == '*'){ // star 1
                tempo = x;
                x++;
                cout << "STAR*";
                if (input.at(x) == '*'){ // star 2
                    tempo = x;
                    cout << "STAR**";
                    x++;
                    if (isspace(input.at(x))){
                        x++;
                        cout << "FUCSDF";
                        if (isdigit(input.at(x))){
                            x++;
                            starCheck = true;
                            starCount++;
                            tempo2 = tempo + 1;
                        }
                        else{
                            starCheck = false;
                            fails++;
                            input.clear();
                        }
                    }
                    
                    else if (input.at(x) == '*'){ // star 3
                        tempo = x;
                        cout << "STAR***";
                        x++;
                        if (isspace(input.at(x))){
                            x++;
                            char up = input.at(x), low = input.at(x);
                            
                            if (islower(low) || isupper(up)){
                                x++;
                                starCheck = true;
                                starCount++;
                                tempo3 = tempo + 1;
                            }
                            else{
                                starCheck = false;
                                fails++;
                                input.clear();
                            }    
                            
                        }
                    }
                }
                else if (isspace(input.at(x))){
                    x++;
                    cout << "FUCK";
                    if (input.at(x) == 'F' || input.at(x) == 'M' || input.at(x) == 'L' || input.at(x) == 'B'){
                        cout << "er";
                        starCheck = true;
                        starCount++;
                        tempo1 = tempo + 1;
                        x++;
                    }
                    else{
                        starCheck = false;
                        fails++;
                        input.clear();
                    }
                    
                }
                else{
                    starCheck = false;
                    fails++;
                    input.clear();
                }
            }
            else{
                cout << "SHIT";
                x++;
            }
        } // second while
        
        
    } // leave while loops
    cout << "DMA";
    int result = pthread_create(&dissector, NULL, &dissectors, NULL);
    if (fails >= 3){
        exit(EXIT_FAILURE);
    }
    else if(result){
        printf("Error - pthread creation failed, return code is: %d\n", result);
        exit(EXIT_FAILURE);
    }   
    pthread_join(dissector, NULL);
    return 0;
}
/*
 * Dissector Method
 */
 void* dissectors(void* message){
    pthread_t part1T, part2T, part3T;
    string *inputOLD = static_cast<string*>(message);
    string input = *inputOLD;
    
    if (starCount == 3){
        for(int x = 0; x < 3; x++){
            if(x == 0){
                string part1S = input.substr(tempo1,temp);
                pthread_create(&part1T, NULL, &part1, &part1S);
                pthread_join(part1T, NULL);
            }
            else if (x == 1){
                string part2S = input.substr(tempo3, temp);
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);
            }
            else if (x == 2){
                string part3S = input.substr(tempo2, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
                pthread_join(part3T, NULL);
            }
        }          
    }     
    return 0;
}
/*
 * Part 1 of Dissector
 */
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
                string sub = inputNEW.substr(temp+1, count); 
                if(letter[y] == 'F'){
                    first = sub;
                }
                else if(letter[y] == 'M'){
                    middle = sub;
                }
                else if(letter[y] == 'L'){
                    last = sub;
                }
                else if(letter[y] == 'B'){
                    birth = sub;
                }  
            }
        }

    }
    printf("Name: %s %s %s\n" "Age: %s\n", first.c_str(), last.c_str(), middle.c_str(), birth.c_str());


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
    printf("Score Average: %f\n Standard Deviation: %f\n", average, standardD);

    return(0);
}

void* part3 (void* input){

    return(0);
}



