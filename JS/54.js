/**
 * @file 54.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 좌표정렬
 * @version 0.1
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const readline = require('readline');
const fs = require('fs');
const rl = readline.createInterface({
    input:fs.createReadStream("./input/54.txt"),
    output:process.stdout
})

input=[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    let res = sort(input);
    res.forEach((el) => {
        console.log(el[0],el[1])
    });
    process.exit();
})
const swap = (arr,i,j)=>{
    let tmp = arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
const sort = (line)=>{
    [N,...input]=line;
    
    for(let i=1;i<N;i++){
        let key = input[i][0];
        for(let j=i-1;j>=0;j--){
            let tmp = input[j][0];
            if(tmp>key) swap(input, j,j+1);
            else if(tmp===key && input[j][1]>input[j+1][1]){
                swap(input,j,j+1);
            }
        }
    }
    return input;
}

