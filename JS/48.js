/**
 * @file 48.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 교육과정 설계
 * @version 0.1
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
    input:fs.createReadStream("./input/48.txt"),
    output:process.stdout,
});

const input =[];
rl.on("line",(line)=>{
    input.push(line.split(''));
}).on("close",()=>{
    Solve2(input);
    process.exit();
});

class Queue{
    constructor(capacity){
        this.capacity=capacity;
        this.storage=new Array(capacity);
        this.front=0;
        this.rear=0;
        this.size=0;
    }
    enqueue =(v)=>{
        if(this.size>=this.capacity) return false;
        this.storage[this.rear]=v;
        this.rear = (this.rear+1)%this.capacity;
        this.size++;
        return true;
    };
    dequeue=()=>{
        if(!this.size) return undefined;
        const num = this.storage[this.front];
        this.storage[this.front]=undefined;
        this.front = (this.front+1)%this.capacity;
        this.size--;
        return num;
    };
    getFront=()=>{
        if(!this.size) return undefined;
        return this.storage[this.front];
    };
    empty=()=>{
        if(this.size) return false;
        else return true;
    };
};

const Solve=(input)=>{
    [manSubject, subject] = input;
    que = new Queue(30);

    manSubject.forEach((el)=> que.enqueue(el));
    subject.forEach((el)=>{
        if(el=== que.getFront()) que.dequeue();
    })
    console.log(que.storage)
    console.log(que.size)
    if(que.empty()) console.log("YES");
    else console.log("NO");
};

const Solve2=(input)=>{
    let res="YES";
    [manSubject, subject] = input;

    subject.forEach((el)=>{
        if(manSubject.includes(el)){
            if(el!==manSubject.shift()) res="NO";
        }
    })
    if(manSubject.length>0) res="NO";

    console.log(res);
}



