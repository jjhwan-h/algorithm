const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/45.txt"),
    output:process.stdout,
});

const input =[];
rl.on("line",(line)=>{
    input.push(line);
}).on("close",()=>{
    Postfix(input);
});

const Postfix = (input)=>{
    input = input[0];
    let stack =[];
    for(el of input){
        if(/[0-9]/.test(parseInt(el,10))){ //0-9를 찾는 정규표현식
            stack.push(Number(el));
        } 
        else {
            let res=0;
            const post = stack.pop();
            const pre = stack.pop();
            if(el ==='+') res=pre+post;
            else if(el==='-') res=pre-post;
            else if(el==='*') res=pre*post;
            else if(el==='/') res=pre/post;

            stack.push(res);
            console.log(`\n pre:${pre}, post:${post}, res:${res}`)
        }
    }
    console.log(stack.pop());
}
