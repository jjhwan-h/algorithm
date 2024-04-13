const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input/52.txt"),
    output:process.stdout,
})

input =[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    LRU(input);
    process.exit();
})

const LRU = (input)=>{
    [num, work] = input;
    const initialValue=0;
    C=Array.from({length:num[0]},()=>initialValue); //new Array(num[0])
    p=0;
    for(let i=0;i<num[1];i++){
        pos =0;
        for(let j=0; j<num[0]; j++) if(C[j]===work[p]) pos=j;

        if(pos){ //cache hit
            for(let j=pos; j>0; j--) C[j]=C[j-1];
        }
        else{ //cache miss
            for(let j=num[0]-1; j>0; j--) C[j]=C[j-1];
        }
        C[0]=work[p];
        p++;
        console.log(C.join(' '));
    }
}