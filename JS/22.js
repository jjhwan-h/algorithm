const fs = require('fs');
const readline = require('readline');

const rl = readline.createInterface({
    input: fs.createReadStream("./input_file/22.txt"),
    output: process.stdout
});

let input =[];

rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    console.log(calGrade2(input));
    process.exit();
})

const calGrade = (input)=>{
    const n = input[0][0];
    const score = input[1];
    //let grade=[];
    // for(let i=0;i<n;i++){
    //     grade.push(n);
    // }
    let grade = Array.from({length:n},()=>n);
    console.log(grade)

    for(let i=0;i<n;i++){
        for(let j=i+1; j<n; j++){
            if(score[i]<score[j])grade[i]--;
            else if(score[i]<score[j])grade[j]--;
            else {
                grade[i]--;
                grade[j]--;
            }
        }
    }
    return grade;

}

//오름차순 정렬
//let copy = score.slice().sort((a,b)=>a-b);
//indexOf(배열형의 원소)
//copy.indexOf(it) //인덱스 리턴
