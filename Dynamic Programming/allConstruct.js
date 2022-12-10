// tabulation

const allConstruct=(target, bank)=>{
    if (target==="") return [];
    var table = Array(target.length +1).fill().map(()=>[]);
    // \\\\\\\\\\\\\\
                table[0].push([]);
                // return [[]] for empty string and [] for non solvable
    // \\\\\\\\\\\\\\\\\\\\\
    for(var i =0;i<=target.length;i++){
        for (let a of bank){
            if(target.slice(i,i+a.length)===a){
                //\\\\\\\\\\\
                // if (!table[i].length)
                // table[i+a.length].push([a]);
                // else
                //\\\\\\\\\\\\
                for (let vv of table[i]){
                    table[i+a.length].push([...vv,a]);
                }
            }
        }
    }
    // console.log(table);
    return table[target.length];
}

console.log(allConstruct("abcdef",["ab","cd","abc","abcd","ef"]));
console.log(allConstruct('enterapotentpot',['a','p','ent','enter','ot','o','t']));
