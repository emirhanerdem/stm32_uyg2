/*
 * bizimKutuphane.h
 *
 *  Created on: Dec 5, 2024
 *      Author: ofab
 */

#ifndef INC_BIZIMKUTUPHANE_H_
#define INC_BIZIMKUTUPHANE_H_




// DİKKAT! Bu header file main.c dosyasına eklenirke USER Include bölümüne ekleyin yoksa eklenmez

void supur(int * );
void dispYak(int );
void basamakAyir(int ,int * ,int );




//================================================ 7 Segment Display için LookUP ========================
int rakamlar[10][8]={
	   //a b c d e f g h
		{1,1,1,1,1,1,0,0},
		{0,1,1,0,0,0,0,0},
		{1,1,0,1,1,0,1,0},
		{1,1,1,1,0,0,1,0},
		{0,1,1,0,0,1,1,0},
		{1,0,1,1,0,1,1,0},
		{1,0,1,1,1,1,1,0},
		{1,1,1,0,0,0,0,0},
		{1,1,1,1,1,1,1,0},
		{1,1,1,0,0,1,1,0},

};

// ============================= Deney Kartındaki displaylerin led pinleri dizisi ==========
int led7ler [8] = {GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};
// =======================================================================================

//=========================BİR 7 Segment'de bir Rakamı Gösterir ==============================================

void dispYak(int rakam)
{
	for(int i=0;i<8;i++)
	{
		HAL_GPIO_WritePin(GPIOE, led7ler[i], rakamlar[rakam][i]);

	}
}

///========================================== Tüm 4 display de Süpürme İle Sayı gösterme ================

// NOT: Deney Kartı üzerindeki displaylerin kontrol portları E4 'den E7'e kadardır

// Soldan itibaren 0 olan display'ler yanmayacak şekilde yazılmıştır

void supur(int * basamakDizi)
{
	for(int i=0;i<4;i++){
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, (i==0)? 1:0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, (i==1)? 1:0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, (i==2)? 1:0);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, (i==3)? 1:0);
		dispYak(basamakDizi[i]);
		HAL_Delay(1);
		}
/*

		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, SET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, RESET);
		dispYak(basamakDizi[0]);
		HAL_Delay(1);

		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, RESET);
		dispYak(basamakDizi[1]);
		HAL_Delay(1);

		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, SET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, RESET);
		dispYak(basamakDizi[2]);
		HAL_Delay(1);

		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, SET);
		dispYak(basamakDizi[3]);
		HAL_Delay(1);
*/

}



//================================================ Rakamları Basamaklarına ayırma onksiyonu =============
// parametre olarak basamaklarına ayrılacak sayı ve daha önce oluşturulmuş 4 elemanlı boş bir dizi

void basamakAyir(int sayi,int * dizi,int diziBoyut)

{
	for(int i=3;i>=0;i--)  // gelen diziyi başta sıfırla
	{
		dizi[i]=0;
	}
	
	
	for(int i=3;i>=0;i--)  // en değerliksiz basamak en sağda olsun
	{
		if(!sayi==0)
		{
			dizi[i]= sayi % 10;

			sayi /=10;
		}
	}


}





#endif /* INC_BIZIMKUTUPHANE_H_ */
