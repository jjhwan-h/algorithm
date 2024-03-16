const fs = require('fs')
const input = fs.readFileSync('./input_file/16.txt').toString().trim();
const [...arr]=input;


const remove = (arr)=>{
    let mem =[]
    arr = arr.map((el)=>{
        if (!mem.includes(el)){
            mem.push(el);
            return el;
        }
        else{
            return
        }
    }).join('')


    console.log(arr)
}

/* 
중복을 제거하는 Set자료형을 사용하는 방법
let answer="";
answer = [...new Set(arr)].join("");

indexOf사용방법
arr.indexOf('k',1); 1번인덱스 후부터 k를 찾아라
만약 arr.indexof(arr[i])값이 i의 인덱스값과 다르다면 앞쪽문자열에 이미 존재하는 문자이다.
*/

remove(arr);