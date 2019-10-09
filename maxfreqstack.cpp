using namespace std;
#include<unordered_map>
#include<stack>
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
 
 

class FreqStack {
    unordered_map<int, stack<int>> freqmap;
    unordered_map<int,int> keymap;
    int max_freq;
public:
    FreqStack() {
        max_freq = INT_MIN; 
    }
    
    void push(int x) {
        int freq;
        keymap[x]++;
        freq = keymap[x];
        if(freq > max_freq)
            max_freq = freq;
        freqmap[freq].push(x);    
    }
    
    int pop() {
        int key;
        key = freqmap[max_freq].top();
        freqmap[max_freq].pop();
        keymap[key]--;
        if(freqmap[max_freq].empty())
            max_freq--;
        return key;
    }
};

