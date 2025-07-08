// COCI '20 Contest 3 #1 Knjige (DMOJ): https://dmoj.ca/problem/coci20c3p1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
int N, leftHand, rightHand, totalSteps; bool rightHandOccupied; vector<int> sorted; vector<string> steps; stack<int> leftStack, rightStack;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0, x; i < N; i++){
        cin >> x; sorted.push_back(x); rightStack.push(x);
    }
    if(is_sorted(sorted.begin(), sorted.end())){
        cout << 0 << endl;
        return 0;
    }
    sort(sorted.begin(), sorted.end(), greater<>() );
    while(!rightStack.empty()){
        leftStack.push(rightStack.top()); rightStack.pop();
    }
    while(!leftStack.empty()){
        int cur = leftStack.top(); leftStack.pop();
        if(cur == sorted[0] && !rightHandOccupied){
            steps.push_back("UZMI D L");
            rightHand = cur; rightHandOccupied = true;
            totalSteps++;
        }
        else {
            steps.push_back("UZMI L L");
            leftHand = cur;
            steps.push_back("STAVI L D");
            rightStack.push(leftHand);
            totalSteps += 2;
        }
    }
    steps.push_back("STAVI D L"); totalSteps++;
    leftStack.push(rightHand);

    for(int i = 1; i < N; i++){
        while(rightStack.top() != sorted[i]){
            steps.push_back("UZMI L D");
            leftHand = rightStack.top(); rightStack.pop();
            steps.push_back("STAVI L L");
            leftStack.push(leftHand);
            totalSteps += 2;
        }
        steps.push_back("UZMI D D"); totalSteps++;
        rightHand = rightStack.top(); rightStack.pop();

        while(leftStack.top() != sorted[i-1]){
            steps.push_back("UZMI L L");
            leftHand = leftStack.top(); leftStack.pop();
            steps.push_back("STAVI L D");
            rightStack.push(leftHand);
            totalSteps += 2;
        }

        steps.push_back("STAVI D L"); totalSteps++;
        leftStack.push(rightHand);
    }
    
    cout << totalSteps << endl;
    for(string s : steps){
        cout << s << endl;
    }
}
