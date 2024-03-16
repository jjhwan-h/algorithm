/**
 * @file 38.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 최대 매출 (sliding window)
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/38.txt"),
    output:process.stdout,
});

const input=[];
rl.on("line",(line)=>{
    console.log(line)
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
    console.log(input)
}).on("close",()=>{
    MaxRevenue(input);
    process.exit();
})

const MaxRevenue=(input)=>{
    [NM,num]=input;
    const N=NM[0];
    const M=NM[1];
    let lp=0, rp=lp+M-1, sum=0, max=0;

    for(let i=lp;i<=rp;i++) sum+=num[i];
    max=sum;
    while(rp<N){
        sum+=(num[rp++]-num[lp++]);
        max=Math.max(max,sum);
    }

    console.log(max);
    return;
}