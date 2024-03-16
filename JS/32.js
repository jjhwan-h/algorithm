/**
 * @file 32.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 졸업선물(브루트포스)
 * @version 0.1
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input: fs.createReadStream("./input_file/32.txt"),
    output:process.stdout,
});

let input =[];
let num =[];
let product =[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=> parseInt(el,10)));
}).on("close",()=>{
    [num,...product] = input;
    present();
    process.exit();
});

const present = ()=>{
    let max=0;
    let flag=false;
    console.log(`\n ${product}\n`);
    product.sort((a,b)=>(a[0]+a[1])-(b[0]+b[1])); // 오름차순
    console.log(`\n ${product}\n`);
    product.forEach((el,idx)=>{
        let sum=0; let cnt=0;
        sum+=product[idx][1];
        sum+=product[idx][0]/2;
        cnt++;
        for(let i=0;i<num[0];i++){
            if(i===idx) continue;
            sum+=product[i][1];
            sum+=product[i][0];
            if(sum>num[1]){ flag =true ;break;}
            cnt++;
        }
        if(flag==true && max<cnt) max=cnt;
    })
    console.log(max);
    return;
}

