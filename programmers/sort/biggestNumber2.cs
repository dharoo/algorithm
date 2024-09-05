// https://school.programmers.co.kr/learn/courses/30/lessons/42746

using System;
using System.Linq;

public class Solution {
    int compare(string a, string b) {
        int intA = int.Parse(a);
        int intB = int.Parse(b);
        
        if(a.Length == b.Length) {
            if(intA > intB) return -1;
            if(intB > intA) return 1;
            return 0;
        }
        
        string temp = "";
        int idx = 0;
        int len = Math.Max(a.Length, b.Length);
        while(len-- > 0) {
            if(a[idx] == b[idx]) {
                temp += a[idx];
                idx++;
                if(a.Length == idx) {
                    a += temp;
                } 
                if(b.Length == idx) {
                    b += temp;
                }
            }
            
            intA = a[idx] - '0';
            intB = b[idx] - '0';
            
            if(intA > intB) return -1;
            if(intB > intA) return 1;
        }
        
        return 0;
    }
    
    public string solution(int[] numbers) {
        string answer = "";

        var stringNumbers = numbers.Select(n => n.ToString()).ToArray();
        Array.Sort(stringNumbers, compare);
        
        foreach(var n in stringNumbers) {
            answer += n.ToString();
        }
        int idx = 0;
        while(answer[idx] == '0' && answer.Length > 1) {
            answer = answer.Substring(1);
        }
        return answer;
    }
}