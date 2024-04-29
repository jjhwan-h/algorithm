/**
 * @file 55.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 회의실 배정
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */


const readline = require('readline');
const fs = require('fs');
const rl = readline.createInterface({
    output:process.stdout,
    input:fs.createReadStream("./input/55.txt")
});

input =[]
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)))
}).on("close",()=>{
    console.log("\n"+sol(input));
    process.exit();
});

const sol = (input)=>{
    [N,...arr]=input;
    arr.sort((a,b)=>{ // 회의가 일찍끝나는 순서대로 정렬
        if(a[1]===b[1]) return a[0]-b[0];
        else return a[1]-b[1];
    });

    let bv=0, res=0;
    for(el of arr){ //먼저 끝나는 회의를 선택한다.
        if(el[0]>=bv) {
            bv=el[1];
            res++;
        }
    }
    return res;
}