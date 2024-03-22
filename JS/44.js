/**
 * @file 44.js
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
    input:fs.createReadStream("./input_file/44.txt"),
    output:process.stdout,
});

const input =[];
rl.on("line",(line)=>{
    input.push(line);
}).on("close",()=>{
    Game(input);
});

const Game = (input)=>{
    const stack=[];
    const board = JSON.parse(input[0]);
    const moves = JSON.parse(input[1]);
    let cnt=0;
    //console.log(board)
    for(el of moves){
        let i=0;
        while(i<board.length-1 && !board[i][el-1] ){ 
            i++;
        }
        if(board[i][el-1]===stack[stack.length-1]){
            stack.pop();
            cnt++;
        }
        else if(board[i][el-1]!==0){
            stack.push(board[i][el-1]);
        }
        board[i][el-1]=0;
        //console.log(stack);
    }
    console.log(cnt*2);
}