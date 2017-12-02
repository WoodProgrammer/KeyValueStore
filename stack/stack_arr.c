#include <stdio.h>
#include <stdlib.h>

int *dizi;//dizi tanımında değişken kullanamadığımız için pointer kullanıyoruz.
int boyut=2;//dizinin boyutunu tutucak.
int tepe=0;//stack'in tepe değerni tutucak

void push(int a){

	if(tepe>=boyut){// eger tepenin değeri boyuttan büyük olursa
		int * dizi2 = (int *)malloc(sizeof(int)*boyut*2);//dizi2 diye bir pointer tanımlıyoruz ve boyutun 2 katı kadar bellekte yer ayırıyoruz.		
		for(int i=0;i<boyut;i++)//Bunu yapma sebebimiz dizide tanımlı verileri yeni dizi2 ye aktarmak için yapıyoruz.Diğer türlü direk eşitlediğimizde verileri dizi2 ye aktarmıyacak. 
			dizi2[i]=dizi[i];
		free(dizi);//Burada free fonk ile dizi adındaki diziyi bellekten siliyoruz.
		dizi=dizi2;//dizi yi dizi2 ye eşitliyoruz.
		boyut *= 2;//buradada boyutu 2 kat arttırıyoruz.
	}
	dizi[tepe++] = a;//tepe değerini arttırarak yeni veriyi, yeni tepe değerine ekliyoruz.
}

int pop(){
	if(dizi==NULL){
		printf("Dizi bos");
	}
	
	if(tepe<=boyut/4){
		int * dizi2 = (int *)malloc(sizeof(int)*boyut/2);
		for(int i=0;i<boyut;i++)
			dizi2[i]=dizi[i];
		free(dizi);
		dizi=dizi2;
		boyut /=2;
	}


	return dizi[--tepe];

}

void show(){
	for(int i=0; i<tepe; i++){
		printf("%d\n",dizi[i]);
	}
}


int main(){
	dizi = (int *)malloc(sizeof(int)*2);
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	show();
	printf("popped: %d\n",pop());
	printf("popped: %d\n",pop());
	show();


}
