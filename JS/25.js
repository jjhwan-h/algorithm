/**
 * 알파벳제외 무시
 * 펠린드롬
 */
const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/25.txt"),
    output:process.stdout
});

const input=[];
rl.on("line",(line)=>{
    input.push(line);
}).on("close",()=>{
    console.log(checkPalind(input));
    process.exit();
});

const checkPalind=((input) =>{
    const str = input[0].toLowerCase().replace(/[^a-z]/g,""); //소문자 알파벳아닌 것을 ""로 대체
    const reverse_str = str.split("").reverse().join(""); //reverse는 array의 메서드.
    console.log(reverse_str);
    if(str === reverse_str) return "YES";
    else return "NO";
    console.log(str)
})

