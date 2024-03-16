const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
    input: fs.createReadStream("./input_file/19.txt"),
    output: process.stdout
});

let input=[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    console.log("\n");
    console.log(cntStd(input));
    process.exit();
})

const cntStd = (input)=>{
    let n=input[0], std=input[1];
    let tall=0,res=0;

    std.forEach((el)=>{
        if(el>tall) {
            res++;
            tall=el;
        }
    })

    return res

}