// const fs = require('fs');
// const readline = require('readline');

// const rl = readline.createInterface({
//     input:fs.createReadStream("./input_file/23.txt"),
//     output:process.stdout
// });

// const intput =[];
// rl.on("line",(line)=>{
//     input.push(line.split(' ').map((el)=>parseInt(el,10)));
// }).on("close",()=>{
//     console.log();
//     process.exit();
// })

const solution = (arr) => {
    const resultArr = [
        ...arr, //1차원배열로 분해
        ...arr.map((_,location) => Array.from({length:arr.length}, (_,idx) => arr[idx][location])), //Array.from({새로운 배열길이}, (_,idx)=>)
        Array.from({length:arr.length}, (_, idx) => arr[idx][idx]),
        Array.from({length:arr.length}, (_,idx) => arr[arr.length-idx-1][idx])
    ]
    console.log( ...arr.map((_,location) => Array.from({length:arr.length}, (_,idx) => arr[idx][location])));
    console.log(Array.from({length:arr.length}, (_, idx) => arr[idx][idx]));
    console.log(Array.from({length:arr.length}, (_,idx) => arr[arr.length-idx-1][idx]));
    return Math.max(...resultArr.map(list => list.reduce((pre, cur) => pre+cur, 0)))
}

console.log(solution([
    [10, 13, 10, 12, 15],
    [12, 39, 30, 23, 11],
    [11, 25, 50, 53, 15],
    [19, 27, 29, 37, 27],
    [19, 13, 30, 13, 19]
]));