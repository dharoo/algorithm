// https://school.programmers.co.kr/learn/courses/30/lessons/12936

#include <string>
#include <vector>

using namespace std;

long long factorial(int n) {
    long long num = 1;
    for(int i = 1; i <= n; ++i) {
        num *= i;
    }
    return num;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> candidates;
    for(int i = 1; i <= n; ++i) {
        candidates.push_back(i);
    } 
    k--;
    for(int i = 0; i < n; ++i) {
        long long fact = factorial(n-1-i);
        // i-th 자리수
        long long quot = k/fact;
        answer.push_back(candidates[quot]);
        candidates.erase(candidates.begin()+quot);
        k = k % fact;
    }
    
    return answer;
}
