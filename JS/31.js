/**
 * @file 31.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 멘토링(브루트포스)
 * @version 0.1
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input: fs.createReadStream("./input_file/31.txt"),
    output:process.stdout,
});

let input =[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=> parseInt(el,10)));
}).on("close",()=>{
    mento(input);
});

const mento = (input)=>{
    let [num,...score] = input;
    let memo=-1;
    let flag=true;
    let cnt=0;

    for(let i=0;i<num[0];i++){
        for(let j=i+1;j<num[0];j++){
            let n1=score[0][i]; let n2=score[0][j];
            flag=true;
            for(let k=1;k<num[1];k++){
                for(let z=0;z<num[0];z++){
                    if(score[k][z]== n2 && memo===-1) {
                        flag=false;
                        break;
                    }
                    else if(score[k][z]==n1) memo=n1;
                }
                memo=-1;
                if(flag==false) break;
            }
            if(flag==true){
                console.log(n1,n2);
                cnt++;
            } 
        }
    }

    console.log(cnt);
    return;
}

/**
 * spread 연산자
 * let [num,...score] = input; input의 첫번째 원소는 num, 나머지 원소들은 score로 저장
 * 
 * 첫번째 점수배열을 기준으로 잡고
 * 가능한 조합을 모두 탐색한다. (3,4), (3,1), (3,2), (4,1), (4,2), (1,2)
 * 첫번째 제외 나머지 점수배열들에 위의 조합에 대하여 앞의 원소가 뒤의 원소보다 앞에 있는지 확인 아닐경우 break;
 */