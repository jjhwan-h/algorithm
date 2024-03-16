const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input: fs.createReadStream("./input_file/21.txt"),
    output: process.stdout
});

let input =[];

rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    console.log(calScore(input));
    process.exit();
})

const calScore = (input)=>{
    const N =input[0];
    const Grade = input[1];
    let cnt=0;
    let res=0;
    for(let i=0;i<N;i++){
        if(Grade[i]===0){
            cnt=0;
        }
        else{
            cnt++;
            res+=cnt;
        }
    }
    return res;
}