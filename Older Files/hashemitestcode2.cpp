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
 #include <sstream>
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
 int temps1 = 0, temps2 = 0, temps3 = 0, temps = 0, subTemp1 = 0, subTemp2 = 0, subTemp3 = 0;
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
    pthread_join(thinker, NULL);
    exit(EXIT_SUCCESS);
}
/*
 * Thinker Method
 */
 void* thinkers (void*){
    pthread_t dissector;
    int fails = 0, star = 0;
    bool exit1 = false;
    string input;
    cout << "Enter a character string: ";

    while (((fails < 3) && (exit1 != true))){
        int x = 0;
        starCount = 0;
        bool starCheck = true;
        if(getline(cin, input) && input.empty()){
            //cout << "YOUR";
            exit1 = true;
        }

        while ((x < input.size() && !input.empty()) && (starCheck == true && exit1 != true)){
            //cout << "YOU";
            input.c_str();

            while (input[x] == '*'){ // Find stars
              cout<< "     " << x << endl;
              temps = x;
              star++;
              ++x;

          }
          if (isspace(input[x]) && star > 0){
            x++;

                //cout << star;
            char letter = input.at(x), low = input.at(x);
            if ((input[x] == 'F' || input[x] == 'M' || input[x] == 'L' || input[x] == 'B') && star == 1){
                    //cout << "STAR1";
                starCheck = true;
                starCount++;
                temps1 = temps + 1;
                star = 0;
                x++;

            }
            else if (isdigit(input[x]) && star == 2){
                   // cout << "STAR2";
                starCheck = true;
                starCount++;
                temps2 = temps + 1;
                cout << "DAMIT" << temps2 << endl;
                star = 0;
                x++;
            }

            else if ((isalpha(letter)) && star == 3){
                    //cout << "STAR3";
                starCheck = true;
                starCount++;
                temps3 = temps + 1;
                star = 0;
                x++;
            }
            else{
                starCheck = false;
                fails++;
                input.clear();
                    //temps1 = 0 temps2 = 0, temps3 = 0, temps = 0;
            }  
        }
        else if(x+1 == input.size()){
            if (starCount == 3){
                exit1 = true;
            }
            else {
              starCheck = false;
              fails++;
              input.clear();
                  //temps1 = 0, temps2 = 0, temps3 = 0, temps = 0;
          }
      }
      else {
        x++;
                //star = 0;
    }

        //star = 0;
        } // while loop
        
    } // leave while loops
    //cout << "DMA";
    int result = pthread_create(&dissector, NULL, &dissectors, &input);
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
    string part1S, part2S, part3S;
    int firstSTARLOCATION = 0;
    int newTemp1 = temps1, newTemp2 = temps2, newTemp3 = temps3;
    bool end = false, end2 = false, end3 = false;

    while (newTemp1 <= input.size() && end == false){

        if (input[newTemp1] == '*'){
            cout << "WE";
            subTemp1 = newTemp1 - temps1;
            end = true;
        }
        else if (firstSTARLOCATION >! 0 && newTemp1 == input.size()){
            subTemp1 = (input.size() - temps1);
        }
        newTemp1++;
    }



    while (newTemp3 <= input.length() && end3 == false){

        if (input[newTemp3] == '*'){
            cout << "TONIGHT";
            subTemp3 = newTemp3 - temps3;
            end3 = true;
        }
        else if (firstSTARLOCATION >! 0 && newTemp3 == input.size()){
            subTemp3 = (input.size() - temps3);
        }
        newTemp3++;
    }



    while ( end2 == false){

        if (input[newTemp2] == '*'){
            cout << "TONIGHT";
            subTemp2 = newTemp2 - temps2;
            end2 = true;
        }
        else if (firstSTARLOCATION >! 0 && newTemp2 == input.size()){
            subTemp2 = (input.size() - temps2);
        }
        newTemp2++;
    }


    cout << input.length() << endl;
    cout << temps1 << " " << subTemp1 << endl;
    cout << temps2 << " " << subTemp2 << endl;
    cout << temps3 << " " << subTemp3 << endl;  
    part1S = input.substr(temps1, subTemp1), part2S = input.substr(temps2, subTemp2), part3S = input.substr(temps3, subTemp3);    
    int result = pthread_create(&part1T, NULL, &part1, &part1S); 
    if (result){
      printf("Error - pthread_create() return code: %d\n", result);
      exit(EXIT_FAILURE);
  }
  pthread_join(part1T, NULL);


  int result2 = pthread_create(&part2T, NULL, &part2, &part2S); 

  if (result2){
      printf("Error - pthread_create() return code: %d\n", result2);
      exit(EXIT_FAILURE);
  }
  pthread_join(part2T, NULL);



  pthread_exit(NULL);
}
/*
 * Part 1 of Dissector
 */
 void* part1 (void* input){ 
    string *inputOLD = static_cast<string*>(input);
    string inputNEW = *inputOLD,first, middle, last, birth ;
    char letter[4] =  {'F', 'M', 'L', 'B'};
    string inputNEWC = inputNEW;
    inputNEWC.c_str();
    int temp = -1, count = 0;
    for (int y = 0; y < 4; y++){

        for (int x = 0; x < inputNEW.size(); x++){

            if (inputNEWC[x] == letter[y]){
                temp = x;
            }

            while((temp > 0) && !isspace(inputNEWC[x])){
                count++;
                x++;
            }
            if(isspace(inputNEWC[x]) && (temp >= 0) && count > 0){
                string sub = inputNEW.substr(temp+1, count); 
                if(letter[y] == 'F'){
                    first = sub;
                    count = 0;
                }
                else if(letter[y] == 'M'){
                    middle = sub;
                    count = 0;
                }
                else if(letter[y] == 'L'){
                    last = sub;
                    count = 0;
                }
                else if(letter[y] == 'B'){
                    birth = sub;
                    count = 0;
                }        
            }
            temp = -1;
        }
    }
    for (int x = 0; x < 4; x++){
        if(first.empty()){
            first = "missing value";
        }
        else if(middle.empty()){
            middle = "missing value";
        }
        else if(last.empty()){
            last = "missing value";
        }
        else if(birth.empty()){
            birth = "missing value";
        } 
    } 
    //cout << last.c_str() << endl;

    printf("Name: \n%s\n%s\n%s\n" "Age: \n%s\n", last.c_str(), first.c_str(), middle.c_str(), birth.c_str());
//return 0;
    return 0;
}


void* part2 (void* input){
    string *inputOLD = static_cast<string*>(input); 
    string inputNEW = *inputOLD;
    int x = 0, sum = 0, count = 0;
    double total = 0, e = 0, average, inverse, standardD, m;
    vector<double> scores;

    while (x <= inputNEW.size()){
        if(isdigit(inputNEW[x])){
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
    average = sum / 4;
    inverse = 1.0 / static_cast<double>(scores.size());

    while (x < scores.size()){
        m = static_cast<double>(scores.at(x) - average);
        e += m * m;
        x++;
    }
    standardD = sqrt(inverse * e);

    string stringD = static_cast<ostringstream*>( &(ostringstream() << standardD) )->str();
    string stringA = static_cast<ostringstream*>( &(ostringstream() << average) )->str();

    printf("Score Average: %s\n Standard Deviation: %s\n", stringA.c_str(), stringD.c_str());

    return 0;
}

void* part3 (void* input){

    return(0);
}