const readline = require('readline');
const fs = require('fs');

const rl = readline.createInterface({
    input:fs.createReadStream("./input_file/18.txt"),
    output:process.stdout
})

let arr =[];

rl.on("line",(line)=>{
    arr.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on('close',()=>{
    console.log("\n");
    console.log(bigNum(arr));
    process.exit();
})

const bigNum= (arr)=>{
    let n = arr[0];
    arr = arr[1];
    let res = [];
    res.push(arr[0]);

    for(let i=1;i<n;i++){
        if(arr[i]>arr[i-1]) res.push(arr[i]);
    }
    return res.join(' ');

};
