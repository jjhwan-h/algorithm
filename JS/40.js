/**
 * @file 40.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 아나그램(해시)
 * @version 0.1
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/40.txt"),
    output:process.stdout,
});

const input=[];
rl.on("line",(line)=>{
    input.push(line.split(''));
}).on("close",()=>{
    anagram2(input);
    process.exit();
});

const anagram=(input)=>{
    const arr1=input[0];
    const arr2=input[1];
    let map = new Map();
    let map2 = new Map();

    arr1.forEach(el=>{
        map.set(el,(map.get(el) || 0)+1)
    });
    arr2.forEach(el=>{
        map2.set(el,(map2.get(el) || 0)+1)
    });
    console.log(map);
    console.log(map2);
    for(let [key,value] of map){
        if(map2.has(key) && map2.get(key)===value){
            continue;
        }
        else{
            console.log("NO");
            return;
        }
    }
    console.log("YES");
    return;
}

const anagram2=(input)=>{
    const arr1=input[0];
    const arr2=input[1];
    let map = new Map();
    
    arr1.forEach(el=>{
        map.set(el,(map.get(el) || 0)+1)
    });
    
    for(let i=0;i<arr2.length;i++){
        if(map.has(arr2[i]) && map.get(arr2[i])>0){
            map.set(arr2[i],map.get(arr2[i])-1)
        }
        else {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
    return;
}

