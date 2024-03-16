const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input: fs.createReadStream("./input_file/20.txt"),
    output: process.stdout
});

let input =[];

rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    console.log("\n");
    console.log(Game(input));
    process.exit();
})

const Game = (input)=>{
    let n=input[0], A=input[1], B=input[2];
    let res=[];

    for(let i=0;i<n;i++){
        res.push(Winner(A[i],B[i]));
    }
    return res.join(' ');
}

const Winner = (a, b)=>{
    if(a===b) return "D";
    else{
        if( a===1 && b===3 
            || a===2 && b===1
            || a===3 && b===2
            ) return "A";
        else return "B";
    }
}

