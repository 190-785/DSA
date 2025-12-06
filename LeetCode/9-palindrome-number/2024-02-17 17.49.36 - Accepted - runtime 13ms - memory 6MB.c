bool isPalindrome(int x) {
    if(x<0){
        return 0;
    }
    else{
       long    i,temp=x,rev=0;
        
        for(i=0;temp!=0;i++){
            rev = (rev*10) + (temp%10);
            temp/=10;
            
        }
        if(rev==x){
            return 1;
        }
        else{
            return 0;
        }
    }
}
