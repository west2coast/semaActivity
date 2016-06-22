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
 void* thinkers (void*);
 void* part1 (void* input);
 void* part2 (void* input);
 void* part3 (void* input);
 int storeLoc[3], storeStar[3];
 int tempStar1 = 0, tempStar2 = 0, tempStar3 = 0, tempStar = 0, lenStar1 = 0, lenStar2 = 0, lenStar3 = 0; // temps temporary store position of star location + 1
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
    int fails = 0, star = 0, starCount = 0; // starCount is total # of stars; star is just to send the right information to certain areas
    bool exit1 = false;
    string input;
    cout << "Enter a character string: ";
    getline(cin, input);
    while (((fails < 3) && (exit1 != true))){
        int x = 0, place1 = 0, place2 = 0;
        starCount = 0;
        bool starCheck = true;
        if(getline(cin, input) && input.empty()){
            exit1 = true;
            cout << "DAMIT";
        }
        while ((x < input.size() && !input.empty()) && (starCheck == true && exit1 != true)){
            input.c_str();
            star = 0;

            while (input[x] == '*'){ // Find stars
              cout<< "     " << x << endl;
              tempStar = x; // temp. location of star
              star++;
              x++;

          }
          if (isspace(input[x]) && star > 0){
            x++;

            char letter = input.at(x), low = input.at(x);
            if ((input[x] == 'F' || input[x] == 'M' || input[x] == 'L' || input[x] == 'B') && star == 1){
                starCheck = true;
               // starCount++; // Adds 1 star
                storeLoc[star-1] = tempStar + 1; // subtract from star to store in array and temp. + 1 to store pass the place of the star to begin
               // storeLoc[starCount-1] = star;
                x++;
            }
            else if (isdigit(input[x]) && star == 2){

                starCheck = true;
                //starCount+= 2; 
                storeLoc[star-1] = tempStar + 1;
                //storeLoc[starCount-1] = star;
                cout << "DAMIT" << tempStar2 << endl;
                x++;
            }

            else if ((isalpha(letter)) && star == 3){

                starCheck = true;
                starCount++;
                storeLoc[star-1] = tempStar + 1;
                ///storeLoc[starCount-1] = star;
                x++;
            }
            else{
                starCheck = false;
                fails++;
                input.clear();

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

          }
      }
      else {
        x++;

    }
        } // while loop
        
    } // leave while loops
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
    int newTempStar1 = tempStar1, newTempStar2 = tempStar2, newTempStar3 = tempStar3;
    bool end = false, end2 = false, end3 = false;

    for (int m = 0; m < 3; m++){

        if (3 == storeStar[m]){ // part 3
            if (m == 0){
                int part1 = storeLoc[m]+1;
                int tempPart = storeLoc[m+1]; 
            }
            else if (m == 2){

            }
            else {

            }
        }
    }



    cout << input.length() << endl;
    cout << tempStar1 << " " << lenStar1 << endl;
    cout << tempStar2 << " " << lenStar2 << endl;
    cout << tempStar3 << " " << lenStar3 << endl;  
    part1S = input.substr(tempStar1, lenStar1), part2S = input.substr(tempStar2, lenStar2), part3S = input.substr(tempStar3, lenStar3);    
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

    printf("Name: \n%s\n%s\n%s\n" "Age: \n%s\n", last.c_str(), first.c_str(), middle.c_str(), birth.c_str());

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