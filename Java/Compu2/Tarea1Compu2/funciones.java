class funciones{

static public int fib(int n){
        int v;
        if(n==0){v=0;}
        else{if(n==1){v=1;}
                else{v=fib(n-1)+fib(n-2);}
        	}
	return v;}

static public int factR(int n){
	int v;
	if(n==0){v=1;}
	else{v=n*factR(n-1);}
	return v;}

static public int factNR(int n){
	int v=n;
	int i;
	for(i=(n-1);i>1;i--){v=v*i;}
	return v;}
static public int sumatoria(int n){
	int v;
	if(n==0){v=0;}
	if(n==1){v=1;}
	else{v=n+sumatoria(n-1);}
	return v;}
}//FIN
