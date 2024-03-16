const fs = require('fs')
const input = fs.readFileSync('./input_file/15.txt').toString().trim();
const [...arr]=input;

const getCenter = (arr)=>{
    let len = arr.length
    //console.log(arr)
    if(len%2===0){
        console.log(`${arr[len/2-1]} ${arr[len/2]}`);
    }
    else{
        console.log(arr[parseInt(len/2,10)]);
        //만약 string일 경우 arr.substring(len/2,len/2+1);
    }
}

getCenter(arr);