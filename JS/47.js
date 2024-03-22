/**
 * @file 47.js
 * @author jang jeong hwan (you@domain.com)
 * @brief 공주 구하기
 * @version 0.1
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

const fs = require('fs');
const readline = require('readline');
const rl = readline.createInterface({
    input:fs.createReadStream("./input/47.txt"),
    output:process.stdout,
});

const input=[];
rl.on("line",(line)=>{
    input.push(line.split(' ').map((el)=>parseInt(el,10)));
}).on("close",()=>{
    Solve(input);
    process.exit();
});
class Queue {
    constructor(capacity) {
      this.capacity=capacity;
      this.storage = new Array(capacity);	// 값을 저장할 객체
      this.front = 0;	// 첫 원소를 가리킬 포인터
      this.rear = 0;	// 마지막 원소를 가리킬 포인터
      this.size=0;
    }
    enqueue =(v)=>{
        this.storage[this.rear]=v;
        this.rear = (this.rear+1)%this.capacity;
        this.size++;
    };
    dequeue =()=>{
        const num = this.storage[this.front];
        this.storage[this.front]=undefined;
        this.front = (this.front+1)%this.capacity;
        this.size--;
        return num;
    };
    empty=()=>{
        if(this.size) return false;
        else return true;
    }
};

const Solve = (input) =>{
    let cnt=0,el;
    const [N,K] = input[0];
    que = new Queue(N);
    
    for(let i=1;i<=N;i++) que.enqueue(i);
    
    while(!que.empty()){
        el = que.dequeue();
        cnt++;
        if(cnt===K) {cnt=0;}
        else {
            que.enqueue(el);
        }
    }
    console.log(`\n${el}`);

    return;
};

const Solve2 = (input) =>{
    let cnt=0,el;
    const [N,K] = input[0];
    
    que = Array.from({length:N},(v,i)=> i+1);
    
    while(que.length){
        el = que.shift();
        cnt++;
        if(cnt===K) {cnt=0;}
        else {
            que.push(el);
        }
    }
    console.log(`\n${el}`);

    return;
};

/**
 * 
 */

/**
 * JS에서는 배열의 shift연산을 통해서 구현할 수 도 있지만,
 * shift연산은 원소들을 앞으로 한칸씩 당겨주는 연산
 * 따라서 배열의 크기가 커질 경우 이를 처리하기위한 연산량이 O(N)만큼 증가한다.
 * 
 * Array.from() 유사배열객체를 배열로 변환할때 사용
 * 
 *  let arrayLike = { 0: 'a', 1: 'b', 2: 'c', length: 3 };
    let newArray = Array.from(arrayLike);
    console.log(newArray); // ['a', 'b', 'c']

    let iterableObject = 'hello';
    let newArray = Array.from(iterableObject);
    console.log(newArray); // ['h', 'e', 'l', 'l', 'o']

    let set = new Set([1, 2, 3]);
    let newArray = Array.from(set, x => x * 2);
    console.log(newArray); // [2, 4, 6]


 */
