/**
 * @file 41.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 모든아나그램 찾기(해쉬, 투포인터, 슬라이딩윈도우)
 * @version 0.1
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/41.txt"),
    output:process.stdout,
});

const input=[];
rl.on("line",(line)=>{
    input.push(line.split(''));
}).on("close",()=>{
    anagram(input);
    process.exit();
});

const compareMaps=(map,map2)=>{
    let flag=1; //원소의 개수가 모두 같은지 체크 flag
    for(const [key,value] of map2){
        if(map.has(key) && map.get(key) === value) continue; //S부분배열과 T배열이 아나그램인지체크
        else flag=0;
    }
    return flag;
}
const anagram=(input)=>{
    [S,T]=input;
    let res=0;
    let map = new Map();
    let map2 = new Map();
    const size = T.length;
    let lp=0, rp=lp+size-1;

    for(let i=0;i<size;i++){
        map.set(S[i],(map.get(S[i])|| 0)+1) //S의 부분배열에 대한 Map
        map2.set(T[i],(map2.get(T[i])||0)+1) //T배열에 대한 Map
    }
    while(rp<S.length){
        if(compareMaps(map,map2)) res++;
        if(rp===S.length-1) break; //js는 segmentation fault같은 저수준에러는 발생시키지 않지만 개발된 프로그램에 따라 에러가 발생할 수 도 있다.
        if(map.get(S[lp])>1)  map.set(S[lp],(map.get(S[lp++])-1)); //lp가 가리키는 원소 map에서 감소
        else map.delete(S[lp++]);
        map.set(S[++rp],(map.get(S[rp])||0)+1); //rp가 가리키는 원소 map에서 증가
    }
    console.log(res);
    return;
}




