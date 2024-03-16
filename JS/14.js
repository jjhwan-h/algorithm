/*\
가장 긴 문자열
*/

const fs = require('fs');


const input = fs.readFileSync('./input_file/14.txt').toString().trim().split("\n");
const [n,...arr]=input;


const getlong= (n,input)=>{
    let Max=0;
    let long="";
    input.forEach((el)=>{
        if(Max<el.length) {
            Max = el.length;
            long=el;
        }

    })
    return long;
}

console.log(getlong(n,arr));
