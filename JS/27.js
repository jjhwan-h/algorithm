/**
 * 가장짧은 문자거리
 */

const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/27.txt"),
    output:process.stdout
});

let input=[];
rl.on("line",(line)=>{
   input= line.split(' ').map((el)=> el)
}).on("close",()=>{
    console.log(getDist(input));
    process.exit();
});

const getDist=(input)=>{
    const str=input[0];
    const res=Array.from({length:str.length},()=>0);
    let pt=str.length+1;
    // ->
    str.split('').forEach((el,idx)=>{
        if(el==='e') pt=0;
        else res[idx]=++pt;
    })
    pt=0;
    // <-
    for(let i=str.length-1;i>=0;i--){
        if(str[i]==='e') pt=0;
        else{
            if(res[i]>pt) res[i]=++pt;
        }
    }

    return res;
}

// const posText = str.split('') //string -> array
//                 .map((el,idx)=>{if(el===text) return idx;}) // text에 해당하는 index리턴. 아닐경우 undefined
//                 .filter((el)=>el!==undefined); //undefined 제거