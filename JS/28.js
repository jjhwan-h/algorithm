/**
 * 문자열압축
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/28.txt"),
    output:process.stdout,
});
let input;
rl.on("line",(line)=>{
    input=line;
}).on("close",()=>{
    console.log(compress(input));
    process.exit();
});

const compress = (input)=>{
    let str=input;
    let res= [];
    let idx,cnt=0;
    let text="";
    str.split('').forEach((el) => {
        if(el===text) cnt++;
        else{
            if(cnt!==1)res.push(cnt);
            text=el;
            res.push(text);
            cnt=1;
        }
    });
    return res.join('');
}