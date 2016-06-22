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
using namespace std;


void* thinker (void* damn){
    pthread_t dissector;
    
    int fails = 0, dissector1;
    string input = "* B010185 FJane LDoe*** thirty two people lost in New Yourk last week** 2, 3, 5, 100,
    Junk*** O AASU is a nice for four years * LFord B250180 MF FJohn** 20, 30, 90, O, 1 It is nice * B211081 MF LDoe** 80, 90, 90, 100, 0*** Everybody says two of the three men are guilty *** This is one good example among sixteen of them** 45, 55, 50, 60, 54, 52, 48* B010185 FJane LDoe ****** Today is a good day for fun** 70, l, 50, 8, 20, 95*** a b, c, d, one, two* ** os* MF LLOAF FLEMAR** 100, 100, 2, 98 *** Sixteen plus one is seventeen and minus nine is seven";
    ;
    //vector<map<char, string>> vector1;
    cout << "Enter a character string: ";
    
    while (fails < 3){
       // bool checkP1 = false, checkP2 = false; checkP3 = false;
        int x = 0;
        bool monkey = true;
        //getline(cin, input);
        while (x < input.size() && monkey == true){
            if (input.substr(x) == "*"){ // star 1
                x++;
                char c = input[x];
                if (isspace(c)){
                    x++;
                    
                    if (input.substr(x) == "F" || input.substr(x) == "M" || input.substr(x) == "L" || input.substr(x) == "B"){
                        x++;
                        monkey = true;
                    }
                    else{
                        monkey = false;
                        fails++;
                    }
                }
                
                else if (input.substr(x) == "*"){ // star 2
                    
                    char c = input[x];
                    if (isspace(c)){
                        x++;
                        
                        if (isdigit(input[x])){
                            x++;
                            monkey = true;
                        }
                        else{
                            monkey = false;
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
                                monkey = true;
                            }
                            else{
                                monkey = false;
                                fails++;
                            }

                            
                        }
                    }
                }
        }
        
        
    }
    
    pthread_exit(0);
}






















int main (){
    //pthread_t thinker;
    //char *message = '* B010185 FJane LDoe*** thirty two people lost in New Yourk last week** 2, 3, 5, 100, Junk*** O AASU is a nice for four years * LFord B250180 MF FJohn** 20, 30, 90, O, 1 It is nice * B211081 MF LDoe** 80, 90, 90, 100, 0*** Everybody says two of the three men are guilty *** This is one good example among sixteen of them** 45, 55, 50, 60, 54, 52, 48* B010185 FJane LDoe ****** Today is a good day for fun** 70, l, 50, 8, 20, 95*** a b, c, d, one, two* ** os* MF LLOAF FLEMAR** 100, 100, 2, 98 *** Sixteen plus one is seventeen and minus nine is seven';
        
    //int result;
    //result = pthread_create(&thinker, NULL, thinker, (void*) message);
    //result = pthread_join(thinker, NULL);

}





