/*회문검사(팰린드롬) */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/24.txt"),
    output:process.stdout
});

let input = "";

rl.on("line",(line)=>{
    input=line;
}).on("close",()=>{
    console.log(checkPalind3(input));
    process.exit();
});

const checkPalind1=(line)=>{
    let l=0,r=line.length-1;
    while(l !==r && l < line.length/2){
        if(line[l]===line[r] || line[l].charCodeAt(0) +32 ===line[r].charCodeAt(0)
                || line[l].charCodeAt(0) === line[r].charCodeAt(0)+32){
            l++;
            r--;
        }
        else return "NO";
    }
    return "YES";
}

const checkPalind2=(line)=>{
    let len = line.length;
   line = line.toLowerCase().split('');
   
   line.forEach((el,i)=>{
        if(el!==line[-i-1]) return "NO";
   })
   return "YES";

}

const checkPalind3=(line)=>{
    let reverse_line = line.split('').reverse().join('');
    console.log(reverse_line);
    if(reverse_line.toLowerCase() ===line.toLowerCase()) return "YES";
    else return "NO";
}

/**
 * 
 * 아스키 코드
 * 알파벳수는 26개
 * 0 => 48
 * A => 65 ~ Z => 90
 * a => 97
 */

