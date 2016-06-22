void* dissector(void* message) {

    pthread_t part1T, part2T, part3T;
    
    string *in = static_cast<string*>(message);
    
    string input = *in;
    
    if (starCount == 3){
        int temp = 0;
        if (min(min(tempo3,tempo2),tempo1) == tempo1){ // first
            if (max(tempo3, tempo2) == tempo2){ // temp1, temp3, temp2
                temp = tempo3 - tempo1;
                string part1S = input.substr(tempo1,temp);
                pthread_create(&part1T, NULL, &part1, part1S);
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
                pthread_create(&part2T, NULL, &part2, &part2S);
                pthread_join(part2T, NULL);

                temp = input.size() - tempo2;
                string part3S = input.substr(tempo2, temp);
                pthread_create(&part3T, NULL, &part3, &part3S);
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
        else{

        }  
            }
        }
    }
     
 

    void *part1 (void *input){
         pthread_exit(0);
    }
    
    
    void *part2 (void *input){
        string *inputOLD = static_cast<string*>(input), inputNEW = *inputOLD;

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
        cout << "Score Average: " << average << endl;
        cout << "Standard Deviation: " << standardD << endl;
    }

    void* part3 (void* part1){
        
        
    }
