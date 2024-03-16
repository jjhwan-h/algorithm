/**
 * @file 34.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 두배열합치기 (투표인터)
 * @version 0.1
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/34.txt"),
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
    let [n,num1,m,num2]=input;
    /*배열의 원소가 하나이므로 정수추출 , 그냥 pop명령어 사용해도된다.*/
    n=n.join('');
    m=m.join('');
    console.log(n,m,num1,num2);

    let arr=[];
    let p1=p2=0;
    while(p1<n && p2<m){
        if(num1[p1]>=num2[p2]) arr.push(num2[p2++]);
        else if(num1[p1]<num2[p2]) arr.push(num1[p1++]);
    }
    while(p1<n) arr.push(num1[p1++]);
    while(p2<m) arr.push(num2[p2++]);


    console.log(arr);

    return;
}

