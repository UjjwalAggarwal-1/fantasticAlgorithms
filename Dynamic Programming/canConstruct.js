// can target strign be constructed from given word bank? 

//lets not add empty strings in the list
const canConstruct = (target,bank) => {
    let sol = [];
    if(target==="") return sol;

    for (let a of bank){
        // console.log(target,a,bank);
        if(target.substring(0,a.length)===a){
            nextItr = canConstruct(target.substring(a.length),bank);
            if (nextItr){
                sol.push(a);
                sol=[...sol,...nextItr];
                return sol;
            }
        }
    }
    return null;
}

// ideas tested :
// console.log('abc'.substring(0,'ab'.length)==='ab');
// console.log(['a','b','c'].join(""))

//tests :
// console.log(canConstruct('abvcdef',['ab','bc','ef','cd','abcd'])) 
// console.log(canConstruct('abcdef',['ab','bc','ef','cd','abcd'])) 
// console.log(canConstruct('wabcdef',['ab','bc','ef','cd','abcd'])) 


//new idea, akin to subtracting strings
// console.log('ab'.replace('a',''))

function remIfFirst(target,sub){
    if(target.indexOf(sub)===0) {
        target=target.replace(sub,"");
        return target;
    }
    return null;
}

const canConstruct2 = (target,bank) => {
    if(target==="") return [];

    for(let a of bank){
        let res = remIfFirst(target,a);
        if(res!==null) {    // not using equality was skipping basecase(empty string)
            let temp = canConstruct2(res, bank); 
        if (temp){
                temp.push(a);
                return temp;
            }
        }
    }
    return null;
}

// console.log(canConstruct2('ab',['b','a']))
// console.log(canConstruct2('aasdfb',['b','a']))
// console.log(canConstruct2('aabbaabaab',['bb','aa','b']))
// console.log(canConstruct2('enterapotentpot',['a','p','ent','enter','ot','o','t']));

