/**
 * 숫자만 추출
 */
const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/26.txt"),
    output:process.stdout,
});

const input =[];
rl.on("line",(line)=>{
    input.push(line);
}).on("close",()=>{
    console.log(findNum(input[0]));
    process.exit();
});

const findNum = (input)=>{
    //0208 => parseInt시켜서 앞의 0없앤다.
    const num = parseInt(input.replace(/[^0-9]/g,""),10);
    
    return num;
}

/**
 * isNaN(x) => x가 숫자인지 확인
 */