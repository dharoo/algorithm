// https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numStrs;
    for(int i = 0; i < numbers.size(); ++i) {
        numStrs.push_back(to_string(numbers[i]));
    }
    sort(numStrs.begin(), numStrs.end(), [](string a, string b) -> bool {
        return (a+b).compare(b+a) > 0;
    });
    
    for(int i = 0; i < numStrs.size(); ++i) {
        answer += numStrs[i];
    }
    
    int idx = -1;
    for(int i = 0; i < answer.length(); ++i) {
        if(answer[i] != '0') {
            idx = i;
            break;
        }
    }
    if(idx == -1) return "0";
    
    answer = answer.substr(idx);
    return answer;
}