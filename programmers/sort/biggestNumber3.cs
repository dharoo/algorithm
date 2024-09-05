// https://school.programmers.co.kr/learn/courses/30/lessons/42746

using System;
using System.Linq;

public class Solution {
    // 숫자를 4자리로 반복하여 문자열로 변환
    string ToFourDigitString(int number)
    {
        string numStr = number.ToString();
        // 숫자를 반복하여 4자리로 만든 문자열
        string repeatedStr = string.Concat(Enumerable.Repeat(numStr, 4));
        return repeatedStr.Substring(0, 4); // 4자리로 자르기
    }

    public string solution(int[] numbers) {
        string answer = "";
        
        var indexNumberPairList = numbers
            .Select((value) => new { originNumber = value, fourDigitNumber = ToFourDigitString(value)})
            .OrderByDescending(item => item.fourDigitNumber)
            .ToArray();
        
        //Array.Sort(indexNumberPairList, (a, b) => b.fourDigitNumber.CompareTo(a.fourDigitNumber));
        
        foreach(var item in indexNumberPairList) {
            answer += item.originNumber;
        }
        
        return answer;
    }
}