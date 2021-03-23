int mang{=====================================MANG============================================
#include <stdio.h>
#include <math.h>

//NHAP MANG
void input(int n, int a[]){
	for(int i=0; i<n; i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
//XUAT MANG
void display(int n, int a[]){
	for(int i=0; i<n; i++){
		printf("%-5d",a[i]);
	}
}
//TIM KIEM MOT PHAN TU TRONG MANG
void search(int n, int a[], int &x){
	int check=1;
	printf("Enter x = ");
	scanf("%d", &x);
	for(int i=0; i<n; i++){
		if(a[i]==x){
			printf("Tim duoc gia tri %d tai vi tri %d\n",x,i);
			check=0;
		}
	}
	if(check==1){
		printf("Khong tim thay phan tu %d trong mang",x);
	}
}
//KIEM TRA TINH CHAT CUA MANG (Co toan so duong hay khong)
void check(int n, int a[]){
	int check=1;
	for(int i=0; i<n; i++){
		if(a[i]<0){
			check=0; break;
		}
	}
	if(check==1) 
		printf("True");
	if (check==0)
		printf("False");
}
//TACH MANG VI TRI BAT KY
void separate(int n, int a[], int &position){
	printf("Enter position = ");
	scanf("%d",&position);
	printf("Array 1: ");
	display(position, a);
	int j=0;
	for(int i=position; i<n; i++){
		a[j++]=a[i];
	}
	printf("\nArray 2: ");
	display(n-position,a);
}
//TACH THANH HAI MANG AM VA DUONG
void separateSign(int n, int a[], int &j, int negative[]){
	j=0;
	for(int i=0; i<n; i++){
		if(a[i]<0){
			negative[j++]=a[i];
		} 
	}
	display(j,negative);
}
//GOP MANG
void addArray(int &n, int a[], int j, int negative[]){
	n+=j;
	int n1=n;
	for(int i=j; i>=0; i--)
		a[n1--]=negative[i];
	printf("\n");
	display(n,a);
}
//TIM GIA TRI LON NHAT TRONG MANG
void max(int n, int a[]){
	int max=a[0];
	for(int i=1; i<n; i++)
		if(a[i]>max)
			max=a[i];
	printf("Max = %d",max);
}
//TIM GIA TRI NHO NHAT
void min(int n, int a[]){
	int min=a[0];
	for(int i=1; i<n; i++)
		if(a[i]<min)
			min=a[i];
	printf("Min = %d",min);
}
//SAP XEP MANG TANG DAN
swap(int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void increase(int n, int a[]){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
	display(n,a);
}
//SAP XEP MANG GIAM DAN
void decrease(int n, int a[]){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]<a[j])
				swap(a[i],a[j]);
	display(n,a);
}
//SAP XEP 5 PHAN TU DAU TIEN
void increase5First(int n, int a[]){
	for(int i=0; i<5; i++)
		for(int j=i+1; j<5; j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
	display(n,a);
}
//SAP XEP 5 PHAN TU CUOI CUNG
void increase5last(int n, int a[]){
	for(int i=n-6; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
	display(n,a);
}
//THEM MOT PHAN TU VAO MANG
void add(int &n, int a[], int &position, int &x){
	printf("Enter position = ");
	scanf("%d",&position);
	printf("Enter value add = ");
	scanf("%d",&x);
	n+=1;
	for(int i=n; i>position; i--){
		a[i]=a[i-1];
	}
	a[position]=x;
	display(n,a);
}
//XOA MOT PHAN TU TRONG MANG
void erase(int &n, int a[], int &position){
	printf("Enter position = ");
	scanf("%d",&position);
	for(int i=position; i<n-1; i++){
		a[i]=a[i+1];
	}
	display(--n,a);
	
}
//SUA MOT PHAN TU TRONG MANG
void edit(int n, int a[], int &position, int &x){
	printf("Enter position = ");
	scanf("%d", &position);
	printf("Enter x = ");
	scanf("%d",&x);
	a[position]=x;
	display(n,a);
}

//HAM KIEM TRA SO NGUYEN TO
int isPrime(int n){
	if(n<2) return 0;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}
//XOA PHAN TU TRUOC SO NGUYEN TO THU 2
void advance(int n, int a[]){
	int count=0;
	for(int i=0; i<n; i++){
		if(isPrime(a[i])==1) count++;
		if(count==2) {
			for(int j=i-1; j<n; j++){
				a[j]=a[j+1];
			}
			break;
		}
	}
	display(--n,a);
}
int main(){
	int n,x,position,j;
	int a[100], negative[100];
	printf("Enter n = ");
	scanf("%d",&n);
	
	input(n,a);
//	search(n,a,x);
//	check(n,a);
//	separateSign(n,a,j,negative);
//	addArray(n,a,j,negative);
//	max(n,a);
//	min(n,a);
//	increase(n,a);
//	decrease(n,a);
//	add(n,a,position,x);
//	erase(n,a,position);
//	edit(n,a,position,x);
//	increase5First(n,a);
//	increase5last(n,a);
//	advance(n,a);
}
}


int kiemtra{================================KIEM TRA========================================
#include <stdio.h>
#include <math.h>

//HAM KIEM TRA SO NGUYEN TO
int isPrime(int n){
	if(n<2) return 0;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}
//HAM KIEM TRA SO CHINH PHUONG
int isSquare(int n){
	if(n<2) return 0;
	if(sqrt(n)==(int)sqrt(n)) return 1;
	else return 0;
}
//HAM KIEM TRA SO HOAN HAO
int isPerfect(int n){
	int s=0;
	for(int i=1; i<n; i++){
		if(n%i==0)	s+=i;
	}
	if(n==s)	return 1;
	else	return 0;
}
//HAM KIEM TRA SO PALINDROME
int isPalindrome(int n){
	int sum=0,r;
	int check=n;
	while (n>0){
		r=n%10;
		sum=sum*10+r;
		n/=10;
	}
	if(sum==check) return 1;
	else return 0;
}
//HAM KIEM TRA SO CHIA HET CHO MOT SO X (VI DU CHIA HET CHO 7)
int isDivisible(int n){
	if(n%7==0) return 1;
	else return 0;
}
//HAM KIEM TRA 1/(2*N+1)<=C
void check1(double c){
	int n=0;
	while(1){
		if(1.0/(2*n+1)<=c)	break;
		n++;
	}
	printf("%d\n",n);
}
//HAM KIEM TRA |X^N/N!<=C|
void check2(double c){
	int n=1;
	double t=1;
	double x=2;
	while(1){
		t*=x/n;
		if(fabs(t)<=c)	break;
		n++;
	}
	printf("%d\n",n);
}
//HAM KIEM TRA |X^(2*N+1)/(2*N+1)!<=C|
void check3(double c){
	int n=3;
	double x=2;
	double t=x;
	while(1){
		if(fabs(t)<=c)	break;
		t*=x*x/(n*(n-1));
		n+=2;
	}
	printf("%d\n",(n-1)/2);
}

int main(){
	int n;
	printf("Enter n = ");
	scanf("%d", &n);
	
//	for(int i=0; i<=n; i++){
//		if(isPrime(i)==1)	printf("%5d",i);
//	}

//	for(int i=0; i<=n; i++){
//		if(isSquare(i)==1)	printf("%5d",i);
//	}

//	for(int i=0; i<=n; i++){
//		if(isPalindrome(i)==1)	printf("%7d",i);
//	}	

	if(isPerfect(n)==1)	printf("True");
	else	printf("False");

//	for(int i=0; i<=n; i++){
//		if(isDivisible(i)==1)	printf("%7d",i);
//	}	
//	double c=0.00001;
//	check1(c);
//	check2(c);
//	check3(c);
	
}
}


int chuoi{====================================CHUOI===========================================
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
//strcpy(s1,s2): sao chep chuoi nguon vao chuoi dich
//strcat(s1,s2): ghep chuoi nguon vao chuoi dich
//strcmp(s1,s2): so sanh chuoi 1 vs 2

//HAM DEM DO DAI CUA CHUOI
int countLength(char s[]){
	int count=0;
	while(s[count++]!=NULL){
	}
	return count-1;
}
//HAM DEM SO KY TU TRONG CHUOI
int countCharacter(char s[]){
	int count=0,i;
	while(s[i]!=NULL){
		if(isalpha(s[i])) count++;
		i++;
	}
	return count;
}
//HAM CHUYEN TAT CA CAC KI TU THANH CHU HOA
void upper(char s[]){
	int i=0;
	while(s[i]!=NULL){
		if(s[i]>='a'&&s[i]<='z')	s[i]-=32;
		i++;
	}
	puts(s);
}
//CHUYEN TAT CA THANH CHU HOA
for (i=0;i<n;i++)
	{
		strupr(s[i]);
	}


//HAM CHUYEN TAT CA CAC KI TU THANH CHU THUONG
int lower(char s[]){
	int i=0;
	while(s[i]!=NULL){
		if(s[i]>='A'&&s[i]<='Z')	s[i]+=32;
		i++;
	}
	puts(s);
}
hoac
//CHUYEN TAT CA THANH CHU THUONG + VIET HOA CHU DAU TIEN
for (i=0;i<n;i++)
	{
		strlwr(s[i]);
		s[i][0] = toupper(s[i][0]);
	}

//HAM CHUYEN TAT CA CAC KI TU THANH CHU HOA NHUNG VAN GIU MANG CU
void upperAdvance(char s[]){
	int i=0;
	char p[100];
	strcpy(p,s);
	while(p[i]!=NULL){
		if(p[i]>='a'&&p[i]<='z')	p[i]-=32;
		i++;
	}
	puts(s);
	puts(p);
}
//HAM CHUYEN TAT CA CAC KY TU DAU TIEN CUA MOI TU THANH KY TU HOA
void beautyCharacter(char s[]){
	for(int i=0; i<=strlen(s); i++){
		if(s[i]==32&&s[i+1]!=32){
			if(s[i+1]>='a'&&s[i+1]<='z') s[i+1]-=32;
		}
		if(s[0]>='a'&&s[0]<='z') s[0]-=32;
	}
	puts(s);
}
//HAM XOA CAC KHOANG TRANG THUA
void deleteSpace(char s[]){
	for(int i=0; i<strlen(s); i++){
		if(s[i]==32&&s[i+1]==32){
			for(int j=i; j<strlen(s); j++)
				s[j]=s[j+1];
			i--;	
			s[strlen(s)]=NULL;
		}
	}
	if(s[0]==32){
		for(int i=0; i<strlen(s); i++)
			s[i]=s[i+1];
		s[strlen(s)]=NULL;
	}
	if(s[strlen(s)]==32)
		s[strlen(s)]=NULL;
	puts(s);
}
//HAM DEM XEM BAO NHIEU TU TRONG CHUOI
void countWord(char s[]){
	int word=0;
	for(int i=0; i<strlen(s); i++)
		if(s[i]!=32&&(s[i+1]==32||s[i+1]==NULL))	word++;
	printf("%d", word);
}
//HAM CAT CAC TU IN RA THANH CAC DONG LIEN TIEP NHAU
void cutWord(char s[]){
	char *token;
	token=strtok(s," \t");
	while(token!=NULL){
		puts(token);
		token=strtok(NULL," \t");
	}
}
//HAM TIM TU CO CHIEU DAI LON NHAT VA IN RA TU DO
int numLongestWord(char s[]){
	char *token;
	char p[100],s2[100];
	int character;
	strcpy(s2,s);
	token=strtok(s2," \t");
	character=strlen(token);
	strcpy(p,token);
	while(token!=NULL){
		token=strtok(NULL," \t");
		if(token!=NULL){
			if(strlen(token)>character)
				character=strlen(token);
		}	
	}
	return character;
}
void longestWord(char s[]){
	char *token;
	int num=numLongestWord(s);
	token=strtok(s," \t");
	if(strlen(token)==num)	puts(token);
	while(token!=NULL){
		token=strtok(NULL," \t");
		if(token!=NULL)
			if(strlen(token)==num)
				printf("%s ",token);
	}
}
//HAM KIEM TRA TEN CO HOP LE KHONG
void checkName(char s[]){
	bool check=true;
	for(int i=0; i<strlen(s); i++){
		if(isalpha(s[i])==0&&s[i]!=32){
			check=false;
			break;
		}	
	}
	if(check==true)	printf("Invalid");
	else printf("Not invalid");
}
//HAM IN RA N KI TU DAU TIEN
void cutNFirst(char s[], int &n){
	printf("Enter n: ");
	scanf("%d", &n);
	int count=0;
	for(int i=0; i<strlen(s); i++){
		if(s[i]!=' ')
			count++;
		if(count==n) 
			s[i+1]=NULL;
	}
	puts(s);
}
//HAM HOAN DOI HAI CHUOI
void swapString(char s1[], char s2[]){
	char y[10];
	strcpy(y,s1);
	strcpy(s1,s2);
	strcpy(s2,y);
}
//HAM DAO CHUOI NGUOC LAI
void swapString2(char s[]){
	char temp[10][10]; //so tu / so ky tu
	int i=0;
	//Cat cac tu trong chuoi
	char *token;
	token=strtok(s," \t");
	while(token!=NULL){
		strcpy(temp[i],token);
		token=strtok(NULL," \t");
		i++;
	}
	for(int j=0; j<i/2; j++){
		swapString(temp[j],temp[i-1-j]);
	}
	for(int j=0; j<i; j++){
		printf("%s ",temp[j]);
	}
}
//HAM DEM XEM TU DAI NHAT CO BAO NHIEU KY TU
void maxCharacter(char s[]){
	int max=0;
	char *token;
	token=strtok(s," \t");
	while(token!=NULL){
		if(strlen(token)>max) max=strlen(token);
		token=strtok(NULL," \t");
	}
	printf("%d", max);
}
//HAM XOA TAT CA CAC CHU CAI DAI HON TU DAU TIEN TRONG CHUOI
void deleWordAdvance(char s[]){
	int firstWord;
	char s2[10][10];
	char *token;
	token=strtok(s," \t");
	firstWord=strlen(token);
	while(token!=NULL){
		if(strlen(token)<=firstWord){
			printf("%s ",token);
		} 
		token=strtok(NULL," \t");
	}
}
//HAM DOI CHO CHU NGAN NHAT VA CHU DAI NHAT DAU TIEN
void swapAdvance(char s[]){
	char s1[100], s2[100], s3[100];
	//Tim chu dai nhat trong chuoi
	int max=0;
	strcpy(s1,s);
	char *token;
	token=strtok(s1," \t");
	while(token!=NULL){
		if(strlen(token)>max) max=strlen(token);
		token=strtok(NULL," \t");
	}
	//Tim chu ngan nhat trong chuoi
	int min;
	strcpy(s2,s);
	char *token2;
	token2=strtok(s2," \t");
	min=strlen(token2);
	while(token2!=NULL){
		if(strlen(token2)<min) min=strlen(token2);
		token2=strtok(NULL," \t");
	}
	//Gan chuoi vao mang 2 chieu
	char temp[10][10];
	int i=0;
	strcpy(s3,s);
	char *token3;
	token3=strtok(s3," \t");
	while(token3!=NULL){
		strcpy(temp[i],token3);
		i++;
		token3=strtok(NULL," \t");
	}
	char y[1][10];
	for(int j=0; j<i; j++){
		for(int k=0; k<i; k++){
			if(strlen(temp[j])==max&&strlen(temp[k])==min){
				strcpy(y[1],temp[j]);
				strcpy(temp[j],temp[k]);
				strcpy(temp[k],y[1]);
				break; break;
			}
		}
	}
	for(int j=0; j<i; j++){
		printf("%s ",temp[j]);
	}
}
int main(){
	char s[100];
	fflush;
	gets(s);
	
//	printf("%d", countLength(s));
//	printf("%d",strlen(s));
	
//	printf("%d", countCharacter(s));
	
//	upper(s);
//	strupr(s);
//	puts(s);
	
//	lower(s);
//	strlwr(s);
//	puts(s);
	
//	upperAdvance(s);

//	beautyCharacter(s);

//	deleteSpace(s);

//	countWord(s);

//	cutWord(s);

//	longestWord(s);

//	checkName(s);

//	int n;
//	cutNFirst(s,n);

//	char s1[100], s2[100];
//	fflush(stdin); gets(s1); 
//	fflush(stdin); gets(s2);
//	swapString(s1,s2);
//	puts(s1); puts(s2);

//	swapString2(s);

//	maxCharacter(s);
	
//	deleWordAdvance(s);
	
//	swapAdvance(s);
}
}


int other{====================================MOT SO HAM KHAC=================================
#include <stdio.h>
//HAM TIM PHAN TU LON THU N TRONG MANG
void maxAdvance(int &n, int a[], int &x){
	int max1,maxn,min;
	printf("Enter n: ");
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	printf("Enter x: ");
	scanf("%d",&x);
	max1=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>max1)	max1=a[i];
	min=a[0];
	for(int i=1;i<n;i++)
		if(a[i]<min)	min=a[i];
	if(x==1)	maxn=max1;
	if(x>1){
		for(int j=1;j<x;j++){
		maxn=min;
		for(int i=1;i<n;i++)
			if(a[i]>maxn&&a[i]<max1)	maxn=a[i];
		max1=maxn;
		}
	}
	printf("%d",maxn);
}

//HAM TIM UOC CHUNG LON NHAT
int gcd(int a, int b){
	while(a!=b){
		if(a>b)	a-=b;
		if(b>a) b-=a;
	}
	return a;
}
//HAM TIM BOI CHUNG NHO NHAT
int lcm(int a, int b){
	return (a*b/gcd(a,b));
}
//HAM DAO NGUOC SO
int swapNumber(int n){
	int temp;
	while(n!=0){
		temp=temp*10+n%10;
		n/=10;
	}
	printf("%d",temp);
}
//HAM CHUYEN SO SANG DANG NHI PHAN
int main(){
//	int n, a[100], x;	
//	maxAdvance(n,a,x);

//	int a, b;
//	scanf("%d %d",&a,&b);
//	printf("GCD: %d",gcd(a,b));
//	printf("LCM: %d",lcm(a,b));
	
	int n;
	scanf("%d",&n);
	swapNumber(n);
}
}


int taylor{===================================TAYLOR==========================================
#include <stdio.h>
#include <math.h>

//HAM COS X = 1 - X^2/2! + X^4/4! -...+(-1)^N*X^2N/(2N)!
void funCos(double x, double &t, int n){
	for(int i=n; i>0; i--)
		t=1.0-t*x/(2*i-1)*x/(2*i);
	printf("%lf\n",t);
}
//HAM SIN X = X/1! - X^3/3! + X^5/5!-...+(-1)^N*X^(2N+1)/(2n+1)!
void funSin(double x, double &t, int n){
	for(int i=n; i>0; i--)
		t=1.0-t*x/(2*i)*x/(2*i+1);
	t*=x;
	printf("%lf\n",t);
}
//HAM E^X=1+X/1! + X^2/2! +...+ X^N/N!
void funpow(double x, double &t, int n){
	for(int i=n; i>0; i--)
		t=1+x*t/i;
	printf("%lf\n",t);
}
//HAM PI=4*(1-1/3+1/5-1/7+...+(-1)^N1/2N+1)
void funpi(double c){
	double pi=0;
	int i=0,d=1;
	while(1){
		if(fabs(1.0/(2*i+1))<=c)	break;
		i++;
	}
	for(int j=1; j<=(2*i+1); j+=2){
		pi+=d*1.0/j;
		d=-d;
	}
	printf("%lf",4*pi);
}

int main(){
	int n;
	double x,t,c;
//	printf("Enter x = ");
//	scanf("%lf",&x);
//	printf("Enter n = ");
//	scanf("%d",&n);
//	funCos(x,t,n);
//	funSin(x,t,n);
//	funpow(x, t, n);
//	printf("%lf",exp(x));
	
	printf("Enter c = ");
	scanf("%lf",&c);
	funpi(c);
}
}
