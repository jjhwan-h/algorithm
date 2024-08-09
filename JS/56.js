/**
 * @file 56.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 결혼식/그리디
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
    input:fs.createReadStream("./input/56.txt"),
    output:process.stdout
})

input=[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    getMax2(input);
    process.exit();
});

const getMax = (input)=>{
    day=3;
    [N,...input]=input;
    timeLine = Array.from({length:24*day},()=>0);

    input.forEach((el)=>{
        for(let i=el[0];i<el[1];i++){
            timeLine[i]++;
        }
    })
    
    for(let j=0;j<24*day;j++){
        process.stdout.write(timeLine[j]+" "); 
    }
}

const getMax2 = (input)=>{
    res = 0;
    day=3;
    [N,...input]=input; 
    timeLine=[];
    for(let x of input){
        timeLine.push([x[0],'s']);
        timeLine.push([x[1],'e']);
    }
    
    timeLine.sort((a,b)=>{
        if(a[0]===b[0]) return a[1].charCodeAt()-b[1].charCodeAt();
        else return a[0]-b[0];
    })  
        
        // for( x of timeLine){
        //     console.log(x[0]+","+x[1])
        // }
    let cnt=0;
    
    for(let x of timeLine){
        if(x[1]==='s')cnt++;
        else cnt--;
        res = (res>cnt) ? res : cnt;
    }
    console.log(res);
}