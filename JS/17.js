const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/17.txt"),
    output:process.stdout
})
let arr=[];
rl.on('line',(line)=>{
    arr.push(line);
}).on("close",()=>{
    console.log(checkDct(arr));
    process.exit();
})


const checkDct = (arr)=>{
    arr.splice(0,1); //첫번째 삭제
    arr = [...new Set(arr)];
    return arr;
}