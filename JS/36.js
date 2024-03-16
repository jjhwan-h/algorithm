/**
 * @file 36.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 연속부분수열1
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline')

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/36.txt"),
    output:process.stdout,
})

const input=[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    subSequence(input);
    process.exit();
})

const subSequence = (input)=>{
    const [NM,arr] = input;
    const N=NM[0]; const M=NM[1];
    let p1=p2=sum=cnt=0;

    while(p1<N && p2<N){
        if(sum<M) sum+=arr[p2++];
        else if(sum>=M) {
            if(sum==M) cnt++;
            sum-=arr[p1++];
        }
    }

    console.log(cnt);
    return;
}

function solution(m, arr){
    let answer=0, lt=0, sum=0;
    for(let rt=0; rt<arr.length; rt++){
        sum+=arr[rt];
        if(sum===m) answer++;
        while(sum>=m){
            sum-=arr[lt++];
            if(sum===m) answer++;       
        }
    }        
    return answer;
}
