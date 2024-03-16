/*
7난쟁이
*/
const readline = require('readline');



// readline 모듈을 사용하여 인터페이스를 생성합니다.
const rl = readline.createInterface({
  input: process.stdin,  // 표준 입력 스트림을 사용합니다.
  output: process.stdout // 표준 출력 스트림을 사용합니다.
});


// 사용자에게 질문을 물어봅니다.
rl.question('', (dwarf) => {
    
        // 사용자로부터 정수를 입력받는데 빈칸을 기준으로 나눈다.
        //입력받은 수는 자동으로 string형태가 되는데 이를 map함수를 통해 각각 정수형으로 변형.
        dwarf = dwarf.split(' ');
        dwarf = dwarf.map(str=>parseInt(str,10));
  
        Checkfake(dwarf);

        rl.close();
 
});

const Checkfake = (dwarf)=>{
    
    //dwarf의 총합 
    // 0으로 초기화 한 후 a의 값에 계속 누적
    let sum = dwarf.reduce((a,b)=> a+b,0 );
    let flag =0;
    // dwarf.forEach((e,i)=>{
    //     dwarf.forEach((v,j)=>{
    //         console.log(j);
    //         if(i!==j && 100 === sum-(e+v)){
    //             filtered = dwarf.filter((el)=> el !== e && el !== v);
    //         }
    //     })
    // })

    for(let i=0; i< dwarf.length; i++){
        for(let j=i+1; j<dwarf.length ; j++){
            if(100 === sum-(dwarf[i]+dwarf[j])){
                filtered = dwarf.filter((el)=> el !== dwarf[i] && el !== dwarf[j]);
                //splice로  해결할 수 도 있다.
                // splice를 사용할 경우 앞으로땡겨져서 인덱스가 변한다. 따라서 뒤에 있는 수 먼저 지운다.
                //dwarf.splice(j,1); dwarf.splice(i,1); 
                flag=1;
                break;
            }
        }
        if(flag===1) break;
    }

    //console.log(dwarf);
    console.log(filtered);
}
