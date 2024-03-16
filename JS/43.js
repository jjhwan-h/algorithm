/**
 * @file 43.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/43.txt"),
    output:process.stdout,
});

input=[];

rl.on("line",(line)=>{
    input.push(line);
}).on("close",()=>{
    res =[];
    if(isBracket(input)) res = getWord(input);
    console.log(res);
    process.exit;
});

const isBracket = (input)=>{
    input = input[0];
    stack = [];
    input=input.replace(/[a-zA-Z]/g, "");
    console.log(input)
    for( let el of input){
        if(el==="(") stack.push(el);
        else{
            if(stack.length===0) return false;
            else stack.pop();
        }
    }

    if(stack.length>0) return false;
    else return true;
}

const getWord = (input)=>{
    input = input[0];
    stack = [];
    res =[];
    for(let el of input){
        if(stack.length===0 && el!=="(" && el!==")") res.push(el);
        if(el==="(") stack.push(el);
        else if(el===")") stack.pop();
    }
    res=res.join('');
    return res;
}

