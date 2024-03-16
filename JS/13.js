/*\
대소문자 변환
*/

const readline = require('readline');

const rl = readline.createInterface({
    input:process.stdin,
    output:process.stdout
})

rl.question('',(str)=>{
    console.log(translate(str));

    rl.close();     
})

const translate = (str)=>{ //48, 65, 97
    str = [...str].map((el)=>{
        tmp = el.charCodeAt(0); //el의 0번째 문자를 unicode로 변환
        if(tmp>=65&&tmp<=90) return el.toLowerCase();
        else if(tmp>=97 && tmp<=122) return el.toUpperCase();
    }).join('');

    return str;
}