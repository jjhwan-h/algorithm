/**
 * @file 33.js
 * @author jang jeong hwan (you@domain.com)
 * @brief K번째 큰수(브루트포스)
 * @version 0.1
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */


const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/33.txt"),
    output:process.stdout,
});

const input = [];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    Solve(input);
    process.exit();
});

const Solve = (input)=>{
    let [nk,...tmp]=input;
    
    const num = tmp.reduce((acc,cur)=>{ //tmp는 현재 2차원배열 => 1차원배열로 변경
        return [...acc,...cur]
    })

    let sum= new Set();
    /**3개의 수를 먼저 더해서 set(중복허용x)에 push해둔다. */
    for(let i=0;i<nk[0]-2;i++){
        for(let j=i+1;j<nk[0]-1;j++){
            for(let k=j+1;k<nk[0];k++)
                sum.add(num[i]+num[j]+num[k]);
        }
    }

    let res = Array.from(sum).sort((a,b) => b-a) //set자료형 array롤 변경후 내림차순sort
    //console.log(`\n ${sum} \n`);

    // let K = nk[1];
    // let pre =0;

    // sum.forEach((el,idx)=>{
    //     if(sum[pre]!==el) K--;
    //     if(K===1){
    //         console.log(el);
    //        return false;
    //     }
    // })
    
    console.log(res[nk[1]-1])
    
}

