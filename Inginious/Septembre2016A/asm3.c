int mp(int c, int d){
    int a=c;
    c+=c;
    c+=a;
    if(c<=d){
        a=c;
        return a;
    }
    else{
        a=d;
        return d;
    }
}
