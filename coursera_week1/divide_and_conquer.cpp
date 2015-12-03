//
//  divide_and_conquer.cpp
//  coursera_week1
//
//  Created by 安田洋介 on 12/2/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#include "divide_and_conquer.h"

using namespace std;

long long int devide_and_conquer(vector<int> vec){
    queue<vector<int>> vec_queue;
    
    for(vector<int>::iterator it=vec.begin(); it!=vec.end(); it++){
        vector<int> newvec;
        newvec.push_back(*it);
        vec_queue.push(newvec);
    }
    
    long long int inverse_count = 0;

    queue<vector<int>> new_queue;
    while (true){
        
        vector<int> first_vec = vec_queue.front();
        vec_queue.pop();
        vector<int> second_vec = vec_queue.front();
        vec_queue.pop();
        vector<int> newvec;
        
        vector<int>::iterator first_it = first_vec.begin();
        vector<int>::iterator second_it = second_vec.begin();
        
        while(!(first_it == first_vec.end() && second_it == second_vec.end())){
            if(first_it == first_vec.end()){
                newvec.push_back(*second_it);
                second_it++;
            }else if(second_it == second_vec.end()){
                newvec.push_back(*first_it);
                first_it++;
            }else{
                if(*first_it<*second_it){
                    newvec.push_back(*first_it);
                    first_it++;
                }else{
                    newvec.push_back(*second_it);
                    second_it++;
                    inverse_count += (first_vec.end() - first_it);
                }
            }
        }
        
        new_queue.push(newvec);
        
        if(vec_queue.size() <= 1){
            if(vec_queue.size() == 1){
                new_queue.push(vec_queue.front());
            }
            if(new_queue.size() == 1){
                break;
            }else{
                vec_queue = new_queue;
                new_queue = *new queue<vector<int>>;
            }
        }
    }
    return inverse_count;
}

long long int exec_devide_and_conquer(string file_name){
    ifstream inFile(file_name);
    int number;
    vector<int> input_vec;
    while(inFile >> number){
        input_vec.push_back(number);
    }
    return devide_and_conquer(input_vec);
}
