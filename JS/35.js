/**
 * @file 35.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 공통원소구하기
 * @version 0.1
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/35.txt"),
    output:process.stdout,
});

const input = [];

rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    Solve(input);
    process.exit();
})

const Solve = (input)=>{
    let res=[];
    let [n,num1,m,num2] = input;
    n = n.join('');
    m = m.join('');

    let p1=p2=0;
    num1.sort((a,b)=>a-b);
    num2.sort((a,b)=>a-b);

    while(p1<n && p2<m){
        if(num1[p1]===num2[p2]) {res.push(num1[p1++]); p2++;}
        else if(num1[p1]>num2[p2]) p2++;
        else if(num2[p2]>num1[p1]) p1++;
    }

    console.log(res);

    return;
}

/**
 * sort함수에 인수를 주지않으면 숫자라하더라도 사전순으로 정렬한다.
 * num1 //[1,2,3,10,4]
 * ex num1.sort();  //[1,10,2,3,4]
 */

/**
 * 다른 좋은풀이
 */ 
function solution(arr1, arr2) {
        let answer = [];
        let temp_obj = {};
        const sum_arr = [...arr1, ...arr2]; //전개
        for (let i = 0; i < sum_arr.length; i++) {
          temp_obj[sum_arr[i]] = temp_obj[sum_arr[i]] + 1 || 1; //해시처럼 접근하여 값을 증가시켜준다.
        }
        for (let key in temp_obj) {
          if (temp_obj[key] === 2) { //2라는 것은 양쪽의 배열에 둘다 존재한다는것.
            answer.push(Number(key));
          }
        }
        return answer;
      }

      let a = [1, 3, 9, 5, 2];
      let b = [3, 2, 5, 7, 8];
      console.log(solution(a, b));
 