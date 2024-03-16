/**
 * @file 37.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 연속부분수열2
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline')

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/37.txt"),
    output:process.stdout,
})
const input =[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=> parseInt(el,10)));
}).on("close",()=>{
    console.log(subSequence2(input));
    process.exit();
})

const subSequence2 = (input)=>{
    const [NM,arr] = input;
    const N=NM[0]; const M=NM[1];
    let lt=sum=cnt=0;
    let res = [];

    for(let rt=0;rt<arr.length;rt++){
        sum+=arr[rt];
        while(sum>M) sum-=arr[lt++];
        let tmp=rt;
        let sub=[];
        //cnt+=(rt-lt+1); //갯수만 구할것같으면
        while(tmp>=lt){
            sub.push(arr[tmp--]);
            res.push(sub.slice()); //배열이나 문자열의 일부분을 추출하여 새로운 배열을 생성.
        }
    }
    console.log(res);
    return res.length;
}


/* JS에서 배열은 참조값만 전달한다.
    따라서 아래와 같은코드를 사용하면 이전에 push된 sub값들이
    변경될 수 있다. */
// while(tmp>=lt){
//     sub.push(arr[tmp--]);
//     res.push(sub);
// }