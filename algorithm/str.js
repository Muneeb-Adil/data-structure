a = "2345"
b = "5678"
var res = ""
var carry = ""
for(var i = a.length-1; i>=0;i--){
    var digit;
    digit = +(a[i]) + +(b[i]) + +carry
    digit = digit.toString()
    if (digit.length == 1){
        res = digit + res  
    }
    else{
        res = digit[1] + res 
        carry = digit[0]
    }
}
console.log(res)