/**
 * @file 39.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 학급회장(해시)
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const { Hash } = require('crypto');
const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/39.txt"),
    output:process.stdout,
});

const input=[];

rl.on("line",(line)=>{
    input.push(line.split(' '));
}).on("close",()=>{
    Vote(input);
    process.exit();
});

const Vote=(input)=>{
    let hash = new Map();
    let max=0, leader="";
    [N,arr]=input[0];
    N=parseInt(N,10);
    arr=arr.split('');

    for(let i=0;i<N;i++) {
        hash.set(arr[i],(hash.get(arr[i]) || 0)+ 1)
    }
    
    for(let [key,value] of hash){
       if(max<value){
            max=value;
            leader=key;
       }
    }
    console.log("\n",leader);
    return;
}


/**
 *  Map과 Set의 차이점
 *  - Set은 값만을 저장하며 중복을 허용하지 않습니다.
    - Map은 키-값 쌍을 저장하며 각 키는 고유해야 합니다.
    - Set은 순서가 없지만, Map은 키-값 쌍의 삽입 순서를 유지합니다.
    - Set은 add() 메서드를 사용하여 값 추가, Map은 set() 메서드를 사용하여 키-값 쌍 추가.
*/

/**
 * for in 과 for of의 차이점
 * 
 * - 주로 for in은 배열의 index에 집중, 객체에 사용
 * - 주로 for of는 배열의 값에 집중(index를 가져올 수 도 있다.), iterable한 객체에 사용
 */

/**
 * 모든 전역객체에 해당 함수를 추가하는 코드
 *  Object.prototype.objCustom = function () {};
    Array.prototype.arrCustom = function () {};
 */