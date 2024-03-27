/**
 * @file 49.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 선택정렬
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input/49.txt"),
    output:process.stdout
});

input =[];

rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    selectionSort(input);
    process.exit();
});
const swap=(arr,a,b)=>{
    let tmp=arr[a];
    arr[a]=arr[b];
    arr[b]=tmp;
}
const selectionSort=(input)=>{
    [N,arr]=input;
    for(let i=0;i<arr.length;i++){
        let min=i
        for(let j=i+1;j<arr.length;j++){
            if(arr[j]<arr[min])min=j;
        }
        //swap(arr,i,min);
        [arr[i],arr[min]]=[arr[min],arr[i]];
    }
    console.log(arr)
    return;
}