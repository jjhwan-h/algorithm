/*
대문자로 통일
*/
const readline = require('readline');

const rl = readline.createInterface({
    input:process.stdin,
    output:process.stdout
})

rl.question('',(str)=>{
    console.log(toUpper(str));

    rl.close();     
})

const toUpper = (str)=>{
    str = [...str].map((el)=>{
        return el.toUpperCase();
    }).join('');
    
    return str
}