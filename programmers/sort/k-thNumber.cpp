// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getResult(vector<int> array, vector<int> command) {
    vector<int> vec;
    for(int i = command[0]-1; i <= command[1]-1; ++i) {
        vec.push_back(array[i]);
    }
    sort(vec.begin(), vec.end());
    return vec[command[2]-1];
    
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); ++i) {
        answer.push_back(getResult(array, commands[i]));
    }
    
    return answer;
}