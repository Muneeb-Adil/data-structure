function palindrome(p){
    j=p.length-1;
    flag = true
    for(var i=0;i<p.length;i++){
        if(p[i]==p[j]){
            j--;
        }
        else{
            flag = false;
            console.log(p+" is not a Palindrome")
            break;
        }
    }
    if(flag){
    console.log(p + " is a palindrome")}
}
palindrome("madam")