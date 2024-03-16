/**
 * @file 42.js
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
    input:fs.createReadStream("./input_file/42.txt"),
    output:process.stdout,
});

input=[];
rl.on("line",(line)=>{
    input.push(line);
}).on("close",()=>{
    flag = isBracket(input);
    if(flag) console.log("YES");
    else console.log("NO");
    process.exit;
})

const isBracket = (input)=>{
    input = input[0];
    stack = [];
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