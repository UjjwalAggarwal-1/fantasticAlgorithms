/*
        some lambda thoughts

amp = (val)=>123+val//, lambda
console.log(amp(3)) 
[Function: amp]
console.log((val)=>123+val) 
[Function], anonymous, lambda
*/



//      fib function

// function fib(n) {
//     if (n<0) return -1;
//     if (n <= 1) return n;
//     return fib(n - 1) + fib(n - 2);
// }



//      fib function arrow operator

/** 
const fib = (n) => {
    if (n<0) return -1;
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

console.log(fib(2))
console.log(fib(253)) // shayad kabhi print hi na ho     // time 2^n, space n
console.log(fib(2)) // shayad kabhi yaha tak pohunche hi nahi 
*/

/** 
//      fib with memoization

const fib = (n,memoMap={0:0,1:1,2:1}) =>{
    if (n<0) return -1;
    if (n in memoMap) return memoMap[n];
    memoMap[n]=fib(n-1,memoMap) + fib(n-2,memoMap);
    return memoMap[n];
}

console.log(fib(03))
console.log(fib(10))
console.log(fib(20))
*/

/** 
//      fib in for loop

let a=0;
let b=1;
for(var i=0;i<20;i++){
    let temp = b;//1//1
    b=a+b;//1//2
    a=temp;//1//1
    console.log(b);

}
*/

