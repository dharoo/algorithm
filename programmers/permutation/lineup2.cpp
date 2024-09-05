// https://school.programmers.co.kr/learn/courses/30/lessons/12936
// lineup 풀이와 동일한데 좀더 직관적으로 재귀로 접근

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

// k번째 수를 만들기 위해 candidates중에서 answer의 현재자리수에 들어갈 숫자를 고르고 나머지는 재귀로 넘긴다.
void findKth(long long k, vector<int>& candidates, vector<int>& answer) {
    if(candidates.empty()) return;
    int n = candidates.size();
    long long fact = factorial(n-1);
    int idx = k/fact;
    answer.push_back(candidates[idx]);
    candidates.erase(candidates.begin()+idx);
    
    findKth(k%fact, candidates, answer);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> candidates;
    for(int i = 1; i <= n; ++i) {
        candidates.push_back(i);
    }
    
    findKth(k-1, candidates, answer);    
    
    return answer;
}
